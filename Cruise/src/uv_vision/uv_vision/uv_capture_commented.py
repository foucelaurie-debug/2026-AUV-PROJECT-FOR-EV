# 导入ROS2的Python客户端库，用于创建ROS节点和通信
import rclpy
# 从rclpy.node导入Node类，这是所有ROS2节点的基础类
from rclpy.node import Node
# 导入OpenCV库，用于图像处理和计算机视觉操作
import cv2
# 导入CvBridge和相关异常，用于ROS图像消息和OpenCV图像格式之间的转换
from cv_bridge import CvBridge, CvBridgeError
# 导入NumPy库，用于数值计算和数组操作
import numpy as np
# 导入时间模块，虽然在本代码中未直接使用，但可能用于时间相关操作
import time
# 导入ROS2的Image消息类型，用于发布图像数据
from sensor_msgs.msg import Image
# 导入argparse模块，用于解析命令行参数
import argparse
# 导入datetime模块，用于生成时间戳
from datetime import datetime
# 导入自定义的立体相机模块
from uv_vision import stereocam
# 导入操作系统接口模块，用于文件路径操作
import os
# 导入系统模块，用于访问命令行参数
import sys
# 导入ROS2的参数过滤工具，用于移除ROS自动添加的命令行参数
from rclpy.utilities import remove_ros_args

# 全局计数器，用于控制下视图像保存频率（每2帧保存一次）
cnt_down = 0
# 全局计数器，用于控制前视图像保存频率（每2帧保存一次）
cnt_front = 0

def image_publish(frame, img_bridge, image_pub):
    """
    图像发布函数：将OpenCV图像转换为ROS消息并发布
    
    参数:
    frame: 要发布的图像帧（OpenCV格式）
    img_bridge: CvBridge对象，用于格式转换
    image_pub: ROS发布器对象
    """
    # 将输入图像转换为NumPy数组格式（确保数据类型正确）
    frame = np.array(frame)
    # 使用CvBridge将OpenCV图像（BGR8编码）转换为ROS Image消息格式
    data = img_bridge.cv2_to_imgmsg(frame, encoding="bgr8")
    # 通过指定的发布器将转换后的图像消息发布到ROS话题
    image_pub.publish(data)
    # 注释：如果提供了保存路径，则保存图像（原代码中的注释，但未实现）

