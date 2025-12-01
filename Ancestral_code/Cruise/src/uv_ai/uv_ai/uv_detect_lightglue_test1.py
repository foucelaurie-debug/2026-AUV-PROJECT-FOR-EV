import rclpy
from rclpy.node import Node
import subprocess
from multiprocessing import Process, Pipe
import threading

from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
import time
import cv2
from pathlib import Path
import numpy as np
import torch
import torch.backends.cudnn as cudnn
from numpy import random
import argparse
import torch
import torch.nn as nn
from ultralytics import YOLO

from sensor_msgs.msg import Image
from uv_msgs.srv import DetectRequest
from uv_msgs.msg import Yolov8
from typing import Dict, Tuple, Union, List

from uv_vision.stereocam import StereoCamera

# ============ 新增导入：LightGlue相关 ============
from lightglue import LightGlue, SuperPoint
from lightglue.utils import load_image, rbd


# 养了一只猫猫，路过的人可以摸一摸
# 　／l、
# （ﾟ､ 。 ７
# 　l、 ~ヽ
# 　じしf_, )ノ


class AiNode(Node):
    def __init__(self, name, opt, pipe_1, pipe_2):
        super().__init__(name)
        self.get_logger().info("大家好，我是%s!" % name)
        self.opt = opt
        self.bridge = CvBridge()  # 图像格式转换器

        # 是否正在处理图像
        self.processing = False
        self.front_cam_Image_data = None
        self.down_cam_Image_data = None
        self.pipe_front = pipe_1
        self.pipe_down = pipe_2
        
        # 话题发布
        # 创建话题发布detectedimg，定义其消息类型为Image，用于发布检测结果图像
        self.detectedimg_down_pub = self.create_publisher(
            Image, "detectedimg_down", 10)
        # 创建话题发布detectedimg，定义其消息类型为Image，用于发布检测结果图像
        self.detectedimg_front_pub = self.create_publisher(
            Image, "detectedimg_front", 10)
        
        # 创建话题发布detectedimg，定义其消息类型为Image，用于发布检测结果图像
        self.detectserveimg_pub = self.create_publisher(
            Image, "detect_server_img", 10)
        
        # 创建话题发布 uv_detect，定义其消息类型为Yolov8，用于发布检测结果
        self.detect_result_pub_down = self.create_publisher(
            Yolov8, 'uv_detect_down', 10)
        
        self.detect_result_pub_front = self.create_publisher(
            Yolov8, 'uv_detect_front', 10) 

        # 话题接收
        # 创建话题接收down_cam/rectified,定义其消息类型为Image
        self.create_subscription(
            Image, 'down_cam/rectified', self.down_cam_callback, 10)
        
        self.create_subscription(
            Image, 'front_cam/rectified', self.front_cam_callback, 10   
        )
        
        # 初始化服务端
        # 服务类型为DetectRequest，服务 uv_detect_srv , 回调函数为self.detectrequest_callback
        self.detect_srv = self.create_service(
            DetectRequest, 'uv_detect_srv', self.detectrequest_callback)

        # 初始化相机参数
        fsc = StereoCamera()
        dsc = StereoCamera()
        self.stereocams = {"front": fsc, "down": dsc}
        self.stereocams["front"].cal_parameters_init(opt.front_params[0])
        self.stereocams["down"].cal_parameters_init(opt.down_params[0])

        # 初始化AI模型
        self.device = torch.device("cuda:0") if torch.cuda.is_available() else torch.device("cpu")
        
        # ============ 修改：加载分割模型（从检测模型切换为分割模型）============
        self.model = YOLO(opt.weights2)  # 这里需要使用seg模型，如yolov8n-seg.pt
        self.model.to(self.device)
        self.names = self.model.names if hasattr(self.model, 'names') else self.model.module.names

        # ============ 新增：加载LightGlue模型（用于服务回调）============
        self.get_logger().info("正在加载LightGlue模型...")
        self.extractor = SuperPoint(max_num_keypoints=512).eval().to(self.device)
        self.matcher = LightGlue(features='superpoint').eval().to(self.device)
        self.get_logger().info("LightGlue模型加载完成！")


    # 下置摄像头回调函数（保持不变）
    def down_cam_callback(self, data):
        self.down_cam_Image_data = data
        self.process_image_down()

    # 前置摄像头回调函数（保持不变）
    def front_cam_callback(self, data):
        self.front_cam_Image_data = data
        self.process_image_front()
    
    # 下视图像处理（保持不变）
    def process_image_down(self):
        if self.down_cam_Image_data is not None and not self.processing:
            self.processing = True
            img0 = self.bridge.imgmsg_to_cv2(self.down_cam_Image_data, 'bgr8')
            img0 = cv2.flip(img0, -1)
            self.pipe_down.send((img0, "down"))
            self.get_logger().info("下视图像已发送到检测进程")
            results_down, img_msg_down = self.pipe_down.recv()
            self.get_logger().info(f"接收到下视检测结果！")
            self.detectedimg_down_pub.publish(img_msg_down)
            self.detect_result_pub_down.publish(results_down)
            self.processing = False

    # 前视图像处理（保持不变）
    def process_image_front(self):
        if self.front_cam_Image_data is not None and not self.processing: 
            self.processing = True      
            img1 = self.bridge.imgmsg_to_cv2(self.front_cam_Image_data, 'bgr8')
            img1 = cv2.flip(img1, -1)
            self.pipe_front.send((img1, "front"))
            self.get_logger().info("前视图像已发送到检测进程")
            results_front, img_msg_front = self.pipe_front.recv()
            self.get_logger().info(f"接收到前视检测结果！")
            self.detectedimg_front_pub.publish(img_msg_front)
            self.detect_result_pub_front.publish(results_front)
            self.processing = False
        
    # ============ 修改：检测结果预处理（增加mask提取）============
    def img_process(self, results):
        """
        处理YOLO分割结果，提取类别、置信度、中心点和mask
        
        Args:
            results: YOLOv8-seg的检测结果对象
            
        Returns:
            filtered: 列表，每个元素为(类别ID, 置信度, 中心点坐标, mask二值图)
        """
        try:
            clas = results.boxes.cls.tolist()  # 类别ID列表
            conf = results.boxes.conf.tolist()  # 置信度列表
            point = results.boxes.xyxy.tolist()  # 边界框坐标列表 [x1,y1,x2,y2]
            
            # ============ 新增：提取分割mask ============
            masks = []
            if results.masks is not None:
                # masks.data是张量 [N, H, W]，需要转为numpy数组
                for mask_tensor in results.masks.data:
                    # 将mask转为numpy数组并调整到原图尺寸
                    mask_np = mask_tensor.cpu().numpy()
                    # 如果mask尺寸不是原图尺寸，需要resize
                    if mask_np.shape != results.orig_shape[:2]:
                        mask_np = cv2.resize(mask_np, 
                                            (results.orig_shape[1], results.orig_shape[0]),
                                            interpolation=cv2.INTER_NEAREST)
                    masks.append(mask_np)
            else:
                # 如果没有mask（使用检测模型），用bbox生成伪mask
                self.get_logger().warn("未检测到分割mask，将使用bbox生成伪mask")
                for bbox in point:
                    mask_np = np.zeros(results.orig_shape[:2], dtype=np.uint8)
                    x1, y1, x2, y2 = map(int, bbox)
                    mask_np[y1:y2, x1:x2] = 1
                    masks.append(mask_np)
            
            # 组合数据
            combined = list(zip(clas, conf, point, masks))
            
            # ============ 修改：过滤条件保持不变，但增加mask信息 ============
            # 过滤掉置信度低于0.65的检测结果，并将结果格式化为 (clas, conf, center, mask)
            filtered = []
            for item in combined:
                if item[1] >= 0.65:  # 置信度阈值
                    # 计算中心点
                    center_x = (item[2][0] + item[2][2]) / 2
                    center_y = (item[2][1] + item[2][3]) / 2
                    center = (center_x, center_y)
                    # 添加：(类别, 置信度, 中心点, mask)
                    filtered.append((item[0], item[1], center, item[3]))

            return filtered
            
        except Exception as e:
            self.get_logger().error(f"图像处理错误: {e}")
            return []

    # ============ 修改：服务回调函数（集成LightGlue多点匹配）============
    def detectrequest_callback(self, request, response):
        """
        处理检测服务请求，使用LightGlue进行特征匹配和多点三角测量
        
        Args:
            request: 包含图像和目标名称的请求
            response: 返回3D坐标和状态
        """
        img0 = self.bridge.imgmsg_to_cv2(request.imagein, 'bgr8')
        img0 = cv2.flip(img0, -1)
        askedtarget = request.target  # 请求的目标名称
        response.s = 0  # 初始化状态为未找到
        
        _, width, _ = img0.shape
        half_width = width // 2

        # 把图像分为左右两部分
        img_l = img0[:, :half_width]
        img_r = img0[:, half_width:]

        t0 = time.time()
        
        # ============ YOLO分割检测 ============
        results_l = self.model.predict(source=img_l)[0]
        filtered_l = self.img_process(results_l)
        self.get_logger().info(f"server:左目完成图像预测,检测到 {len(filtered_l)} 个目标")

        results_r = self.model.predict(source=img_r)[0]
        filtered_r = self.img_process(results_r)
        self.get_logger().info(f"server:右目完成图像预测,检测到 {len(filtered_r)} 个目标")
        
        # ============ 匹配左右目标（基于类别）============
        targets_dict: Dict[Union[str, int], Tuple[float, Tuple[float], Tuple[float], np.ndarray, np.ndarray]] = {}
        
        # 格式：{类别ID: (置信度, 左中心, 右中心, 左mask, 右mask)}
        for clas, conf, center_l, mask_l in filtered_l:
            targets_dict[clas] = (conf, center_l, None, mask_l, None)
        
        for clas, conf, center_r, mask_r in filtered_r:
            if clas in targets_dict:
                targets_dict[clas] = (targets_dict[clas][0], 
                                     targets_dict[clas][1], 
                                     center_r, 
                                     targets_dict[clas][3], 
                                     mask_r)

        # ============ 遍历字典，使用LightGlue计算目标物的三维坐标 ============
        for clas in targets_dict:
            if self.names[int(clas)] == askedtarget:
                left_center = targets_dict[clas][1]
                right_center = targets_dict[clas][2]
                left_mask = targets_dict[clas][3]
                right_mask = targets_dict[clas][4]

                # 检查是否左右都检测到
                if left_center is not None and right_center is not None and \
                   left_mask is not None and right_mask is not None:
                    
                    # ============ 使用LightGlue进行多点匹配 ============
                    result_3d = self.multipoint_triangulation_with_lightglue(
                        img_l, img_r, 
                        left_mask, right_mask,
                        self.stereocams[request.stero].P1, 
                        self.stereocams[request.stero].P2
                    )
                    
                    if result_3d is not None:
                        x, y, z = result_3d
                        response.s = 1
                        response.x, response.y, response.z = x, y, z
                        self.get_logger().info(f"目标 {askedtarget} 3D坐标: ({x:.3f}, {y:.3f}, {z:.3f})")
                        break  # 找到目标后退出循环

        # ============ 发布可视化图像（保持不变）============
        img_l_plot = results_l.plot()
        img_r_plot = results_r.plot()
        img0_vis = np.hstack((img_l_plot, img_r_plot))
        img0_vis = np.array(img0_vis)
        data = self.bridge.cv2_to_imgmsg(img0_vis, encoding="bgr8")
        self.detectserveimg_pub.publish(data)

        if response.s == 1:
            self.get_logger().info("已检测到目标，用时: %.3fs" % (time.time() - t0))
        else:
            self.get_logger().info("未检测到目标，用时: %.3fs" % (time.time() - t0))

        return response

    # ============ 新增：使用LightGlue进行多点三角测量的核心函数 ============
    def multipoint_triangulation_with_lightglue(self, img_l, img_r, mask_l, mask_r, P1, P2):
        """
        使用LightGlue在mask区域内进行特征匹配，并通过多点三角测量计算鲁棒的3D坐标
        
        Args:
            img_l: 左目图像 (numpy array, BGR)
            img_r: 右目图像 (numpy array, BGR)
            mask_l: 左目mask (numpy array, 0-1二值图)
            mask_r: 右目mask (numpy array, 0-1二值图)
            P1: 左相机投影矩阵
            P2: 右相机投影矩阵
            
        Returns:
            (x, y, z): 3D坐标，如果失败返回None
        """
        try:
            # ============ Step 1: 预处理mask（腐蚀操作去除边缘噪声）============
            kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
            mask_l_eroded = cv2.erode(mask_l.astype(np.uint8), kernel, iterations=2)
            mask_r_eroded = cv2.erode(mask_r.astype(np.uint8), kernel, iterations=2)
            
            # ============ Step 2: 转换图像格式为灰度图（LightGlue需要）============
            gray_l = cv2.cvtColor(img_l, cv2.COLOR_BGR2GRAY)
            gray_r = cv2.cvtColor(img_r, cv2.COLOR_BGR2GRAY)
            
            # 转换为torch张量 [1, 1, H, W]，归一化到[0,1]
            image_l = torch.from_numpy(gray_l).float()[None, None] / 255.0
            image_r = torch.from_numpy(gray_r).float()[None, None] / 255.0
            image_l = image_l.to(self.device)
            image_r = image_r.to(self.device)
            
            # ============ Step 3: 使用SuperPoint提取特征点 ============
            with torch.no_grad():
                feats_l = self.extractor.extract(image_l)
                feats_r = self.extractor.extract(image_r)
            
            # ============ Step 4: 过滤特征点（只保留mask内的点）============
            # feats包含keypoints [N, 2]和descriptors [N, D]
            kpts_l = feats_l['keypoints'][0].cpu().numpy()  # [N, 2]
            kpts_r = feats_r['keypoints'][0].cpu().numpy()
            
            # 检查哪些特征点在mask内
            valid_l = []
            for i, (x, y) in enumerate(kpts_l):
                if 0 <= int(y) < mask_l_eroded.shape[0] and 0 <= int(x) < mask_l_eroded.shape[1]:
                    if mask_l_eroded[int(y), int(x)] > 0:
                        valid_l.append(i)
            
            valid_r = []
            for i, (x, y) in enumerate(kpts_r):
                if 0 <= int(y) < mask_r_eroded.shape[0] and 0 <= int(x) < mask_r_eroded.shape[1]:
                    if mask_r_eroded[int(y), int(x)] > 0:
                        valid_r.append(i)
            
            if len(valid_l) < 5 or len(valid_r) < 5:
                self.get_logger().warn(f"mask内特征点不足: 左{len(valid_l)}个，右{len(valid_r)}个")
                return None
            
            # 过滤特征
            feats_l['keypoints'] = feats_l['keypoints'][:, valid_l, :]
            feats_l['descriptors'] = feats_l['descriptors'][:, valid_l, :]
            feats_r['keypoints'] = feats_r['keypoints'][:, valid_r, :]
            feats_r['descriptors'] = feats_r['descriptors'][:, valid_r, :]
            
            # ============ Step 5: 使用LightGlue进行匹配 ============
            with torch.no_grad():
                matches01 = self.matcher({'image0': feats_l, 'image1': feats_r})
            
            # 提取匹配结果
            matches = matches01['matches'][0].cpu().numpy()  # [M, 2]，每行是(idx_l, idx_r)
            valid_matches = matches[matches[:, 0] != -1]  # 过滤无效匹配
            
            if len(valid_matches) < 5:
                self.get_logger().warn(f"有效匹配点不足: {len(valid_matches)}个")
                return None
            
            self.get_logger().info(f"LightGlue匹配成功: {len(valid_matches)}个点对")
            
            # ============ Step 6: 提取匹配点坐标 ============
            kpts_l_matched = feats_l['keypoints'][0][valid_matches[:, 0]].cpu().numpy()
            kpts_r_matched = feats_r['keypoints'][0][valid_matches[:, 1]].cpu().numpy()
            
            # ============ Step 7: 多点三角测量 + RANSAC ============
            points_3d = []
            for pt_l, pt_r in zip(kpts_l_matched, kpts_r_matched):
                # 纵坐标对齐（使用平均值）
                avg_y = (pt_l[1] + pt_r[1]) / 2
                pt_l_aligned = np.array([pt_l[0], avg_y], dtype=np.float32).reshape(2, 1)
                pt_r_aligned = np.array([pt_r[0], avg_y], dtype=np.float32).reshape(2, 1)
                
                # 三角测量
                pt_4d = cv2.triangulatePoints(P1, P2, pt_l_aligned, pt_r_aligned)
                pt_3d = pt_4d[:3] / pt_4d[3]  # 归一化为笛卡尔坐标
                points_3d.append(pt_3d.flatten())
            
            points_3d = np.array(points_3d)  # [M, 3]
            
            # ============ Step 8: RANSAC剔除外点（基于深度一致性）============
            z_values = points_3d[:, 2]
            z_median = np.median(z_values)
            z_std = np.std(z_values)
            
            # 内点判定：距离中位数不超过2倍标准差
            inliers = np.abs(z_values - z_median) < 2.0 * z_std
            
            if np.sum(inliers) < 3:
                self.get_logger().warn(f"内点数量不足: {np.sum(inliers)}个")
                return None
            
            # ============ Step 9: 计算加权平均（内点）============
            inlier_points = points_3d[inliers]
            final_point = np.mean(inlier_points, axis=0)
            
            # 转换坐标系（与原代码保持一致）
            x = -float(final_point[0])
            y = -float(final_point[1])
            z = float(final_point[2])
            
            self.get_logger().info(f"多点测量成功: 使用{np.sum(inliers)}/{len(points_3d)}个内点")
            
            return (x, y, z)
            
        except Exception as e:
            self.get_logger().error(f"LightGlue多点三角测量失败: {e}")
            import traceback
            traceback.print_exc()
            return None


