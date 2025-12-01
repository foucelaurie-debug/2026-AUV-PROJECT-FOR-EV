# AUV UDP 桥接与仪表盘

在 AGX 上的 ROS2 栈与 PC 上的 PyQt6 仪表盘之间建立轻量级 UDP 链路（PC 端无需安装 ROS）。端口约定：8000 传输遥测/控制 JSON，8001 传输 JPEG 视频。

## 方案逻辑
- `cruise_bridge/udp_server.py` 订阅 ROS2 话题（图像 + 用标准消息模拟的深度/姿态/电池/AI），将图像缩放到 640x480、JPEG 编码后通过 UDP 8001 推送。
- 遥测 JSON（心跳、深度、姿态、电池、AI、最后命令、视频序号）周期性发到 UDP 8000，目标是最近一次与桥接节点通信的客户端 IP。
- UDP 命令（8000）：
  - `{"action":"set_param","node":"...","param":"...","value":<数值>}` → 通过 `AsyncParameterClient` 下发参数。
  - `{"action":"command","cmd":"..."}` → 记录并回复。
  - `{"action":"ping"}` → 存活确认。
- PC 仪表盘 (`pc_client/dashboard.py`) 监听 8000/8001，显示视频与遥测，并发送参数/命令 JSON；异常捕获可防止畸形报文导致崩溃。

## 目录
- `ros2_udp_ws/src/cruise_bridge/` — ROS2 Python 包（桥接节点）。
- `pc_client/dashboard.py` — PyQt6 仪表盘。
- `requirements.txt` — PC 端依赖。

## 安装（AGX / ROS2 侧）
```bash
cd UDP_GUI_PROJECT/ros2_udp_ws
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
source install/setup.bash   # Windows: call install\setup.bat
```

## 安装（PC 仪表盘）
```bash
cd UDP_GUI_PROJECT
python -m venv .venv && .venv\Scripts\activate  # Linux: source .venv/bin/activate
pip install -r requirements.txt
```

## 运行
1) AGX 桥接节点：
```bash
cd UDP_GUI_PROJECT/ros2_udp_ws
source install/setup.bash
ros2 run cruise_bridge udp_server
# 绑定 0.0.0.0:8000（控制/遥测），视频发往最近客户端的 8001
```
如需修改订阅话题：
```bash
ros2 run cruise_bridge udp_server --ros-args \
  -p video_topic:=/front_cam/raw -p depth_topic:=/uv/depth \
  -p attitude_topic:=/uv/attitude -p battery_topic:=/uv/battery \
  -p ai_topic:=/uv/ai/status
```

2) PC 仪表盘：
```bash
cd UDP_GUI_PROJECT/pc_client
python dashboard.py
# 填 AGX IP（默认 192.168.16.151）后点击 Connect
```
视频走 8001，遥测走 8000；滑条发送 `set_param`，命令框发送 `command`。

## 说明
- 使用标准消息（sensor_msgs/Image、std_msgs/Float32、geometry_msgs/Vector3、std_msgs/String）模拟 uv_hm/uv_ai 数据。
- JPEG 帧若超过 `max_udp_size` 将被丢弃以避免分片。
- 遥测发送给最近一次发控制包的客户端，请先从 PC 发送一次包（如 ping/Connect）建立返回地址。
- `build/`、`install/`、`log/` 为 colcon 生成物，勿入库；大模型权重请放库外。