class CaptureNode(Node):
    """
    图像采集节点类：继承自ROS2 Node，负责从立体摄像头采集图像并发布
    """
    
    def __init__(self, name, opt):
        """
        初始化图像采集节点
        
        参数:
        name: 节点名称
        opt: 包含配置选项的对象（摄像头设备路径、参数文件路径等）
        """
        # 调用父类Node的初始化方法，设置节点名称
        super().__init__(name)
        # 创建CvBridge对象，用于OpenCV和ROS图像格式转换
        self.bridge = CvBridge()

        # 在ROS日志中输出节点启动信息
        self.get_logger().info("大家好，我是%s!" % name)

        # 检查是否启用了前视摄像头（"none"表示禁用）
        if opt.front_cam[0] != "none":
            # 创建前视摄像头原始完整图像发布器，话题名为"front_cam/raw"
            self.frontcam_raw_pub = self.create_publisher(
                Image, "front_cam/raw", 10)
            # 创建前视摄像头原始左目图像发布器，话题名为"front_cam/raw/left"
            self.frontcam_rawleft_pub = self.create_publisher(
                Image, "front_cam/raw/left", 10)
            # 创建前视摄像头原始右目图像发布器，话题名为"front_cam/raw/right"
            self.frontcam_rawright_pub = self.create_publisher(
                Image, "front_cam/raw/right", 10)
            
            # 检查是否提供了前视摄像头的标定参数文件
            if opt.front_params[0] != "none":
                # 创建前视摄像头校正后完整图像发布器，话题名为"front_cam/rectified"
                self.frontcam_rectified_pub = self.create_publisher(
                    Image, "front_cam/rectified", 10)
                # 创建前视摄像头校正后左目图像发布器，话题名为"front_cam/rectified/left"
                self.frontcam_rectifiedleft_pub = self.create_publisher(
                    Image, "front_cam/rectified/left", 10)
                # 创建前视摄像头校正后右目图像发布器，话题名为"front_cam/rectified/right"
                self.frontcam_rectifiedright_pub = self.create_publisher(
                    Image, "front_cam/rectified/right", 10)

            # 创建前视摄像头定时器，每0.01秒触发一次（100Hz频率）
            self.front_cam_timer = self.create_timer(
                0.01, self.front_cam_timer_callback)

            # 创建前视立体相机对象
            self.front_sc = stereocam.StereoCamera()
            # 配置前视摄像头的设备参数（设备路径、分辨率、帧率等）
            self.front_sc.device_parameter_config(device=opt.front_cam[0])
            # 如果提供了标定参数文件，则加载相机标定参数
            if opt.front_params[0] != "none":
                # 从.npz文件中加载相机内外参数、畸变系数等标定数据
                self.front_sc.cal_parameters_init(opt.front_params[0])
                # 初始化立体校正映射，用于后续的图像校正处理
                self.front_sc.rectification_init()

        # 检查是否启用了下视摄像头（"none"表示禁用）
        if opt.down_cam[0] != "none":
            # 创建下视摄像头原始完整图像发布器，话题名为"down_cam/raw"
            self.backcam_raw_pub = self.create_publisher(
                Image, "down_cam/raw", 10)
            # 创建下视摄像头原始左目图像发布器，话题名为"down_cam/raw/left"
            self.backcam_rawleft_pub = self.create_publisher(
                Image, "down_cam/raw/left", 10)
            # 创建下视摄像头原始右目图像发布器，话题名为"down_cam/raw/right"
            self.backcam_rawright_pub = self.create_publisher(
                Image, "down_cam/raw/right", 10)
            
            # 检查是否提供了下视摄像头的标定参数文件
            if opt.down_params[0] != "none":
                # 创建下视摄像头校正后完整图像发布器，话题名为"down_cam/rectified"
                self.backcam_rectified_pub = self.create_publisher(
                    Image, "down_cam/rectified", 10)
                # 创建下视摄像头校正后左目图像发布器，话题名为"down_cam/rectified/left"
                self.backcam_rectifiedleft_pub = self.create_publisher(
                    Image, "down_cam/rectified/left", 10)
                # 创建下视摄像头校正后右目图像发布器，话题名为"down_cam/rectified/right"
                self.backcam_rectifiedright_pub = self.create_publisher(
                    Image, "down_cam/rectified/right", 10)
            
            # 创建下视摄像头定时器，每0.01秒触发一次（100Hz频率）
            self.down_cam_timer = self.create_timer(
                0.01, self.back_cam_timer_callback)

            # 创建下视立体相机对象
            self.down_sc = stereocam.StereoCamera()
            # 配置下视摄像头的设备参数（设备路径、分辨率、帧率等）
            self.down_sc.device_parameter_config(device=opt.down_cam[0])
            # 如果提供了标定参数文件，则加载相机标定参数
            if opt.down_params[0] != "none":
                # 从.npz文件中加载相机内外参数、畸变系数等标定数据
                self.down_sc.cal_parameters_init(opt.down_params[0])
                # 初始化立体校正映射，用于后续的图像校正处理
                self.down_sc.rectification_init()

        # 将配置选项对象保存为实例变量，供其他方法使用
        self.opt = opt   

    def front_cam_timer_callback(self):
        """
        前视摄像头定时器回调函数：每0.01秒被调用一次，负责采集和处理前视图像
        """
        # 从立体摄像头捕获一帧图像，s表示成功状态，f表示图像帧
        s, f = self.front_sc.capture()

        # 检查图像捕获是否成功
        if s:
            # 将捕获的立体图像分割为左目和右目图像
            img_l, img_r = self.front_sc.get_halfimg(f)
            
            # 发布前视摄像头的原始完整图像
            image_publish(f, self.bridge, self.frontcam_raw_pub)
            # 发布前视摄像头的原始左目图像
            image_publish(img_l, self.bridge, self.frontcam_rawleft_pub)
            # 发布前视摄像头的原始右目图像
            image_publish(img_r, self.bridge, self.frontcam_rawright_pub)
            
            # 检查是否提供了下视摄像头的标定参数（这里应该是前视参数，可能是代码错误）
            if self.opt.down_params[0] != "none":
                # 对左右目图像进行立体校正，消除镜头畸变和立体视差
                r_l, r_r = self.front_sc.rectifyImage(img_l, img_r)
                # 将校正后的左右目图像合并为完整的立体图像
                full = self.front_sc.get_fullimg(r_l, r_r)
                # 声明使用全局计数器变量cnt_front
                global cnt_front
                # 增加前视图像计数器
                cnt_front = cnt_front + 1
                # 检查是否达到保存条件（每2帧保存一次）
                if cnt_front == 2:
                    # 获取当前时间
                    now = datetime.now()
                    # 生成带微秒精度的时间戳字符串
                    timestamp = now.strftime("%Y%m%d_%H%M%S%f")
                    # 构建图像保存的完整路径
                    filename = os.path.join("/home/nvidia/Workspace/Cruise/img/front", f"{timestamp}.jpg")
                    # 将校正后的完整图像保存为JPG文件
                    cv2.imwrite(filename, full)
                    # 重置计数器为0
                    cnt_front = 0
                # 发布前视摄像头的校正后完整图像
                image_publish(full, self.bridge, self.frontcam_rectified_pub)
                # 发布前视摄像头的校正后左目图像
                image_publish(r_l, self.bridge, self.frontcam_rectifiedleft_pub)
                # 发布前视摄像头的校正后右目图像
                image_publish(r_r, self.bridge, self.frontcam_rectifiedright_pub)

            # 在ROS日志中输出前视图像发布成功的消息
            self.get_logger().info('发布了前视图像')
        else:
            # 如果图像捕获失败，在ROS日志中输出错误消息
            self.get_logger().info('图像获取失败')

    def back_cam_timer_callback(self):
        """
        下视摄像头定时器回调函数：每0.01秒被调用一次，负责采集和处理下视图像
        """
        # 从立体摄像头捕获一帧图像，s表示成功状态，f表示图像帧
        s, f = self.down_sc.capture()

        # 检查图像捕获是否成功
        if s:
            # 将捕获的立体图像分割为左目和右目图像
            img_l, img_r = self.down_sc.get_halfimg(f)
            
            # 发布下视摄像头的原始完整图像
            image_publish(f, self.bridge, self.backcam_raw_pub)
            # 发布下视摄像头的原始左目图像
            image_publish(img_l, self.bridge, self.backcam_rawleft_pub)
            # 发布下视摄像头的原始右目图像
            image_publish(img_r, self.bridge, self.backcam_rawright_pub)
            
            # 检查是否提供了下视摄像头的标定参数
            if self.opt.down_params[0] != "none":
                # 对左右目图像进行立体校正，消除镜头畸变和立体视差
                r_l, r_r = self.down_sc.rectifyImage(img_l, img_r)
                # 将校正后的左右目图像合并为完整的立体图像
                full = self.down_sc.get_fullimg(r_l, r_r)
                # 声明使用全局计数器变量cnt_down
                global cnt_down
                # 增加下视图像计数器
                cnt_down = cnt_down + 1
                # 检查是否达到保存条件（每2帧保存一次）
                if cnt_down == 2:
                    # 获取当前时间
                    now = datetime.now()
                    # 生成带微秒精度的时间戳字符串
                    timestamp = now.strftime("%Y%m%d_%H%M%S%f")
                    # 构建图像保存的完整路径
                    filename = os.path.join("/home/nvidia/Workspace/Cruise/img/down", f"{timestamp}.jpg")
                    # 将校正后的完整图像保存为JPG文件
                    cv2.imwrite(filename, full)
                    # 重置计数器为0
                    cnt_down = 0
                # 发布下视摄像头的校正后完整图像
                image_publish(full, self.bridge, self.backcam_rectified_pub)
                # 发布下视摄像头的校正后左目图像
                image_publish(r_l, self.bridge, self.backcam_rectifiedleft_pub)
                # 发布下视摄像头的校正后右目图像
                image_publish(r_r, self.bridge, self.backcam_rectifiedright_pub)

            # 在ROS日志中输出下视图像发布成功的消息
            self.get_logger().info('发布了下视图像')
        else:
            # 如果图像捕获失败，在ROS日志中输出错误消息
            self.get_logger().info('图像获取失败')

