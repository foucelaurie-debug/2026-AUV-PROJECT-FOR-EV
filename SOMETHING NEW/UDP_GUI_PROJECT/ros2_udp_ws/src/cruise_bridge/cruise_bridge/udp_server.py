import json
import socket
import threading
import time
from typing import Dict, Optional, Tuple

import cv2
import rclpy
from cv_bridge import CvBridge
from geometry_msgs.msg import Vector3
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.parameter_client import AsyncParameterClient
from sensor_msgs.msg import Image
from std_msgs.msg import Float32, String


class UdpBridgeNode(Node):
    """
    ROS2 <-> UDP 桥接节点

    功能：
    1. 订阅 ROS2 视频与遥测话题
    2. 通过 UDP 发送 JPEG 视频流
    3. 通过 UDP 周期性发送遥测 JSON
    4. 接收 UDP 控制指令与远程参数设置请求
    """

    def __init__(self) -> None:
        # 初始化 ROS2 节点，节点名为 udp_bridge
        super().__init__("udp_bridge")

        # ROS Image 与 OpenCV Image 转换工具
        self.bridge = CvBridge()

        # ======================
        # ROS2 参数声明
        # ======================
        self.declare_parameter("bind_host", "0.0.0.0")      # UDP 监听地址
        self.declare_parameter("control_port", 8000)        # 控制/遥测 UDP 端口
        self.declare_parameter("video_port", 8001)          # 视频 UDP 端口
        self.declare_parameter("telemetry_rate_hz", 5.0)    # 遥测发送频率
        self.declare_parameter("video_topic", "/front_cam/raw")
        self.declare_parameter("depth_topic", "/uv/depth")
        self.declare_parameter("attitude_topic", "/uv/attitude")
        self.declare_parameter("battery_topic", "/uv/battery")
        self.declare_parameter("ai_topic", "/uv/ai/status")
        self.declare_parameter("resize_width", 640)         # 视频宽度
        self.declare_parameter("resize_height", 480)        # 视频高度
        self.declare_parameter("jpeg_quality", 80)          # JPEG 压缩质量
        self.declare_parameter("max_udp_size", 65000)       # UDP 单包最大大小

        # ======================
        # 参数读取
        # ======================
        self.bind_host: str = self.get_parameter("bind_host").value
        self.control_port: int = int(self.get_parameter("control_port").value)
        self.video_port: int = int(self.get_parameter("video_port").value)
        self.telemetry_rate_hz: float = float(self.get_parameter("telemetry_rate_hz").value)
        self.resize_width: int = int(self.get_parameter("resize_width").value)
        self.resize_height: int = int(self.get_parameter("resize_height").value)
        self.jpeg_quality: int = int(self.get_parameter("jpeg_quality").value)
        self.max_udp_size: int = int(self.get_parameter("max_udp_size").value)

        # ======================
        # 内部状态缓存（最新遥测数据）
        # ======================
        self.latest_depth: Optional[float] = None
        self.latest_attitude: Optional[Vector3] = None
        self.latest_battery: Optional[float] = None
        self.latest_ai: Optional[str] = None
        self.last_command: Optional[str] = None

        # UDP 客户端信息（最后一个与本节点通信的客户端）
        self.client_lock = threading.Lock()
        self.client_addr: Optional[Tuple[str, int]] = None

        # 视频帧序号计数
        self.video_seq: int = 0

        # ROS2 参数客户端缓存（按 node_name 复用）
        self.param_clients: Dict[str, AsyncParameterClient] = {}

        # 节点运行状态标志
        self.running = True

        # ======================
        # UDP Socket 初始化
        # ======================

        # 控制 & 遥测 UDP socket（接收控制指令 + 发送遥测）
        self.control_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.control_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.control_sock.bind((self.bind_host, self.control_port))
        self.control_sock.settimeout(1.0)  # 防止 recv 阻塞，便于线程退出

        # 视频 UDP socket（只发送，不监听）
        self.video_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.video_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        # ======================
        # ROS2 话题订阅
        # ======================
        video_topic = self.get_parameter("video_topic").value
        depth_topic = self.get_parameter("depth_topic").value
        attitude_topic = self.get_parameter("attitude_topic").value
        battery_topic = self.get_parameter("battery_topic").value
        ai_topic = self.get_parameter("ai_topic").value

        self.create_subscription(Image, video_topic, self._image_callback, 10)
        self.create_subscription(Float32, depth_topic, self._depth_callback, 10)
        self.create_subscription(Vector3, attitude_topic, self._attitude_callback, 10)
        self.create_subscription(Float32, battery_topic, self._battery_callback, 10)
        self.create_subscription(String, ai_topic, self._ai_callback, 10)

        # ======================
        # 后台线程启动
        # ======================

        # UDP 控制接收线程
        self.control_thread = threading.Thread(
            target=self._control_loop, daemon=True
        )

        # 遥测定时发送线程
        self.telemetry_thread = threading.Thread(
            target=self._telemetry_loop, daemon=True
        )

        self.control_thread.start()
        self.telemetry_thread.start()

        self.get_logger().info(
            f"UDP bridge ready on {self.bind_host}:{self.control_port} (video:{self.video_port})"
        )

    # ======================
    # ROS2 回调函数
    # ======================

    def _image_callback(self, msg: Image) -> None:
        """
        视频话题回调：
        - ROS Image -> OpenCV
        - resize
        - JPEG 编码
        - UDP 发送
        """
        target_addr = self._get_video_target()
        if not target_addr:
            return

        try:
            # ROS Image 转 OpenCV BGR 图像
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

            # 缩放到指定分辨率
            resized = cv2.resize(
                cv_image, (self.resize_width, self.resize_height)
            )

            # JPEG 编码
            ok, encoded = cv2.imencode(
                ".jpg",
                resized,
                [int(cv2.IMWRITE_JPEG_QUALITY), self.jpeg_quality],
            )
            if not ok:
                self.get_logger().warning("JPEG 编码失败")
                return

            buffer = encoded.tobytes()

            # 超过 UDP 单包限制则直接丢弃
            if len(buffer) > self.max_udp_size:
                self.get_logger().warning(
                    f"帧大小 {len(buffer)} 超过 UDP 限制 {self.max_udp_size}"
                )
                return

            # 发送视频数据
            self.video_sock.sendto(buffer, target_addr)
            self.video_seq += 1

        except Exception as exc:
            self.get_logger().warning(f"视频发送异常: {exc}")

    def _depth_callback(self, msg: Float32) -> None:
        """更新最新深度数据"""
        self.latest_depth = float(msg.data)

    def _attitude_callback(self, msg: Vector3) -> None:
        """更新最新姿态（roll/pitch/yaw）"""
        self.latest_attitude = msg

    def _battery_callback(self, msg: Float32) -> None:
        """更新最新电池电量"""
        self.latest_battery = float(msg.data)

    def _ai_callback(self, msg: String) -> None:
        """更新 AI 状态字符串"""
        self.latest_ai = msg.data

    # ======================
    # UDP 控制接收线程
    # ======================

    def _control_loop(self) -> None:
        """
        接收 UDP 控制指令：
        - ping
        - command
        - set_param
        """
        while rclpy.ok() and self.running:
            try:
                data, addr = self.control_sock.recvfrom(65535)
            except socket.timeout:
                continue
            except OSError:
                break

            # 记录最近的客户端 IP
            with self.client_lock:
                self.client_addr = (addr[0], self.control_port)

            try:
                payload = json.loads(data.decode("utf-8"))
            except Exception:
                self.get_logger().warning("收到非法 JSON 控制包")
                continue

            action = payload.get("action")

            if action == "set_param":
                self._handle_set_param(payload, addr)

            elif action == "command":
                self.last_command = payload.get("cmd", "")
                self.get_logger().info(f"收到命令: {self.last_command}")
                self._send_ack(
                    {"status": "ok", "action": "command", "cmd": self.last_command},
                    addr,
                )

            elif action == "ping":
                self._send_ack({"status": "alive", "ts": time.time()}, addr)

            else:
                self._send_ack({"status": "unknown_action"}, addr)

    # ======================
    # 遥测发送线程
    # ======================

    def _telemetry_loop(self) -> None:
        """周期性向客户端发送遥测 JSON"""
        period = 1.0 / max(self.telemetry_rate_hz, 0.1)

        while rclpy.ok() and self.running:
            target = self._get_control_target()
            if target:
                telemetry = {
                    "heartbeat": time.time(),
                    "depth": self.latest_depth,
                    "attitude": self._attitude_dict(self.latest_attitude),
                    "battery": self.latest_battery,
                    "ai": self.latest_ai,
                    "last_command": self.last_command,
                    "video_seq": self.video_seq,
                }
                try:
                    self.control_sock.sendto(
                        json.dumps(telemetry).encode("utf-8"),
                        target,
                    )
                except Exception as exc:
                    self.get_logger().warning(f"遥测发送失败: {exc}")

            time.sleep(period)

    # ======================
    # 远程参数设置
    # ======================

    def _handle_set_param(self, payload: dict, reply_addr: Tuple[str, int]) -> None:
        """处理 set_param 控制指令"""
        node_name = payload.get("node")
        param_name = payload.get("param")
        value = payload.get("value")

        if not node_name or not param_name:
            self._send_ack(
                {"status": "error", "reason": "missing node/param"},
                reply_addr,
            )
            return

        try:
            # 获取或创建参数客户端
            client = self.param_clients.get(node_name)
            if client is None:
                client = AsyncParameterClient(self, node_name=node_name)
                self.param_clients[node_name] = client

            # 构造参数并异步设置
            parameter = Parameter(name=param_name, value=value)
            future = client.set_parameters([parameter])
            future.add_done_callback(
                lambda fut: self._on_param_result(fut, node_name, param_name)
            )

            self._send_ack(
                {"status": "sent", "node": node_name, "param": param_name},
                reply_addr,
            )

        except Exception as exc:
            self._send_ack({"status": "error", "reason": str(exc)}, reply_addr)
            self.get_logger().warning(f"参数设置异常: {exc}")

    def _on_param_result(
        self, future: rclpy.task.Future, node_name: str, param_name: str
    ) -> None:
        """参数设置完成回调"""
        try:
            result = future.result()
            for outcome in result:
                if not outcome.successful:
                    self.get_logger().warning(
                        f"参数设置失败 {node_name}:{param_name} -> {outcome.reason}"
                    )
        except Exception as exc:
            self.get_logger().warning(f"参数回调异常: {exc}")

    # ======================
    # 工具函数
    # ======================

    def _send_ack(self, payload: dict, addr: Tuple[str, int]) -> None:
        """发送 UDP ACK 回复"""
        try:
            self.control_sock.sendto(
                json.dumps(payload).encode("utf-8"), addr
            )
        except Exception as exc:
            self.get_logger().warning(f"ACK 发送失败: {exc}")

    def _get_video_target(self) -> Optional[Tuple[str, int]]:
        """获取视频发送目标地址"""
        with self.client_lock:
            if self.client_addr:
                return (self.client_addr[0], self.video_port)
        return None

    def _get_control_target(self) -> Optional[Tuple[str, int]]:
        """获取控制/遥测发送目标地址"""
        with self.client_lock:
            return self.client_addr

    @staticmethod
    def _attitude_dict(att: Optional[Vector3]) -> Optional[dict]:
        """Vector3 -> dict"""
        if att is None:
            return None
        return {"roll": att.x, "pitch": att.y, "yaw": att.z}

    def shutdown(self) -> None:
        """节点关闭清理"""
        self.running = False
        try:
            self.control_sock.close()
        except Exception:
            pass
        try:
            self.video_sock.close()
        except Exception:
            pass


def main(args=None) -> None:
    """ROS2 节点入口"""
    rclpy.init(args=args)
    node = UdpBridgeNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
