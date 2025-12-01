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
    """Bridge ROS2 topics to UDP telemetry/video and accept UDP control/parameter commands."""

    def __init__(self) -> None:
        super().__init__("udp_bridge")
        self.bridge = CvBridge()

        # Parameters
        self.declare_parameter("bind_host", "0.0.0.0")
        self.declare_parameter("control_port", 8000)
        self.declare_parameter("video_port", 8001)
        self.declare_parameter("telemetry_rate_hz", 5.0)
        self.declare_parameter("video_topic", "/front_cam/raw")
        self.declare_parameter("depth_topic", "/uv/depth")
        self.declare_parameter("attitude_topic", "/uv/attitude")
        self.declare_parameter("battery_topic", "/uv/battery")
        self.declare_parameter("ai_topic", "/uv/ai/status")
        self.declare_parameter("resize_width", 640)
        self.declare_parameter("resize_height", 480)
        self.declare_parameter("jpeg_quality", 80)
        self.declare_parameter("max_udp_size", 65000)

        self.bind_host: str = self.get_parameter("bind_host").value
        self.control_port: int = int(self.get_parameter("control_port").value)
        self.video_port: int = int(self.get_parameter("video_port").value)
        self.telemetry_rate_hz: float = float(self.get_parameter("telemetry_rate_hz").value)
        self.resize_width: int = int(self.get_parameter("resize_width").value)
        self.resize_height: int = int(self.get_parameter("resize_height").value)
        self.jpeg_quality: int = int(self.get_parameter("jpeg_quality").value)
        self.max_udp_size: int = int(self.get_parameter("max_udp_size").value)

        # State
        self.latest_depth: Optional[float] = None
        self.latest_attitude: Optional[Vector3] = None
        self.latest_battery: Optional[float] = None
        self.latest_ai: Optional[str] = None
        self.last_command: Optional[str] = None
        self.client_lock = threading.Lock()
        self.client_addr: Optional[Tuple[str, int]] = None
        self.video_seq: int = 0
        self.param_clients: Dict[str, AsyncParameterClient] = {}
        self.running = True

        # Sockets
        self.control_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.control_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.control_sock.bind((self.bind_host, self.control_port))
        self.control_sock.settimeout(1.0)

        self.video_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.video_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        # Subscriptions
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

        # Threads
        self.control_thread = threading.Thread(target=self._control_loop, daemon=True)
        self.telemetry_thread = threading.Thread(target=self._telemetry_loop, daemon=True)
        self.control_thread.start()
        self.telemetry_thread.start()

        self.get_logger().info(
            f"UDP bridge ready on {self.bind_host}:{self.control_port} (video:{self.video_port})"
        )

    def _image_callback(self, msg: Image) -> None:
        """Convert ROS image to JPEG and send via UDP."""
        target_addr = self._get_video_target()
        if not target_addr:
            return
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
            resized = cv2.resize(cv_image, (self.resize_width, self.resize_height))
            ok, encoded = cv2.imencode(".jpg", resized, [int(cv2.IMWRITE_JPEG_QUALITY), self.jpeg_quality])
            if not ok:
                self.get_logger().warning("Failed to encode image to JPEG")
                return
            buffer = encoded.tobytes()
            if len(buffer) > self.max_udp_size:
                self.get_logger().warning(
                    f"Encoded frame size {len(buffer)} exceeds UDP limit {self.max_udp_size}"
                )
                return
            self.video_sock.sendto(buffer, target_addr)
            self.video_seq += 1
        except Exception as exc:  # noqa: BLE001
            self.get_logger().warning(f"Video send error: {exc}")

    def _depth_callback(self, msg: Float32) -> None:
        self.latest_depth = float(msg.data)

    def _attitude_callback(self, msg: Vector3) -> None:
        self.latest_attitude = msg

    def _battery_callback(self, msg: Float32) -> None:
        self.latest_battery = float(msg.data)

    def _ai_callback(self, msg: String) -> None:
        self.latest_ai = msg.data

    def _control_loop(self) -> None:
        """Listen for incoming UDP control/parameter commands."""
        while rclpy.ok() and self.running:
            try:
                data, addr = self.control_sock.recvfrom(65535)
            except socket.timeout:
                continue
            except OSError:
                break

            with self.client_lock:
                self.client_addr = (addr[0], self.control_port)

            try:
                payload = json.loads(data.decode("utf-8"))
            except Exception:
                self.get_logger().warning("Received malformed control packet")
                continue

            action = payload.get("action")
            if action == "set_param":
                self._handle_set_param(payload, addr)
            elif action == "command":
                self.last_command = payload.get("cmd", "")
                self.get_logger().info(f"Received command: {self.last_command}")
                self._send_ack({"status": "ok", "action": "command", "cmd": self.last_command}, addr)
            elif action == "ping":
                self._send_ack({"status": "alive", "ts": time.time()}, addr)
            else:
                self._send_ack({"status": "unknown_action"}, addr)

    def _telemetry_loop(self) -> None:
        """Push periodic telemetry JSON to the last known client."""
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
                    payload = json.dumps(telemetry).encode("utf-8")
                    self.control_sock.sendto(payload, target)
                except Exception as exc:  # noqa: BLE001
                    self.get_logger().warning(f"Telemetry send error: {exc}")
            time.sleep(period)

    def _handle_set_param(self, payload: dict, reply_addr: Tuple[str, int]) -> None:
        node_name = payload.get("node")
        param_name = payload.get("param")
        value = payload.get("value")
        if not node_name or not param_name:
            self._send_ack({"status": "error", "reason": "missing node/param"}, reply_addr)
            return

        try:
            client = self.param_clients.get(node_name)
            if client is None:
                client = AsyncParameterClient(self, node_name=node_name)
                self.param_clients[node_name] = client
            parameter = Parameter(name=param_name, value=value)
            future = client.set_parameters([parameter])
            future.add_done_callback(lambda fut: self._on_param_result(fut, node_name, param_name))
            self._send_ack({"status": "sent", "node": node_name, "param": param_name}, reply_addr)
        except Exception as exc:  # noqa: BLE001
            self._send_ack({"status": "error", "reason": str(exc)}, reply_addr)
            self.get_logger().warning(f"Parameter set error: {exc}")

    def _on_param_result(self, future: rclpy.task.Future, node_name: str, param_name: str) -> None:
        try:
            result = future.result()
            for outcome in result:
                if not outcome.successful:
                    self.get_logger().warning(
                        f"Parameter set failed for {node_name}:{param_name} -> {outcome.reason}"
                    )
        except Exception as exc:  # noqa: BLE001
            self.get_logger().warning(f"Parameter result error: {exc}")

    def _send_ack(self, payload: dict, addr: Tuple[str, int]) -> None:
        try:
            self.control_sock.sendto(json.dumps(payload).encode("utf-8"), addr)
        except Exception as exc:  # noqa: BLE001
            self.get_logger().warning(f"Ack send error: {exc}")

    def _get_video_target(self) -> Optional[Tuple[str, int]]:
        with self.client_lock:
            if self.client_addr:
                return (self.client_addr[0], self.video_port)
        return None

    def _get_control_target(self) -> Optional[Tuple[str, int]]:
        with self.client_lock:
            return self.client_addr

    @staticmethod
    def _attitude_dict(att: Optional[Vector3]) -> Optional[dict]:
        if att is None:
            return None
        return {"roll": att.x, "pitch": att.y, "yaw": att.z}

    def shutdown(self) -> None:
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
