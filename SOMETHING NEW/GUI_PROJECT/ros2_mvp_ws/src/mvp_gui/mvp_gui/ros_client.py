"""ROS2 worker thread utilities for the GUI MVP."""
from __future__ import annotations

import queue
import threading
from functools import partial
from typing import Any, Dict, Optional

from PyQt6 import QtCore
import rclpy
from rcl_interfaces.msg import ParameterType
from rcl_interfaces.srv import GetParameters, ListParameters, SetParameters
from rclpy.executors import SingleThreadedExecutor
from rclpy.node import Node
from rclpy.parameter import Parameter
from std_msgs.msg import String


class GuiRosNode(Node):
    """ROS2 node that proxies parameter and topic actions for the GUI."""

    def __init__(self, worker: "ROSWorker") -> None:
        super().__init__("mvp_gui_bridge")
        self._worker = worker
        self._subscription = None
        self._current_topic: Optional[str] = None

    def fetch_parameters(self, target_node: str) -> None:
        normalized = self._normalize_name(target_node)
        if not normalized:
            self._worker.ros_feedback.emit("请输入有效的节点名称。")
            return
        list_client = self.create_client(ListParameters, f"{normalized}/list_parameters")
        if not list_client.wait_for_service(timeout_sec=2.0):
            self._worker.ros_feedback.emit("参数服务不可用，请确认节点已运行。")
            return
        list_request = ListParameters.Request()
        list_request.depth = 10
        list_future = list_client.call_async(list_request)
        if not self._wait_for_future(list_future):
            self._worker.ros_feedback.emit("获取参数列表超时。")
            return
        names = list_future.result().result.names
        if not names:
            self._worker.parameters_ready.emit({})
            return
        get_client = self.create_client(GetParameters, f"{normalized}/get_parameters")
        if not get_client.wait_for_service(timeout_sec=2.0):
            self._worker.ros_feedback.emit("获取参数值的服务不可用。")
            return
        get_request = GetParameters.Request()
        get_request.names = names
        get_future = get_client.call_async(get_request)
        if not self._wait_for_future(get_future):
            self._worker.ros_feedback.emit("获取参数值超时。")
            return
        value_map = self._convert_parameter_values(names, get_future.result().values)
        self._worker.parameters_ready.emit(value_map)

    def set_parameter(self, target_node: str, name: str, value: Any) -> None:
        normalized = self._normalize_name(target_node)
        if not normalized:
            self._worker.ros_feedback.emit("节点名称无效，无法设置参数。")
            return
        set_client = self.create_client(SetParameters, f"{normalized}/set_parameters")
        if not set_client.wait_for_service(timeout_sec=2.0):
            self._worker.ros_feedback.emit("无法连接到参数设置服务。")
            return
        request = SetParameters.Request()
        param_msg = Parameter(name=name, value=value).to_parameter_msg()
        request.parameters.append(param_msg)
        future = set_client.call_async(request)
        if not self._wait_for_future(future):
            self._worker.ros_feedback.emit("设置参数请求超时。")
            return
        result = future.result()
        if not result or not result.results:
            self._worker.ros_feedback.emit("参数设置失败，未收到响应。")
            return
        response = result.results[0]
        if response.successful:
            self._worker.ros_feedback.emit(f"参数 {name} 已更新。")
        else:
            self._worker.ros_feedback.emit(f"参数设置失败：{response.reason}")

    def subscribe_topic(self, topic_name: str) -> None:
        normalized = topic_name if topic_name.startswith("/") else f"/{topic_name}"
        if self._subscription:
            self.destroy_subscription(self._subscription)
            self._subscription = None
        self._subscription = self.create_subscription(
            String,
            normalized,
            self._handle_topic_message,
            10,
        )
        self._current_topic = normalized
        self._worker.ros_feedback.emit(f"订阅 {normalized} 成功。")

    def _handle_topic_message(self, msg: String) -> None:
        self._worker.topic_message.emit(msg.data)

    def _wait_for_future(self, future: rclpy.task.Future, timeout: float = 2.0) -> bool:
        if not rclpy.ok():
            return False
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout)
        return future.done()

    @staticmethod
    def _normalize_name(name: str) -> str:
        cleaned = name.strip()
        if not cleaned:
            return ""
        return cleaned if cleaned.startswith("/") else f"/{cleaned}"

    @staticmethod
    def _convert_parameter_values(names: Any, values: Any) -> Dict[str, Any]:
        result: Dict[str, Any] = {}
        for name, value in zip(names, values):
            if value.type == ParameterType.PARAMETER_DOUBLE:
                result[name] = value.double_value
            elif value.type == ParameterType.PARAMETER_INTEGER:
                result[name] = value.integer_value
            elif value.type == ParameterType.PARAMETER_STRING:
                result[name] = value.string_value
            elif value.type == ParameterType.PARAMETER_BOOL:
                result[name] = value.bool_value
            else:
                result[name] = "(unsupported type)"
        return result


class ROSWorker(QtCore.QThread):
    """Runs ROS2 interactions without blocking the GUI thread."""

    parameters_ready = QtCore.pyqtSignal(dict)
    ros_feedback = QtCore.pyqtSignal(str)
    topic_message = QtCore.pyqtSignal(str)

    def __init__(self) -> None:
        super().__init__()
        self._task_queue: "queue.Queue[tuple]" = queue.Queue()
        self._stop_event = threading.Event()
        self._executor: Optional[SingleThreadedExecutor] = None
        self._node: Optional[GuiRosNode] = None

    def run(self) -> None:
        rclpy.init(args=None)
        self._executor = SingleThreadedExecutor()
        self._node = GuiRosNode(worker=self)
        self._executor.add_node(self._node)
        while not self._stop_event.is_set():
            self._drain_tasks()
            self._executor.spin_once(timeout_sec=0.1)
        self._executor.shutdown()
        self._executor = None
        if self._node is not None:
            self._node.destroy_node()
        rclpy.shutdown()

    def stop(self) -> None:
        self._stop_event.set()
        self.wait(1000)

    def request_parameter_snapshot(self, target: str) -> None:
        self._enqueue_task(self._node.fetch_parameters if self._node else None, target)

    def push_parameter_update(self, target: str, name: str, value: Any) -> None:
        self._enqueue_task(self._node.set_parameter if self._node else None, target, name, value)

    def subscribe_to_topic(self, topic: str) -> None:
        self._enqueue_task(self._node.subscribe_topic if self._node else None, topic)

    def _enqueue_task(self, func: Optional[Any], *args: Any) -> None:
        if func is None:
            self.ros_feedback.emit("ROS2 节点尚未就绪。")
            return
        self._task_queue.put(partial(func, *args))

    def _drain_tasks(self) -> None:
        while True:
            try:
                task = self._task_queue.get_nowait()
            except queue.Empty:
                break
            try:
                task()
            except Exception as exc:  # pragma: no cover - defensive logging
                self.ros_feedback.emit(f"ROS2 操作失败：{exc}")

