import sys
import os
import cv2
import numpy as np
import torch
from pathlib import Path
from typing import List, Tuple, Dict, Any
import argparse
import tkinter as tk
from tkinter import filedialog

# --- 1. SuperGlue 依赖设置：将 SuperGlue 路径添加到 Python 路径 ---
# 请根据您的实际路径修改此变量
SUPERGLUE_PATH = r"E:\PROJECTS\AUV\SuperGluePretrainedNetwork-master"
if SUPERGLUE_PATH not in sys.path:
    sys.path.append(SUPERGLUE_PATH)

try:
    # 导入 SuperGlue 核心模块
    from models.superpoint import SuperPoint
    from models.superglue import SuperGlue
    print("SuperGlue 模块导入成功。")
except ImportError as e:
    print(f"致命错误：无法导入 SuperGlue 模块。请检查路径 {SUPERGLUE_PATH} 是否正确，且 'models/superpoint.py' 和 'models/superglue.py' 文件是否存在。")
    print(f"导入错误详情: {e}")
    sys.exit(1)

# YOLO 依赖
try:
    from ultralytics import YOLO
    print("YOLO (ultralytics) 模块导入成功。")
except ImportError:
    print("致命错误：无法导入 ultralytics 库。请安装：pip install ultralytics")
    sys.exit(1)

# --- 2. SuperGlue/SuperPoint 模型抽象封装 ---

class StereoFeatureMatcher:
    """
    封装 SuperPoint 特征提取和 SuperGlue 匹配逻辑。
    """
    def __init__(self, weights_dir: str):
        # SuperPoint 配置
        sp_config = {'nms_radius': 4, 'keypoint_threshold': 0.005, 'max_keypoints': 1024}
        # SuperGlue 配置
        sg_config = {'weights': 'outdoor', 'sinkhorn_iterations': 20, 'match_threshold': 0.2}

        device = 'cuda' if torch.cuda.is_available() else 'cpu'
        self.device = torch.device(device)
        weights_path = Path(weights_dir)
        
        self.matcher = SuperGlue(sg_config).to(self.device)
        self.keypoint_detector = SuperPoint(sp_config).to(self.device)
        
        # 加载权重
        self.keypoint_detector.load_state_dict(torch.load(weights_path / 'superpoint_v1.pth', map_location=device))
        self.matcher.load_state_dict(torch.load(weights_path / f'superglue_{sg_config["weights"]}.pth', map_location=device))
        
        self.keypoint_detector.eval()
        self.matcher.eval()
        
    def preprocess_image(self, img: np.ndarray) -> torch.Tensor:
        """ 将 OpenCV BGR 图像转换为 SuperGlue 所需的 PyTorch Tensor (灰度, 归一化) """
        if img is None:
             raise ValueError("Input image is None")
             
        # 转换为灰度图
        gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        
        # 归一化到 [0, 1]
        norm_img = gray_img / 255.0
        
        # 转换为 Tensor: (H, W) -> (1, 1, H, W)
        tensor = torch.from_numpy(norm_img).float()[None, None].to(self.device)
        return tensor

    def match(self, img_l_patch: np.ndarray, img_r_patch: np.ndarray) -> Tuple[np.ndarray, np.ndarray, int]:
        """
        运行 SuperPoint 和 SuperGlue，返回匹配成功的特征点坐标。
        """
        if img_l_patch.size == 0 or img_r_patch.size == 0:
            return np.array([]), np.array([]), 0

        # 1. 预处理
        tensor_l = self.preprocess_image(img_l_patch)
        tensor_r = self.preprocess_image(img_r_patch)

        # 2. 特征提取 (SuperPoint)
        with torch.no_grad():
            pred_l = self.keypoint_detector( {'image': tensor_l} )
            pred_r = self.keypoint_detector( {'image': tensor_r} )
            
        # 3. 格式化 SuperGlue 输入
        kpts0_raw = pred_l['keypoints'][0]
        kpts1_raw = pred_r['keypoints'][0]

        # 关键修复：检查 keypoint 维度 (解决 RuntimeError)
        if kpts0_raw.shape[0] == 2 and kpts0_raw.shape[1] != 2:
            kpts0_final = kpts0_raw.transpose(0, 1) # (2, N) -> (N, 2)
        else:
            kpts0_final = kpts0_raw
            
        if kpts1_raw.shape[0] == 2 and kpts1_raw.shape[1] != 2:
            kpts1_final = kpts1_raw.transpose(0, 1) # (2, N) -> (N, 2)
        else:
            kpts1_final = kpts1_raw
        
        data = {
            'keypoints0': kpts0_final.unsqueeze(0),
            'keypoints1': kpts1_final.unsqueeze(0),
            
            'descriptors0': pred_l['descriptors'][0].unsqueeze(0), 
            'descriptors1': pred_r['descriptors'][0].unsqueeze(0),
            
            'scores0': pred_l['scores'][0].unsqueeze(0),
            'scores1': pred_r['scores'][0].unsqueeze(0),
            
            'image0': tensor_l,
            'image1': tensor_r,
        }
        
        # 4. 匹配 (SuperGlue)
        with torch.no_grad():
            pred = self.matcher(data)
            
        # 5. 提取匹配结果
        kpts_l = data['keypoints0'][0].cpu().numpy() # (N, 2)
        kpts_r = data['keypoints1'][0].cpu().numpy() # (N, 2)
        
        matches = pred['matches0'][0].cpu().numpy() 
        valid = matches > -1
        
        kpts_l_matched = kpts_l[valid]
        kpts_r_matched = kpts_r[matches[valid]]
        
        num_matches = kpts_l_matched.shape[0]

        return kpts_l_matched, kpts_r_matched, num_matches

