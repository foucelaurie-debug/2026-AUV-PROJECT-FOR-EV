# AUV项目智能助手上下文文档 (agent.md)

## 项目概述

这是一个基于ROS2的自主水下航行器(AUV)软件系统，集成了硬件控制、环境感知、AI决策与任务执行等多个功能模块。项目采用模块化设计，实现水下环境中的自主导航与作业能力。

## 核心技术栈

- **机器人操作系统**: ROS 2 (Foxy/Galactic)
- **编程语言**: Python 3.8+
- **构建系统**: colcon
- **深度学习框架**: PyTorch + Ultralytics YOLOv8
- **计算机视觉**: OpenCV, CvBridge
- **底层通信**: PySerial (自定义二进制协议)
- **坐标系统**: 自定义坐标系转换库

## 项目结构

```
e:\PROJECTS\AUV\
├── Cruise\                    # 主要ROS2工作空间
│   ├── src\                   # 源代码目录
│   │   ├── uv_ai\            # AI感知包 (目标检测、分割)
│   │   ├── uv_control_py\    # 控制算法库 (PID, 推力曲线)
│   │   ├── uv_hm\            # 硬件管理包
│   │   ├── uv_launch_pkg\    # 启动文件包
│   │   ├── uv_msgs\          # 自定义消息包
│   │   └── uv_vision\        # 视觉采集包
│   ├── datas\                # 核心数据与配置文件目录
│   ├── install\              # colcon构建后安装目录
│   ├── build\                # colcon构建中间文件目录
│   └── log\                  # ROS2节点日志文件目录
└── README.md                  # 项目详细文档
```

## 核心功能模块详解

### 1. 视觉数据采集 (uv_vision)

**关键文件**: `uv_vision/uv_vision/uv_capture.py`

**功能**: 
- 从前视和下视立体摄像头获取图像数据
- 发布原始图像和校正后图像
- 支持图像翻转和立体校正

**主要话题**:
- `front_cam/raw/left`, `front_cam/raw/right` - 前视原始图像
- `front_cam/rectified/left`, `front_cam/rectified/right` - 前视校正图像
- `down_cam/raw/left`, `down_cam/raw/right` - 下视原始图像
- `down_cam/rectified/left`, `down_cam/rectified/right` - 下视校正图像

### 2. AI感知系统 (uv_ai)

**关键文件**:
- `uv_ai/uv_ai/uv_detect_demo.py` - 目标检测节点
- `uv_ai/uv_ai/uv_segment.py` - 图像分割节点
- `uv_ai/uv_ai/uv_automaton.py` - 任务自动化节点

**功能**:
- 运行YOLOv8模型进行实时目标检测
- 图像分割用于识别水下引导线
- 立体视觉计算目标三维坐标
- 自动化任务执行和状态机管理

**AI模型文件** (位于datas目录):
- `AUV2025V1.pt` - 主要目标检测模型
- `redline-7-2.pt` - 红线分割模型
- `segment.pt` - 通用分割模型

**主要话题**:
- `uv_detect_down`, `uv_detect_front` - 检测结果 (Yolov8消息类型)
- `binary_segment_img` - 二值化分割结果
- `detectedimg_down`, `detectedimg_front` - 可视化调试图像

### 3. 硬件管理系统 (uv_hm)

**关键文件**: `uv_hm/uv_hm/uv_hmu.py`

**功能**:
- 作为ROS软件与底层硬件的桥梁
- 通过串口与微控制器(H750/F407)通信
- 解析AUV完整状态(漏水、电压、姿态、位置、速度等)
- 处理控制指令并发送给硬件

**通信协议**: 自定义二进制协议，以`0xfa 0xaf`开头，`0xfb 0xbf`结尾

**主要话题**:
- 发布: `motion_controller`, `device_manager`, `pid_controllers`, `curves`
- 订阅: `target_pos_down`, `openloop_thrust`, `pid_controllers_set`等

### 4. 控制算法库 (uv_control_py)

**关键文件**:
- `uv_control_py/uv_control_py/Pid.py` - PID控制器实现
- `uv_control_py/uv_control_py/Curve.py` - 推力曲线处理
- `uv_control_py/uv_control_py/Serial.py` - 串口通信封装

**功能**: 提供被其他包导入的控制算法库，不是独立节点

### 5. 自定义消息系统 (uv_msgs)

**关键消息定义**:
- `Yolov8.msg` - 目标检测结果
- `RobotMotionController.msg` - AUV运动状态
- `RobotDeviceManager.msg` - 设备健康状态
- `TargetPosDown.msg` - 目标位置指令
- `PidParams.msg` - PID参数设置

### 6. 启动配置 (uv_launch_pkg)

**关键文件**: `uv_launch_pkg/launch/launch.py`

**功能**: 一键启动核心节点系统
- `uv_core` (硬件管理)
- `uv_capture` (视觉采集)
- `uv_detect_demo` (目标检测)
- `uv_segment` (图像分割)

