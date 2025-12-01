# Project Title: AUV UDP Bridge & Control Dashboard
# Development Prompt: AUV UDP Communication System

## PROJECT OVERVIEW | 项目概述

### Background | 背景
The user has an existing ROS2 AUV project ("Cruise") running on an NVIDIA AGX. They need a lightweight, cross-platform method to tune parameters, view video feeds, and monitor status from a Windows PC *without* installing ROS2 on the PC.
用户现有一个运行在 NVIDIA AGX 上的 ROS2 AUV 项目 ("Cruise")。他们需要一种轻量级、跨平台的方法，在 Windows PC 上调节参数、查看视频流和监控状态，且**无需**在 PC 上安装 ROS2。

### Architecture | 架构
We will implement a **UDP Bridge Architecture**:
1.  **On-board (AGX):** A ROS2 Node (`udp_bridge`) that collects ROS data, compresses it, and streams it via UDP. It also listens for UDP commands and translates them into ROS service calls/topic publications.
2.  **Client (PC):** A pure Python/PyQt6 application (`cruise_dashboard`) that receives UDP streams for display and sends JSON commands for control.

### Communication Protocol | 通信协议
-   **Port 8000 (Bidirectional - Control/Telemetry):** JSON-based.
    -   *AGX -> PC:* Telemetry data (Depth, Attitude, Battery, Task Status).
    -   *PC -> AGX:* Commands (Set Parameter, Start Task).
-   **Port 8001 (Unidirectional - Video):** Binary JPEG stream.
    -   *AGX -> PC:* Compressed video frames.

---

## FUNCTIONAL REQUIREMENTS | 功能需求

### Component 1: The Bridge Node (AGX) | 桥接节点
**File:** `cruise_bridge/udp_server.py`

**Data Discovery & collection (Based on "Cruise" Project Context):**
The agent must implement subscriptions for the following logical data points based on the user's previous project description:
1.  **Vision:** Subscribe to the output of `uv_vision` (e.g., `sensor_msgs/Image`).
    *   *Action:* Resize to 640x480 (to save bandwidth) -> Compress to JPEG -> Send via UDP Port 8001.
2.  **Hardware Status:** Subscribe to data likely from `uv_hm`.
    *   *Data:* Depth, Roll/Pitch/Yaw, Motor speeds (simulated or real).
3.  **AI Results:** Subscribe to detection results from `uv_ai` (if available).

**Command Handling:**
1.  **Parameter Tuning:** Listen for JSON commands `{"action": "set_param", "node": "...", "param": "...", "value": ...}`.
    *   *Action:* Use `AsyncParameterClient` to dynamically update the target node's parameters.
2.  **Control:** Listen for `{"action": "command", "cmd": "..."}` (e.g., Arm/Disarm).

**Implementation Requirements:**
-   Use `rclpy` for ROS2.
-   Use standard `socket` and `threading` for UDP.
-   **Robustness:** Handle connection timeouts gracefully.

---

### Component 2: The PC Dashboard (Windows) | PC端仪表盘
**File:** `pc_client/dashboard.py`

**Tech Stack:** Python 3.8+, PyQt6, OpenCV (headless preferred for decoding). **NO ROS2 Libraries.**

**UI Layout:**
1.  **Video Panel:** Large central label to display the decoded JPEG stream from Port 8001.
2.  **Telemetry Sidebar:** Labels for:
    -   Connection Status (Heartbeat)
    -   Depth (m)
    -   Attitude (Roll/Pitch/Yaw)
    -   Battery (V)
3.  **Tuning Panel (Dynamic):**
    -   Dropdown to select Node (e.g., `uv_hm`, `uv_vision`).
    -   Dropdown to select Parameter (e.g., `pid_p`, `exposure`).
    -   Slider & SpinBox to adjust value.
    -   "Apply" Button to send the UDP command.
4.  **Terminal/Log:** A text area showing sent commands and received system messages.

**Implementation Requirements:**
-   **Threading:**
    -   `VideoThread`: Listens on 8001, decodes JPEG, emits `QImage` signal.
    -   `StatusThread`: Listens on 8000, parses JSON, emits signal.
-   **Network:** Allow user to input AGX IP address (Default: `192.168.16.151`).

---

## DELIVERABLES & README STRUCTURE | 交付物与文档结构

Please provide the code and a `README.md` covering:

### 1. Solution Logic | 解决思路
Explain how the UDP packets are structured and how the "Bridge" translates JSON to ROS2 Parameter calls.

### 2. Installation | 安装指南
-   **AGX:** `colcon build` instructions.
-   **PC:** `pip install PyQt6 opencv-python` instructions.

### 3. Usage Guide | 使用流程
**Step 1: Start the Bridge (AGX)**
```bash
source install/setup.bash
ros2 run cruise_bridge udp_server
# Expected Output: "UDP Bridge listening on 0.0.0.0:8000..."
Step 2: Start the Dashboard (PC)
code
Bash
python dashboard.py
# GUI opens. Enter IP 192.168.16.151 and click Connect.
Step 3: Tuning
Select "uv_hm" from the dropdown.
Type "pid_p" in parameter name.
Adjust slider.
Observe terminal output: Sent: {"action": "set_param", ...}
SPECIAL INSTRUCTIONS FOR AGENT | 给Agent的特殊指令
Simulate Data: Since you don't have the actual uv_msgs, please use standard ROS messages (std_msgs, sensor_msgs, geometry_msgs) to simulate the uv_hm and uv_ai data for the bridge.
Error Handling: The PC client must not crash if the UDP packet is malformed or if the video frame is incomplete. Add try-except blocks in the listening threads.
Code Structure: Provide the code in two distinct blocks: one for the ROS2 package (cruise_bridge) and one for the PC Client script.