# --- 3. 几何计算和主函数 ---

def triangulate_and_fuse(P1: np.ndarray, P2: np.ndarray, pts_l: np.ndarray, pts_r: np.ndarray) -> Tuple[float, float, float]:
    """ 批量三角测量并使用中位数融合结果，返回 (X, Y, Z) 笛卡尔坐标。"""
    if pts_l.shape[0] < 5:
        return 0.0, 0.0, 0.0

    # 1. 准备数据格式 (2xN)
    pts_l_2xN = pts_l.T 
    pts_r_2xN = pts_r.T

    # 2. 批量三角测量 (4xN 齐次坐标)
    pt_4d = cv2.triangulatePoints(P1, P2, pts_l_2xN, pts_r_2xN)

    # 3. 归一化为笛卡尔坐标 (3xN)
    pt_3d_cartesian = pt_4d[:3] / pt_4d[3]

    # 4. 融合：使用中位数进行鲁棒估计
    X_median = np.median(pt_3d_cartesian[0, :])
    Y_median = np.median(pt_3d_cartesian[1, :])
    Z_median = np.median(pt_3d_cartesian[2, :])
    
    # 输出：(X_左右偏移, Y_上下偏移, Z_深度)
    return float(X_median), float(Y_median), float(Z_median)


def select_image_path() -> str:
    """ 使用 Tkinter GUI 弹出文件选择窗口 """
    root = tk.Tk()
    root.withdraw()  # 隐藏主窗口
    file_path = filedialog.askopenfilename(
        title="选择双目拼接图像文件",
        filetypes=[("Image files", "*.jpg *.jpeg *.png")]
    )
    root.destroy()
    return file_path

# 用于存储绘图信息的结构
MatchDrawInfo = Tuple[np.ndarray, np.ndarray] # (pts_l_full, pts_r_full)

