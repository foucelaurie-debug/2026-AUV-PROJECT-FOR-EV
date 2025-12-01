# ROS2 Cross-Platform Control GUI MVP (V2)

> 逐步讲清楚如何在 PC 与 NVIDIA AGX 上部署、运行、验证本最小可行产品（MVP）。

## 1. 项目简介
- **目标**：验证一套跨平台控制 GUI 的核心链路——PyQt6 桌面端与 AGX 上 ROS2 节点之间的参数、话题与 SSH 命令交互。
- **产物**：两个 ROS2 Python 包（`mvp_talker`、`mvp_gui`）位于 `ros2_mvp_ws/src/`，外加本说明文档。
- **运行方式**：
  - AGX（Ubuntu 20.04/22.04）运行 `mvp_talker`，发布 `/mvp/data` 话题并暴露参数。
  - 开发者 PC（Windows 10/11 或 Ubuntu 22.04）运行 PyQt6 GUI，既作为 ROS2 节点，也通过 SSH 发送命令。

## 2. 目录结构速览
```
GUI_PROJECT/
└─ ros2_mvp_ws/
   ├─ requirements.txt          # pip 依赖
   └─ src/
      ├─ mvp_talker/            # AGX 端参数化 Talker
      │  └─ mvp_talker/parameter_talker.py
      └─ mvp_gui/               # PC 端 PyQt6 GUI
         └─ mvp_gui/
            ├─ app.py           # GUI 入口
            ├─ gui.py           # 三个 Tab 的界面逻辑
            ├─ ros_client.py    # ROS2 线程
            └─ ssh_client.py    # SSH 命令线程
```

## 3. 前置条件（两个设备都需要）
| 组件 | AGX (Ubuntu) | PC (Win/Ubuntu) |
| --- | --- | --- |
| ROS2 发行版 | Foxy / Humble（与 PC 保持一致） | 与 AGX 相同 |
| Python | 3.8+ | 3.8+ |
| SSH | `sudo apt install openssh-server` | 不需要（GUI 使用客户端）|
| Python 依赖 | `pip install -r requirements.txt` | 同左 |
| 其他 | 确保两台设备在**同一局域网**，`ROS_DOMAIN_ID` 设置一致 | Windows 需安装 ROS2 并在终端中 `call install/setup.bat` |

> **Tip**：建议为 PC 端创建虚拟环境 `python -m venv .venv && .venv\Scripts\activate`（Win）或 `source .venv/bin/activate`（Linux）。

## 4. 环境部署步骤
### 4.1 下载/复制代码
1. 将 `GUI_PROJECT/ros2_mvp_ws` 拷贝到目标机器（AGX 与 PC 可共用同一份）。
2. 在各自机器上执行：
   ```bash
   cd path/to/ros2_mvp_ws
   python -m pip install -r requirements.txt
   ```

### 4.2 构建 ROS2 工作区
1. 打开 ROS2 命令行（Linux: `source /opt/ros/<distro>/setup.bash`；Windows: `call C:\dev\ros2_<distro>\local_setup.bat`）。
2. 在 `ros2_mvp_ws` 下运行：
   ```bash
   colcon build --symlink-install
   ```
3. 构建完成后 **务必** `source install/setup.bash`（或 Windows `.bat`）。

## 5. 运行指南
### 5.1 在 AGX 启动 Talker
```bash
cd ros2_mvp_ws
source install/setup.bash
ros2 run mvp_talker parameter_talker
```
- 默认参数：`speed=1.0`、`message_content="Hello World"`、`enable_publishing=True`。
- 你可以另开终端使用 `ros2 param set /parameter_talker speed 1.5` 验证参数即时生效。

### 5.2 在 PC 启动 GUI
```bash
cd ros2_mvp_ws
source install/setup.bash  # Windows 改为 call 对应 bat
ros2 run mvp_gui mvp_gui
```
GUI 启动后会显示 3 个标签页：
1. **ROS2 Parameters**：输入目标节点（默认 `/parameter_talker`），点击 **Connect** 拉取参数；修改控件即触发远程 `set_parameters`。
2. **Topic Viewer**：填入话题名（默认 `/mvp/data`），点击 **Subscribe** 后实时显示消息。
3. **Remote Terminal**：填写 AGX 的 IP/用户名/密码，在命令框输入如 `ls -l /home`，点击 **Execute** 即可查看 stdout/stderr。

> GUI 底部状态栏实时提示 ROS2 的成功/失败信息；SSH 命令在新线程运行，界面不会卡死。

## 6. 验证清单（逐条勾选）
1. [ ] AGX 终端持续打印参数变化日志，并在 `/mvp/data` 发布消息。
2. [ ] GUI **Parameters** 页能加载三个参数，并能实时修改 `speed`、`message_content`、`enable_publishing`。
3. [ ] GUI **Topic Viewer** 持续显示来自 `/mvp/data` 的字符串（例如 `Hello World #5`）。
4. [ ] GUI **Remote Terminal** 可成功执行 `ls -l` 等命令并展示输出。
5. [ ] 修改 `speed` 为 2.0 后，话题消息频率明显加快；勾掉 `enable_publishing` 后消息停止。

## 7. 常见问题（FAQ）
- **GUI 显示“参数服务不可用”？** 确认 AGX 节点正在运行，且两台机器 `ROS_DOMAIN_ID` 相同。必要时在 PC 上 `ping <AGX IP>` 验证网络。
- **Topic Viewer 没数据？** 检查 `<AGX> ros2 topic echo /mvp/data` 是否有输出，无则查看 Talker 终端是否报错。
- **SSH 命令失败？** 确保 `openssh-server` 已安装并运行，账号密码正确，可先在终端 `ssh user@AGX` 测试。

## 8. 下一步建议
- 将 GUI 样式与操作提示本地化给更多操作员。
- 为 Talker 增加更多可调参数，并在 GUI 中扩展控件类型。
- 编写 `colcon test`/`pytest` 用例，便于 CI 自动化验证。

祝你调试顺利！若有修改需求，可直接在 `GUI_PROJECT/ros2_mvp_ws` 中迭代，保持 `Cruise/` 原样不动即可。
