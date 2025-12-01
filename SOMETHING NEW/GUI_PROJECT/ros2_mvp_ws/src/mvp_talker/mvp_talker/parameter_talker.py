"""Parameter-driven talker node used by the GUI MVP."""
from __future__ import annotations

from typing import Dict, Iterable

import rclpy
from rcl_interfaces.msg import SetParametersResult
from rclpy.node import Node
from rclpy.parameter import Parameter
from std_msgs.msg import String


class ParameterTalker(Node):
    """A timer-based talker that exposes adjustable parameters."""

    def __init__(self) -> None:
        super().__init__("parameter_talker")
        self._declare_initial_parameters()
        self._counter = 0
        self._publisher = self.create_publisher(String, "/mvp/data", 10)
        self._timer = self.create_timer(self._current_period, self._on_timer)
        self.add_on_set_parameters_callback(self._on_parameter_change)

    def _declare_initial_parameters(self) -> None:
        self._speed = float(
            self.declare_parameter("speed", 1.0).get_parameter_value().double_value
        )
        self._message_content = (
            self.declare_parameter("message_content", "Hello World")
            .get_parameter_value()
            .string_value
        )
        self._enable_publishing = (
            self.declare_parameter("enable_publishing", True)
            .get_parameter_value()
            .bool_value
        )
        self._enforce_speed_bounds()

    def _enforce_speed_bounds(self) -> None:
        self._speed = float(min(2.0, max(0.1, self._speed)))

    @property
    def _current_period(self) -> float:
        if self._speed <= 0:
            return 1.0
        return 1.0 / self._speed

    def _on_timer(self) -> None:
        if not self._enable_publishing:
            return
        msg = String()
        msg.data = f"{self._message_content} #{self._counter}"
        self._publisher.publish(msg)
        self._counter += 1

    def _on_parameter_change(self, params: Iterable[Parameter]) -> SetParametersResult:
        updates: Dict[str, str] = {}
        for param in params:
            if param.name == "speed":
                new_speed = float(param.value)
                if new_speed < 0.1 or new_speed > 2.0:
                    return SetParametersResult(
                        successful=False,
                        reason="speed must be between 0.1 and 2.0",
                    )
                self._speed = new_speed
                updates["speed"] = f"{new_speed:.2f}"
                self._restart_timer()
            elif param.name == "message_content":
                self._message_content = str(param.value)
                updates["message_content"] = self._message_content
            elif param.name == "enable_publishing":
                self._enable_publishing = bool(param.value)
                updates["enable_publishing"] = str(self._enable_publishing)
        if updates:
            print(f"[parameter_talker] Updated parameters: {updates}")
        return SetParametersResult(successful=True)

    def _restart_timer(self) -> None:
        self._enforce_speed_bounds()
        new_period = self._current_period
        if hasattr(self, "_timer") and self._timer is not None:
            self._timer.cancel()
            self.destroy_timer(self._timer)
        self._timer = self.create_timer(new_period, self._on_timer)


def main() -> None:
    rclpy.init()
    node = ParameterTalker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