# ============ 修改：检测子进程（集成LightGlue）============
def detect_process(pipe, opt):
    """
    独立的检测进程，使用YOLOv8-seg + LightGlue进行目标检测和深度估计
    
    Args:
        pipe: 与主进程通信的管道
        opt: 命令行参数
    """
    # 初始化相机参数
    fsc = StereoCamera()
    dsc = StereoCamera()
    stereocams = {"front": fsc, "down": dsc}
    stereocams["front"].cal_parameters_init(opt.front_params[0])
    stereocams["down"].cal_parameters_init(opt.down_params[0])
    
    # ============ 修改：加载分割模型 ============
    model1 = YOLO(opt.weights)  # 需要使用seg模型
    device1 = torch.device("cuda:0") if torch.cuda.is_available() else torch.device("cpu")
    model1.to(device1)
    
    # ============ 新增：加载LightGlue模型 ============
    print("detect_process: 正在加载LightGlue模型...")
    extractor = SuperPoint(max_num_keypoints=512).eval().to(device1)
    matcher = LightGlue(features='superpoint').eval().to(device1)
    print("detect_process: LightGlue模型加载完成！")

    while True:
        img0, cam_type = pipe.recv()
        tar = Yolov8()

        try:
            print("detect_process: 开始处理图像")
            _, width, _ = img0.shape
            half_width = width // 2
            img_l = img0[:, :half_width]
            img_r = img0[:, half_width:]
            
            # ============ YOLO分割检测 ============
            print("detect_process: 开始YOLO分割推理...")
            results_l = model1.predict(source=img_l)[0]
            results_r = model1.predict(source=img_r)[0]
            
            # ============ 提取检测结果（包含mask）============
            clas_l = results_l.boxes.cls.tolist()
            conf_l = results_l.boxes.conf.tolist()
            point_l = results_l.boxes.xyxy.tolist()
            
            # 提取mask
            masks_l = []
            if results_l.masks is not None:
                for mask_tensor in results_l.masks.data:
                    mask_np = mask_tensor.cpu().numpy()
                    if mask_np.shape != results_l.orig_shape[:2]:
                        mask_np = cv2.resize(mask_np, 
                                           (results_l.orig_shape[1], results_l.orig_shape[0]),
                                           interpolation=cv2.INTER_NEAREST)
                    masks_l.append(mask_np)
            else:
                print("detect_process: 警告 - 未检测到mask，使用bbox生成")
                for bbox in point_l:
                    mask_np = np.zeros(results_l.orig_shape[:2], dtype=np.uint8)
                    x1, y1, x2, y2 = map(int, bbox)
                    mask_np[y1:y2, x1:x2] = 1
                    masks_l.append(mask_np)
            
            combined_l = list(zip(clas_l, conf_l, point_l, masks_l))
            filtered_l = []
            for item in combined_l:
                if item[1] >= 0.50:  # 置信度阈值
                    center_x = (item[2][0] + item[2][2]) / 2
                    center_y = (item[2][1] + item[2][3]) / 2
                    filtered_l.append((item[0], item[1], (center_x, center_y), item[3]))
            
            print(f"process: 左目完成图像预测，检测到 {len(filtered_l)} 个目标")

            # 右目同样处理
            clas_r = results_r.boxes.cls.tolist()
            conf_r = results_r.boxes.conf.tolist()
            point_r = results_r.boxes.xyxy.tolist()
            
            masks_r = []
            if results_r.masks is not None:
                for mask_tensor in results_r.masks.data:
                    mask_np = mask_tensor.cpu().numpy()
                    if mask_np.shape != results_r.orig_shape[:2]:
                        mask_np = cv2.resize(mask_np, 
                                           (results_r.orig_shape[1], results_r.orig_shape[0]),
                                           interpolation=cv2.INTER_NEAREST)
                    masks_r.append(mask_np)
            else:
                for bbox in point_r:
                    mask_np = np.zeros(results_r.orig_shape[:2], dtype=np.uint8)
                    x1, y1, x2, y2 = map(int, bbox)
                    mask_np[y1:y2, x1:x2] = 1
                    masks_r.append(mask_np)
            
            combined_r = list(zip(clas_r, conf_r, point_r, masks_r))
            filtered_r = []
            for item in combined_r:
                if item[1] >= 0.50:
                    center_x = (item[2][0] + item[2][2]) / 2
                    center_y = (item[2][1] + item[2][3]) / 2
                    filtered_r.append((item[0], item[1], (center_x, center_y), item[3]))
            
            print(f"process: 右目完成图像预测，检测到 {len(filtered_r)} 个目标")
            
            # ============ 匹配左右目标 ============
            targets_dict: Dict[Union[str, int], Tuple[float, Tuple[float], Tuple[float], np.ndarray, np.ndarray]] = {}
            
            for clas, conf, center_l, mask_l in filtered_l:
                targets_dict[clas] = (conf, center_l, None, mask_l, None)
            
            for clas, conf, center_r, mask_r in filtered_r:
                if clas in targets_dict:
                    targets_dict[clas] = (targets_dict[clas][0], 
                                         targets_dict[clas][1], 
                                         center_r, 
                                         targets_dict[clas][3], 
                                         mask_r)
            
            # 初始化状态
            tar.state = [0.0 for _ in range(13)]

            # ============ 遍历每个目标，使用LightGlue计算深度 ============
            for clas in targets_dict: 
                # 统计检测数量
                if targets_dict[clas][1] is not None or targets_dict[clas][2] is not None:
                    tar.state[int(clas)] += 1

                left_center = targets_dict[clas][1]
                right_center = targets_dict[clas][2]
                left_mask = targets_dict[clas][3]
                right_mask = targets_dict[clas][4]

                # 检查左右是否都检测到
                if left_center is not None and right_center is not None and \
                   left_mask is not None and right_mask is not None:
                    
                    # ============ 调用多点三角测量函数 ============
                    result_3d = multipoint_triangulation_lightglue(
                        img_l, img_r,
                        left_mask, right_mask,
                        stereocams[cam_type].P1,
                        stereocams[cam_type].P2,
                        extractor, matcher, device1
                    )
                    
                    if result_3d is not None:
                        x, y, z = result_3d
                        # 填充消息
                        tar.targets[int(clas)].tpos_inpic.x = round(left_center[0])
                        tar.targets[int(clas)].tpos_inpic.y = round(left_center[1])
                        tar.targets[int(clas)].tpos_inworld.x = x
                        tar.targets[int(clas)].tpos_inworld.y = y
                        tar.targets[int(clas)].tpos_inworld.z = z
                        print(f"process: 类别{int(clas)} 3D坐标: ({x:.3f}, {y:.3f}, {z:.3f})")
                    else:
                        print(f"process: 类别{int(clas)} 多点测量失败，跳过")
            
            # ============ 可视化结果 ============
            img_l_vis = results_l.plot()
            img_r_vis = results_r.plot()
            img0_vis = np.hstack((img_l_vis, img_r_vis))  # 图像二合一
            img0_vis = np.array(img0_vis)    
            img_msg = CvBridge().cv2_to_imgmsg(img0_vis, encoding="bgr8")

            pipe.send((tar, img_msg))

            print("detect_process: 图像处理完成")
            
        except CvBridgeError as e:
            print(f"detect_process: 图像转换错误: {e}")
        except Exception as e:
            print(f"detect_process: 目标检测错误: {e}")
            import traceback
            traceback.print_exc()