def main():
    # --- 0. 参数设置 ---
    parser = argparse.ArgumentParser(description="SuperGlue 复合双目测距测试")
    parser.add_argument('--yolo_weights', type=str, default=r"E:\PROJECTS\yolo-training\train\train\weights\best.pt", help='YOLO model pt file path')
    parser.add_argument('--sg_weights_dir', type=str, default=str(Path(SUPERGLUE_PATH) / 'models' / 'weights'), help='SuperGlue weights directory')
    args = parser.parse_args()

    # --- 1. 初始化模型和参数 ---
    print("\n[STEP 1] 初始化 YOLO 和 SuperGlue 模型...")
    yolo_model = YOLO(args.yolo_weights)
    sg_matcher = StereoFeatureMatcher(args.sg_weights_dir)
    
    # 矫正后的投影矩阵 P1 和 P2 (请替换为您的实际 npz 文件加载逻辑)
    focal_length = 600.0  # 焦距
    baseline = 0.12       # 基线
    cx = 320.0            # 图像中心 x
    cy = 240.0            # 图像中心 y
    P1 = np.array([[focal_length, 0, cx, 0], [0, focal_length, cy, 0], [0, 0, 1, 0]], dtype=np.float32)
    P2 = np.array([[focal_length, 0, cx, -focal_length * baseline], [0, focal_length, cy, 0], [0, 0, 1, 0]], dtype=np.float32)
    
    # --- 2. 选择图像并预处理 ---
    img_path = select_image_path()
    if not img_path:
        print("未选择图像文件，程序退出。")
        return

    print(f"\n[STEP 2] 正在处理图像：{img_path}")
    img_full = cv2.imread(img_path)
    if img_full is None:
        print("无法读取图像。")
        return

    # 摄像头方向倒置：进行图像翻转
    img_full = cv2.flip(img_full, -1)
    
    # 左右目分割
    height, width, _ = img_full.shape
    half_width = width // 2
    img_l = img_full[:, :half_width]
    img_r = img_full[:, half_width:]
    
    # --- 3. YOLO 检测 ---
    print("[STEP 3] YOLO 目标检测...")
    yolo_results = yolo_model.predict(source=img_full, conf=0.5, verbose=False)[0]
    
    # YOLO 检测结果结构
    detections: Dict[int, List[Dict[str, Any]]] = {} 

    # 处理 YOLO 结果并分离左右目标
    for i, box in enumerate(yolo_results.boxes):
        x1, y1, x2, y2 = [int(x) for x in box.xyxy[0].cpu().numpy()]
        conf = float(box.conf[0].cpu().numpy())
        cls = int(box.cls[0].cpu().numpy())
        name = yolo_model.names[cls]

        # 判断左右目
        if x2 <= half_width: # 完全位于左目
            side = 'L'
            x1_box, x2_box = x1, x2
        elif x1 >= half_width: # 完全位于右目
            side = 'R'
            # 右目图像块坐标修正：x1, x2 减去 half_width
            x1_patch = x1 - half_width
            x2_patch = x2 - half_width
            x1_box, x2_box = x1_patch, x2_patch
        else:
            continue # 忽略跨越中线的检测框

        if cls not in detections:
            detections[cls] = []
        
        detections[cls].append({
            'box': (x1_box, y1, x2_box, y2), # 图像块相对坐标
            'conf': conf, 
            'side': side,
            'full_box': [int(x) for x in box.xyxy[0].cpu().numpy()] # 全图坐标
        })

    print(f"  -> 总共检测到 {len(yolo_results.boxes)} 个目标。")
    
    # --- 4. SuperGlue 关联与测距 ---
    print("\n[STEP 4] SuperGlue 关联与三维测距...")
    final_results: Dict[str, Tuple[float, float, float]] = {}
    match_draw_list: List[MatchDrawInfo] = [] # 存储用于绘图的匹配点对
    
    matched_r_indices = {} # {class_id: [list of matched R box indices]}
    
    for cls, targets in detections.items():
        if cls not in matched_r_indices:
            matched_r_indices[cls] = []
            
        targets_l = [t for t in targets if t['side'] == 'L']
        targets_r = [t for t in targets if t['side'] == 'R']
        
        # 遍历左目目标
        for i_l, target_l in enumerate(targets_l):
            (x1_l, y1_l, x2_l, y2_l) = target_l['box']
            img_l_patch = img_l[y1_l:y2_l, x1_l:x2_l]
            
            best_match_score = -1
            best_r_index = -1
            final_pts_l, final_pts_r = None, None

            # 遍历右目同类目标
            for i_r, target_r in enumerate(targets_r):
                # 检查是否已被匹配
                if i_r in matched_r_indices[cls]:
                    continue
                
                (x1_r, y1_r, x2_r, y2_r) = target_r['box']
                img_r_patch = img_r[y1_r:y2_r, x1_r:x2_r]
                
                # 运行 SuperGlue (获得图像块坐标下的匹配点)
                pts_l_patch, pts_r_patch, num_matches = sg_matcher.match(img_l_patch, img_r_patch)

                if num_matches > best_match_score:
                    best_match_score = num_matches
                    best_r_index = i_r
                    
                    # 转换匹配点坐标为**全图**坐标 (全图坐标用于 Triangulate 和绘制)
                    pts_l_full = pts_l_patch + np.array([[target_l['full_box'][0], target_l['full_box'][1]]])
                    pts_r_full = pts_r_patch + np.array([[target_r['full_box'][0], target_r['full_box'][1]]])
                    
                    final_pts_l = pts_l_full
                    final_pts_r = pts_r_full

            # 如果找到足够多匹配点 (例如 > 20 个)
            if best_match_score > 20 and best_r_index != -1:
                # 标记右目目标为已匹配
                matched_r_indices[cls].append(best_r_index)

                # 批量三角测量
                X, Y, Z = triangulate_and_fuse(P1, P2, final_pts_l, final_pts_r)

                # 存储结果
                target_name = f"CLS:{yolo_model.names[cls]}_ID:{i_l}"
                final_results[target_name] = (X, Y, Z)
                match_draw_list.append((final_pts_l, final_pts_r)) # 存储匹配点对用于绘制
                print(f"  -> 关联成功：{target_name} ({best_match_score} 特征点) -> X:{X:.3f}m, Y:{Y:.3f}m, Z:{Z:.3f}m")
            else:
                print(f"  -> 左目 {yolo_model.names[cls]} 目标 {i_l} 未找到可靠的右目匹配。")
                
    # --- 5. 结果输出 ---
    print("\n[STEP 5] 最终三维坐标结果 (中位数融合)")
    print("-" * 50)
    
    for target_id, (X, Y, Z) in final_results.items():
        print(f"目标 [{target_id}]:")
        print(f"  相对坐标 (X_左右, Y_上下, Z_深度): ({X:.3f}, {Y:.3f}, {Z:.3f}) m")
    
    print("-" * 50)

    # --- 6. 显示结果图（包含连线和尺寸调整） ---
    print("\n[STEP 6] 显示结果图 (SuperGlue匹配点和尺寸调整)")
    img_display = img_full.copy()
    
    # 随机生成颜色用于绘制匹配线
    colors = [tuple(np.random.randint(0, 256, 3).tolist()) for _ in range(len(match_draw_list))]
    
    # 绘制 SuperGlue 匹配连线
    for (pts_l, pts_r), color in zip(match_draw_list, colors):
        color = (int(color[0]), int(color[1]), int(color[2]))
        for (xl, yl), (xr, yr) in zip(pts_l, pts_r):
            # 左目点
            cv2.circle(img_display, (int(xl), int(yl)), 2, color, -1)
            # 右目点
            cv2.circle(img_display, (int(xr), int(yr)), 2, color, -1)
            # 连线
            cv2.line(img_display, (int(xl), int(yl)), (int(xr), int(yr)), color, 1)


    # 绘制 YOLO 框和结果文本
    for targets in detections.values():
        for target in targets:
            x1, y1, x2, y2 = target['full_box']
            cv2.rectangle(img_display, (x1, y1), (x2, y2), (0, 255, 255), 2)
            
    # 绘制 3D 结果文本
    for target_id, (X, Y, Z) in final_results.items():
        # 查找对应的 YOLO 框（简化查找，实际应用中需更严谨）
        target_info = next(
            (t for targets in detections.values() for t in targets if target_id.endswith(f"_ID:{targets.index(t)}")), None
        )
        if target_info:
            x1, y1 = target_info['full_box'][0], target_info['full_box'][1]
            text = f"X:{X:.2f}m Y:{Y:.2f}m Z:{Z:.2f}m"
            cv2.putText(img_display, text, (x1, y1 + 25), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)


    # **图片尺寸调整为更小的视图**
    display_scale = 0.8 # 调整到原图的 80%
    new_width = int(img_display.shape[1] * display_scale)
    new_height = int(img_display.shape[0] * display_scale)
    img_resized = cv2.resize(img_display, (new_width, new_height))

    cv2.imshow("Detection and Triangulation Result (Scaled)", img_resized)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    

if __name__ == "__main__":
    main()