## 核心配置文件

### 1. PID参数 (`datas/pid_parameters.json`)
```json
{
  "x": {"p": 35000.0, "i": 0.0, "d": 500000.0, "i_limit": 2000.0, "output_limit": 500.0},
  "y": {"p": 35000.0, "i": 100.0, "d": 900000.0, "i_limit": 2000.0, "output_limit": 5000.0},
  "z": {"p": 6500.0, "i": 100.0, "d": 900000.0, "i_limit": 500.0, "output_limit": 2000.0},
  "rz": {"p": 39.0, "i": 1.0, "d": 400.0, "i_limit": 1.0, "output_limit": 5000.0}
}
```

### 2. 推力曲线 (`datas/thrust_cureves.json`)
定义每个推进器(m0-m5)的输入控制信号到实际输出推力的非线性映射关系

### 3. 相机标定参数 (`datas/*.npz`)
- `front.npz` - 前视相机标定参数
- `down.npz` - 下视相机标定参数

### 4. 任务定义 (`datas/uv_tasks*.json`)
```json
{
  "tasks": [
    {"name": "pass_door", "params": {"num": 11}},
    {"name": "mttpos_amend", "params": {"x": 1.72, "y": 5.4, "z": 0.4, "rz": -25.0}},
    {"name": "line", "params": {"ys_dep": 0.7}},
    {"name": "grab_golf", "params": {"kind": "blue_golf", "dx": -0.01, "dy": 0.25}}
  ]
}
```

## 数据流架构

```
物理硬件 → uv_capture → uv_detect_demo/uv_segment → uv_automaton → uv_core → 微控制器
    ↑                                                              ↓
    └───────────────────── 状态反馈 ←─────────────────────────────────┘
```

1. **数据采集**: 摄像头获取图像数据
2. **AI感知**: YOLOv8模型进行目标检测和分割
3. **决策控制**: 自动化节点根据任务和感知结果制定控制策略
4. **硬件执行**: 通过串口发送控制指令给微控制器
5. **状态反馈**: 微控制器返回AUV状态信息

## 坐标系统

项目使用自定义坐标系统:
- **世界坐标系**: 固定参考坐标系
- **机器人坐标系**: AUV本体坐标系
- **相机坐标系**: 前视和下视相机独立坐标系

相机偏置参数:
- 前视相机: x=0.1076m, y=0.320m, z=0.065m, rx=-90°
- 下视相机: x=0.0m, y=0.170m, z=0.0427m

## 构建与运行

### 环境准备
```bash
# 安装ROS2 (Foxy/Galactic)
# 安装Python依赖
pip install torch ultralytics opencv-python pyserial rclpy
```

### 构建项目
```bash
cd e:\PROJECTS\AUV\Cruise
colcon build
```

### 运行系统
```bash
# Source环境
source install/setup.bash

# 启动核心系统
ros2 launch uv_launch_pkg launch.py

# 启动自动化任务 (另开终端)
ros2 run uv_ai uv_automaton
```

## 调试与监控

### 常用命令
```bash
# 查看话题列表
ros2 topic list

# 监听特定话题
ros2 topic echo /motion_controller

# 可视化节点关系
rqt_graph

# 查看图像话题
rqt_image_view
```

### 关键监控点
1. `/motion_controller` - AUV运动状态
2. `/device_manager` - 设备健康状态
3. `/uv_detect_down`, `/uv_detect_front` - 目标检测结果
4. `/binary_segment_img` - 分割结果

## 常见任务类型

1. **pass_door** - 通过门障碍
2. **mttpos_amend** - 移动到指定位置
3. **line** - 巡线任务
4. **grab_golf** - 抓取高尔夫球任务

## 开发注意事项

1. **串口通信**: 确保正确配置H750和F407微控制器的串口路径
2. **AI模型**: 模型文件路径在datas目录，确保模型文件存在
3. **坐标转换**: 注意各坐标系之间的转换关系
4. **PID调参**: 根据实际硬件响应调整PID参数
5. **任务配置**: 修改uv_tasks.json文件来调整任务序列

## 扩展开发

### 添加新的AI模型
1. 将新的.pt模型文件放入datas目录
2. 在uv_detect_demo.py中添加模型加载逻辑
3. 更新相应的消息定义

### 添加新的任务类型
1. 在uv_automaton.py中添加新的任务处理函数
2. 更新uv_tasks.json配置文件格式
3. 添加相应的控制逻辑

### 修改控制算法
1. 主要在uv_control_py包中修改PID或推力曲线算法
2. 更新相应的配置文件
3. 重新构建项目

## 故障排除

1. **摄像头无法启动**: 检查设备权限和驱动
2. **AI模型加载失败**: 确认模型文件路径和格式
3. **串口通信异常**: 检查串口路径和波特率设置
4. **节点启动失败**: 检查ROS2环境配置和依赖安装

这个文档为后续的开发、调试和维护工作提供了完整的上下文参考。