# ============ 新增：子进程使用的多点三角测量函数 ============
def multipoint_triangulation_lightglue(img_l, img_r, mask_l, mask_r, P1, P2, extractor, matcher, device):
    """
    使用LightGlue进行多点三角测量（子进程版本）
    
    参数和返回值与AiNode中的方法相同
    """
    try:
        # ============ mask预处理 ============
        kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
        mask_l_eroded = cv2.erode(mask_l.astype(np.uint8), kernel, iterations=2)
        mask_r_eroded = cv2.erode(mask_r.astype(np.uint8), kernel, iterations=2)
        
        # ============ 转换为灰度图 ============
        gray_l = cv2.cvtColor(img_l, cv2.COLOR_BGR2GRAY)
        gray_r = cv2.cvtColor(img_r, cv2.COLOR_BGR2GRAY)
        
        # 转为torch张量
        image_l = torch.from_numpy(gray_l).float()[None, None] / 255.0
        image_r = torch.from_numpy(gray_r).float()[None, None] / 255.0
        image_l = image_l.to(device)
        image_r = image_r.to(device)
        
        # ============ 提取特征 ============
        with torch.no_grad():
            feats_l = extractor.extract(image_l)
            feats_r = extractor.extract(image_r)
        
        # ============ 过滤mask内的特征点 ============
        kpts_l = feats_l['keypoints'][0].cpu().numpy()
        kpts_r = feats_r['keypoints'][0].cpu().numpy()
        
        valid_l = []
        for i, (x, y) in enumerate(kpts_l):
            if 0 <= int(y) < mask_l_eroded.shape[0] and 0 <= int(x) < mask_l_eroded.shape[1]:
                if mask_l_eroded[int(y), int(x)] > 0:
                    valid_l.append(i)
        
        valid_r = []
        for i, (x, y) in enumerate(kpts_r):
            if 0 <= int(y) < mask_r_eroded.shape[0] and 0 <= int(x) < mask_r_eroded.shape[1]:
                if mask_r_eroded[int(y), int(x)] > 0:
                    valid_r.append(i)
        
        if len(valid_l) < 5 or len(valid_r) < 5:
            print(f"mask内特征点不足: 左{len(valid_l)}个，右{len(valid_r)}个")
            return None
        
        # 过滤特征
        feats_l['keypoints'] = feats_l['keypoints'][:, valid_l, :]
        feats_l['descriptors'] = feats_l['descriptors'][:, valid_l, :]
        feats_r['keypoints'] = feats_r['keypoints'][:, valid_r, :]
        feats_r['descriptors'] = feats_r['descriptors'][:, valid_r, :]
        
        # ============ LightGlue匹配 ============
        with torch.no_grad():
            matches01 = matcher({'image0': feats_l, 'image1': feats_r})
        
        matches = matches01['matches'][0].cpu().numpy()
        valid_matches = matches[matches[:, 0] != -1]
        
        if len(valid_matches) < 5:
            print(f"有效匹配点不足: {len(valid_matches)}个")
            return None
        
        print(f"LightGlue匹配成功: {len(valid_matches)}个点对")
        
        # ============ 提取匹配点 ============
        kpts_l_matched = feats_l['keypoints'][0][valid_matches[:, 0]].cpu().numpy()
        kpts_r_matched = feats_r['keypoints'][0][valid_matches[:, 1]].cpu().numpy()
        
        # ============ 多点三角测量 ============
        points_3d = []
        for pt_l, pt_r in zip(kpts_l_matched, kpts_r_matched):
            # 纵坐标对齐
            avg_y = (pt_l[1] + pt_r[1]) / 2
            pt_l_aligned = np.array([pt_l[0], avg_y], dtype=np.float32).reshape(2, 1)
            pt_r_aligned = np.array([pt_r[0], avg_y], dtype=np.float32).reshape(2, 1)
            
            # 三角测量
            pt_4d = cv2.triangulatePoints(P1, P2, pt_l_aligned, pt_r_aligned)
            pt_3d = pt_4d[:3] / pt_4d[3]
            points_3d.append(pt_3d.flatten())
        
        points_3d = np.array(points_3d)
        
        # ============ RANSAC剔除外点 ============
        z_values = points_3d[:, 2]
        z_median = np.median(z_values)
        z_std = np.std(z_values)
        inliers = np.abs(z_values - z_median) < 2.0 * z_std
        
        if np.sum(inliers) < 3:
            print(f"内点数量不足: {np.sum(inliers)}个")
            return None
        
        # ============ 加权平均 ============
        inlier_points = points_3d[inliers]
        final_point = np.mean(inlier_points, axis=0)
        
        # 坐标转换
        x = -float(final_point[0])
        y = -float(final_point[1])
        z = float(final_point[2])
        
        print(f"多点测量成功: 使用{np.sum(inliers)}/{len(points_3d)}个内点")
        
        return (x, y, z)
        
    except Exception as e:
        print(f"LightGlue多点三角测量失败: {e}")
        import traceback
        traceback.print_exc()
        return None