def main(args=None):
    """
    主函数：程序的入口点，负责参数解析、节点初始化和运行
    """
    # 步骤1：过滤ROS 2自动添加的命令行参数（关键步骤）
    # 移除--ros-args等ROS相关参数，只保留用户自定义的参数
    ros_args = remove_ros_args(sys.argv)
    
    # 步骤2：解析自定义命令行参数（使用过滤后的参数列表）
    # 创建参数解析器对象
    parser = argparse.ArgumentParser()
    # 添加前视摄像头设备路径参数，默认为/dev/video0
    parser.add_argument('--front-cam', nargs='+', type=str,
                        default=['/dev/video0'], help='前置摄像头')
    # 添加下视摄像头设备路径参数，默认为/dev/video2
    parser.add_argument('--down-cam', nargs='+', type=str,
                        default=['/dev/video2'], help='下置摄像头')
    # 添加前视摄像头标定参数文件路径，默认为front.npz
    parser.add_argument('--front-params', nargs='+', type=str,
                        default=['/home/nvidia/Workspace/Cruise/datas/front.npz'], help='前置摄像头参数存储路径')
    # 添加下视摄像头标定参数文件路径，默认为down.npz
    parser.add_argument('--down-params', nargs='+', type=str,
                        default=['/home/nvidia/Workspace/Cruise/datas/down.npz'], help='下置摄像头参数存储路径')
    
    # 解析命令行参数，跳过脚本文件名（ros_args[0]），只处理自定义参数
    opt = parser.parse_args(ros_args[1:])

    # 步骤3：检查摄像头配置并初始化ROS2节点
    # 检查是否所有摄像头都被禁用
    if opt.front_cam[0] == "none" and opt.down_cam[0] == "none":
        # 如果没有启用任何摄像头，输出提示信息并退出
        print("No Camera opened")
    else:
        # 初始化ROS2通信系统
        rclpy.init(args=args)
        # 创建图像采集节点实例，传入节点名称和配置参数
        node = CaptureNode("uv_capture", opt)
        # 启动节点的事件循环，使节点开始处理回调和定时器
        rclpy.spin(node)
        # 关闭ROS2通信系统，清理资源
        rclpy.shutdown()
        
# 如果此脚本被直接执行（而不是被导入），则调用主函数
if __name__ == '__main__':
    main()