# ============ main函数（保持不变）============
import rclpy
from rclpy.node import Node
import argparse
from multiprocessing import Pipe, Process
import sys

def main(args=None):
    # 过滤ROS 2自动添加的参数
    ros_args = rclpy.utilities.remove_ros_args(sys.argv)
    
    # 解析自定义参数
    parser = argparse.ArgumentParser()
    parser.add_argument('--weights', nargs='+', type=str,
                        default='/home/nvidia/Workspace/Cruise/datas/AUV2025V1.pt', 
                        help='子进程检测模型路径（建议使用seg模型）')
    parser.add_argument('--weights2', nargs='+', type=str,
                        default='/home/nvidia/Workspace/Cruise/datas/AUV2025V1.pt', 
                        help='服务检测模型路径（建议使用seg模型）')
    parser.add_argument('--show-img', type=bool,
                        default=True, help='是否展示图像')
    parser.add_argument('--front-params', nargs='+', type=str,
                        default=['/home/nvidia/Workspace/Cruise/datas/front.npz'], 
                        help='前置摄像头参数存储路径')
    parser.add_argument('--down-params', nargs='+', type=str,
                        default=['/home/nvidia/Workspace/Cruise/datas/down.npz'], 
                        help='下置摄像头参数存储路径')

    opt = parser.parse_args(ros_args[1:])

    # 初始化ROS 2节点
    rclpy.init(args=args)

    # 创建双进程通信管道
    parent_conn_1, child_conn_1 = Pipe()
    parent_conn_2, child_conn_2 = Pipe()
    
    # 启动检测子进程
    p_1 = Process(target=detect_process, args=(child_conn_1, opt))
    p_2 = Process(target=detect_process, args=(child_conn_2, opt))
    p_1.start()
    p_2.start()

    # 启动主节点
    node = AiNode("uv_detect_demo", opt, parent_conn_1, parent_conn_2)
    rclpy.spin(node)
    rclpy.shutdown()

    # 进程清理
    p_1.join()
    p_2.join()