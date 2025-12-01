"""Modernised orchestration layer for the UV automaton node.

This module keeps behavioural parity with :mod:`uv_automaton` while providing
clearer structure around task dispatching and the interactive CLI utilities.
Low level motion / perception logic is reused by inheriting from the legacy
implementation.  The goal is to make it easier to maintain the behaviour
catalogue (task list) and related tooling without having to touch the lengthy
legacy file.
"""

from __future__ import annotations

import argparse
import json
import threading
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Callable, Dict, Iterable, Mapping, Optional, Sequence, Tuple

import rclpy

from . import uv_automaton as legacy

TaskPayload = Any
TaskHandler = Callable[[legacy.CoreNode, TaskPayload], None]


def _to_float(value: str) -> float:
    return float(value)


def _to_int(value: str) -> int:
    return int(value)


def _to_str(value: str) -> str:
    return value


@dataclass(frozen=True)
class ParameterSpec:
    """Specification for a command line parameter."""

    name: str
    converter: Callable[[str], Any]


@dataclass(frozen=True)
class TaskDescriptor:
    """Metadata describing how to execute and configure a task."""

    name: str
    handler: TaskHandler
    parameters: Tuple[ParameterSpec, ...] = field(default_factory=tuple)
    store_as_mapping: bool = True

    def build_payload(self, args: Sequence[str]) -> TaskPayload:
        """Convert CLI arguments into the payload expected by ``handler``."""
        if len(args) != len(self.parameters):
            raise ValueError(
                f"{self.name} 需要 {len(self.parameters)} 个参数, 实际得到 {len(args)} 个"
            )

        if not self.parameters:
            return {} if self.store_as_mapping else None

        converted = [spec.converter(arg) for spec, arg in zip(self.parameters, args)]

        if self.store_as_mapping:
            return {
                spec.name: value
                for spec, value in zip(self.parameters, converted)
            }

        if len(converted) == 1:
            return converted[0]

        return tuple(converted)

    def normalise_payload(self, raw: TaskPayload) -> TaskPayload:
        """Ensure a payload loaded from disk matches the expected shape."""
        if self.store_as_mapping:
            if raw is None:
                return {}
            if not isinstance(raw, Mapping):
                raise TypeError(f"{self.name} 需要字典参数, 当前为 {type(raw)!r}")
            return dict(raw)

        # 非映射参数允许直接传入数字或 None。
        return raw

    def execute(self, node: legacy.CoreNode, payload: TaskPayload) -> None:
        self.handler(node, payload)


def _build_default_registry() -> Dict[str, TaskDescriptor]:
    """Factory producing the default task registry used by ``CoreNode``."""

    def _bind_args(method_name: str, *arg_names: str) -> TaskHandler:
        def _run(node: legacy.CoreNode, params: Mapping[str, Any]) -> None:
            kwargs = {name: params[name] for name in arg_names}
            getattr(node, method_name)(**kwargs)

        return _run

    def _bind_direct(method_name: str) -> TaskHandler:
        def _run(node: legacy.CoreNode, value: Any) -> None:
            getattr(node, method_name)(value)

        return _run

    def _bind_no_args(method_name: str) -> TaskHandler:
        def _run(node: legacy.CoreNode, _: TaskPayload) -> None:
            getattr(node, method_name)()

        return _run

    return {
        "movexyz": TaskDescriptor(
            name="movexyz",
            handler=_bind_args("movexyz", "x", "y", "z"),
            parameters=(
                ParameterSpec("x", _to_float),
                ParameterSpec("y", _to_float),
                ParameterSpec("z", _to_float),
            ),
        ),
        "throw_golf": TaskDescriptor(
            name="throw_golf",
            handler=_bind_args("throw_golf", "dy", "depth"),
            parameters=(
                ParameterSpec("dy", _to_float),
                ParameterSpec("depth", _to_float),
            ),
        ),
        "movexy": TaskDescriptor(
            name="movexy",
            handler=_bind_args("movexy", "x", "y"),
            parameters=(
                ParameterSpec("x", _to_float),
                ParameterSpec("y", _to_float),
            ),
        ),
        "movex": TaskDescriptor(
            name="movex",
            handler=_bind_args("movex", "x"),
            parameters=(ParameterSpec("x", _to_float),),
        ),
        "movey": TaskDescriptor(
            name="movey",
            handler=_bind_args("movey", "y"),
            parameters=(ParameterSpec("y", _to_float),),
        ),
        "movez": TaskDescriptor(
            name="movez",
            handler=_bind_args("movez", "z"),
            parameters=(ParameterSpec("z", _to_float),),
        ),
        "moverz": TaskDescriptor(
            name="moverz",
            handler=_bind_args("moverz", "rz"),
            parameters=(ParameterSpec("rz", _to_float),),
        ),
        "setz": TaskDescriptor(
            name="setz",
            handler=_bind_args("setz", "z"),
            parameters=(ParameterSpec("z", _to_float),),
        ),
        "setrz": TaskDescriptor(
            name="setrz",
            handler=_bind_args("setrz", "rz"),
            parameters=(ParameterSpec("rz", _to_float),),
        ),
        "search": TaskDescriptor(
            name="search",
            handler=_bind_args("search", "name", "cam"),
            parameters=(
                ParameterSpec("name", _to_str),
                ParameterSpec("cam", _to_str),
            ),
        ),
        "mtty": TaskDescriptor(
            name="mtty",
            handler=_bind_args("mtty", "y", "z"),
            parameters=(
                ParameterSpec("y", _to_float),
                ParameterSpec("z", _to_float),
            ),
        ),
        "mttxf": TaskDescriptor(
            name="mttxf",
            handler=_bind_args("mttxf", "dx", "dy"),
            parameters=(
                ParameterSpec("dx", _to_float),
                ParameterSpec("dy", _to_float),
            ),
        ),
        "mttz": TaskDescriptor(
            name="mttz",
            handler=_bind_args("mttz", "y", "z"),
            parameters=(
                ParameterSpec("y", _to_float),
                ParameterSpec("z", _to_float),
            ),
        ),
        "mttzxy": TaskDescriptor(
            name="mttzxy",
            handler=_bind_args("mttzxy", "dz", "dx", "dy"),
            parameters=(
                ParameterSpec("dz", _to_float),
                ParameterSpec("dx", _to_float),
                ParameterSpec("dy", _to_float),
            ),
        ),
        "setp": TaskDescriptor(
            name="setp",
            handler=_bind_no_args("setp"),
            parameters=(),
        ),
        "back": TaskDescriptor(
            name="back",
            handler=_bind_no_args("back"),
            parameters=(),
        ),
        "backy": TaskDescriptor(
            name="backy",
            handler=_bind_no_args("backy"),
            parameters=(),
        ),
        "pow": TaskDescriptor(
            name="pow",
            handler=_bind_direct("pow"),
            parameters=(ParameterSpec("value", _to_int),),
            store_as_mapping=False,
        ),
        "line": TaskDescriptor(
            name="line",
            handler=_bind_args("line", "ys_dep"),
            parameters=(ParameterSpec("ys_dep", _to_float),),
        ),
        "graball": TaskDescriptor(
            name="graball",
            handler=_bind_args("graball", "color", "depth", "timeout", "pr", "k", "step_time"),
            parameters=(
                ParameterSpec("color", _to_str),
                ParameterSpec("depth", _to_float),
                ParameterSpec("timeout", _to_float),
                ParameterSpec("pr", _to_float),
                ParameterSpec("k", _to_float),
                ParameterSpec("step_time", _to_float),
            ),
        ),
        "thrball": TaskDescriptor(
            name="thrball",
            handler=_bind_args("thrball", "pr", "timeout", "k", "step_time"),
            parameters=(
                ParameterSpec("pr", _to_float),
                ParameterSpec("timeout", _to_float),
                ParameterSpec("k", _to_float),
                ParameterSpec("step_time", _to_float),
            ),
        ),
        "pass_door": TaskDescriptor(
            name="pass_door",
            handler=_bind_args("pass_door", "num"),
            parameters=(ParameterSpec("num", _to_int),),
        ),
        "mttpos": TaskDescriptor(
            name="mttpos",
            handler=_bind_args("mttpos", "x", "y", "z", "rz", "dy"),
            parameters=(
                ParameterSpec("x", _to_float),
                ParameterSpec("y", _to_float),
                ParameterSpec("z", _to_float),
                ParameterSpec("rz", _to_float),
                ParameterSpec("dy", _to_float),
            ),
        ),
        "mttzpos_amend": TaskDescriptor(
            name="mttzpos_amend",
            handler=_bind_args("mttzpos_amend", "x", "y", "z", "dy"),
            parameters=(
                ParameterSpec("x", _to_float),
                ParameterSpec("y", _to_float),
                ParameterSpec("z", _to_float),
                ParameterSpec("dy", _to_float),
            ),
        ),
        "mttpos_amend": TaskDescriptor(
            name="mttpos_amend",
            handler=_bind_args("mttpos_amend", "x", "y", "z", "rz", "dy"),
            parameters=(
                ParameterSpec("x", _to_float),
                ParameterSpec("y", _to_float),
                ParameterSpec("z", _to_float),
                ParameterSpec("rz", _to_float),
                ParameterSpec("dy", _to_float),
            ),
        ),
        "mttzpos_": TaskDescriptor(
            name="mttzpos_",
            handler=_bind_args("mttzpos", "x", "y", "z", "dy"),
            parameters=(
                ParameterSpec("x", _to_float),
                ParameterSpec("y", _to_float),
                ParameterSpec("z", _to_float),
                ParameterSpec("dy", _to_float),
            ),
        ),
        "delay": TaskDescriptor(
            name="delay",
            handler=_bind_direct("delay"),
            parameters=(ParameterSpec("seconds", _to_float),),
            store_as_mapping=False,
        ),
        "led": TaskDescriptor(
            name="led",
            handler=_bind_args("led", "led0", "led1"),
            parameters=(
                ParameterSpec("led0", _to_int),
                ParameterSpec("led1", _to_int),
            ),
        ),
        "grab_golf": TaskDescriptor(
            name="grab_golf",
            handler=_bind_args("grab_golf", "kind", "dx", "dy", "down_depth", "up_depth"),
            parameters=(
                ParameterSpec("kind", _to_str),
                ParameterSpec("dx", _to_float),
                ParameterSpec("dy", _to_float),
                ParameterSpec("down_depth", _to_float),
                ParameterSpec("up_depth", _to_float),
            ),
        ),
        "put_t": TaskDescriptor(
            name="put_t",
            handler=_bind_args("put_t", "num", "dy", "dz"),
            parameters=(
                ParameterSpec("num", _to_int),
                ParameterSpec("dy", _to_float),
                ParameterSpec("dz", _to_float),
            ),
        ),
        "strike_ball": TaskDescriptor(
            name="strike_ball",
            handler=_bind_args("strike_ball", "num"),
            parameters=(ParameterSpec("num", _to_int),),
        ),
        "strike_ball3": TaskDescriptor(
            name="strike_ball3",
            handler=_bind_args("strike_ball3", "num1", "num2", "num3"),
            parameters=(
                ParameterSpec("num1", _to_int),
                ParameterSpec("num2", _to_int),
                ParameterSpec("num3", _to_int),
            ),
        ),
        "line_qd": TaskDescriptor(
            name="line_qd",
            handler=_bind_no_args("line_qd"),
            parameters=(),
        ),
        "endfloat": TaskDescriptor(
            name="endfloat",
            handler=_bind_no_args("endfloat"),
            parameters=(),
        ),
    }


class TaskRegistry:
    """Holds all available task descriptors and provides helpers."""

    def __init__(self, descriptors: Optional[Dict[str, TaskDescriptor]] = None) -> None:
        self._descriptors = descriptors or _build_default_registry()

    def get(self, name: str) -> Optional[TaskDescriptor]:
        return self._descriptors.get(name)

    def names(self) -> Iterable[str]:
        return self._descriptors.keys()

    def parse_cli_task(self, command: str) -> Optional[Dict[str, Any]]:
        parts = command.strip().split()
        if not parts:
            return None

        name, args = parts[0], parts[1:]
        descriptor = self.get(name)
        if not descriptor:
            print(f"Warn: 未知任务 {name}")
            return None

        try:
            payload = descriptor.build_payload(args)
        except ValueError as exc:
            print(f"Warn: 参数错误 - {exc}")
            return None

        return {
            "name": name,
            "params": payload,
        }


class TaskRunner:
    """Executes tasks using a registry and a bound node."""

    def __init__(self, node: legacy.CoreNode, registry: Optional[TaskRegistry] = None) -> None:
        self._node = node
        self._registry = registry or TaskRegistry()

    def run(self, task: Mapping[str, Any]) -> None:
        name = task.get("name")
        descriptor = self._registry.get(name)
        if not descriptor:
            self._node.get_logger().info(f"Warn:非法任务 {name}")
            return
        try:
            payload = descriptor.normalise_payload(task.get("params"))
            descriptor.execute(self._node, payload)
        except Exception as exc:  # pragma: no cover - defensive logging
            self._node.get_logger().error(f"任务 {name} 执行失败: {exc}")

    def run_sequence(self, tasks: Sequence[Mapping[str, Any]], start_index: int = 0) -> None:
        for index in range(start_index, len(tasks)):
            task = tasks[index]
            name = task.get("name", "<unknown>")
            self._node.get_logger().info(
                f"Info:=========执行第 {index:d} 步任务 {name}========="
            )
            self.run(task)
            self._node.get_logger().info(
                f"Info:=========完成第 {index:d} 步任务 {name}========="
            )

    @property
    def registry(self) -> TaskRegistry:
        return self._registry


class CoreNode(legacy.CoreNode):
    """Drop-in replacement node that reuses legacy behaviour with modern tooling."""

    def __init__(self, name: str, opt: argparse.Namespace):
        super().__init__(name, opt)
        self.task_runner = TaskRunner(self)

    def run(self, task: Mapping[str, Any]) -> None:  # type: ignore[override]
        """Override legacy ``run`` to use the task runner registry."""
        self.task_runner.run(task)


def load_actions(path: str) -> Dict[str, Any]:
    with open(path, "r", encoding="utf-8") as stream:
        return json.load(stream)


def save_actions(data: Mapping[str, Any], path: str) -> None:
    print(f"所保存的任务:\n{data}\n")
    with open(path, "w", encoding="utf-8") as stream:
        json.dump(data, stream, ensure_ascii=False, indent=2)


def get_act(registry: TaskRegistry) -> Optional[Dict[str, Any]]:
    command = input("请输入任务指令: ")
    return registry.parse_cli_task(command)


def commom_loop(node: CoreNode, opt: argparse.Namespace) -> None:
    tasks_doc = load_actions(opt.data_path[0] + "uv_tasks.json")
    tasks = tasks_doc.get("tasks", [])

    node.start()
    node.task_runner.run_sequence(tasks)
    node.end()


def _print_task_list(tasks: Sequence[Mapping[str, Any]]) -> None:
    for index, task in enumerate(tasks):
        print(f"编号:   {index}")
        print(f"任务名: {task.get('name')}")
        print(f"参数:   {task.get('params')}")


def debug_loop(node: CoreNode, opt: argparse.Namespace) -> None:
    node.get_logger().info("Info:进入调试模式")

    registry = node.task_runner.registry
    tasklist = load_actions(opt.data_path[0] + "uv_tasks.json")
    tasks = tasklist.setdefault("tasks", [])

    help_path = Path(opt.data_path[0] + "help.txt")
    help_text = help_path.read_text(encoding="utf-8") if help_path.exists() else ""

    node.start()

    while True:
        node.get_logger().info("Info:等待指令输入")
        command = input("请输入调试指令: \n").strip()
        if not command:
            continue

        parts = command.split()
        head = parts[0]

        if head == "help":
            print(help_text)
            continue

        if head == "act":
            task = get_act(registry)
            if task is None:
                node.get_logger().info("Warn:非法任务")
                continue
            node.get_logger().info(f"Info:=========执行任务: {task['name']}=========")
            node.run(task)
            node.get_logger().info(f"Info:=========完成任务: {task['name']}=========")
            continue

        if head != "task":
            node.get_logger().info("Warn:非法指令")
            continue

        if len(parts) < 2:
            node.get_logger().info("Warn:非法指令")
            continue

        action = parts[1]

        if action == "run":
            if len(parts) == 2:
                node.task_runner.run_sequence(tasks, start_index=0)
            elif len(parts) == 3:
                idx = int(parts[2])
                if idx < 0 or idx >= len(tasks):
                    node.get_logger().info("Warn: 所请求任务不在列表范围内！")
                else:
                    node.task_runner.run_sequence(tasks, start_index=idx)
            else:
                node.get_logger().info("Warn:非法指令")
            continue

        if action == "runonly" and len(parts) == 3:
            idx = int(parts[2])
            if idx < 0 or idx >= len(tasks):
                node.get_logger().info("Warn: 所请求任务不在列表范围内！")
            else:
                task = tasks[idx]
                node.get_logger().info(f"Info:=========执行任务: {task['name']}=========")
                node.run(task)
                node.get_logger().info(f"Info:=========完成任务: {task['name']}=========")
            continue

        if action == "add":
            if len(parts) == 3:
                idx = int(parts[2])
                if idx < 0 or idx > len(tasks):
                    node.get_logger().info("Warn: 所请求任务不在列表范围内！")
                    continue
                task = get_act(registry)
                if task:
                    tasks.insert(idx, task)
                    save_actions(tasklist, opt.data_path[0] + "uv_tasks.json")
            elif len(parts) == 2:
                task = get_act(registry)
                if task:
                    tasks.append(task)
                    save_actions(tasklist, opt.data_path[0] + "uv_tasks.json")
            else:
                node.get_logger().info("Warn:非法指令")
            continue

        if action == "del" and len(parts) == 3:
            idx = int(parts[2])
            if idx < 0 or idx >= len(tasks):
                node.get_logger().info("Warn: 所请求任务不在列表范围内！")
            else:
                tasks.pop(idx)
                save_actions(tasklist, opt.data_path[0] + "uv_tasks.json")
            continue

        if action == "clear" and len(parts) == 2:
            tasks.clear()
            save_actions(tasklist, opt.data_path[0] + "uv_tasks.json")
            continue

        if action == "list" and len(parts) == 2:
            node.get_logger().info("Info: 打印任务列表")
            _print_task_list(tasks)
            continue

        if action == "mod" and len(parts) == 3:
            idx = int(parts[2])
            if idx < 0 or idx >= len(tasks):
                node.get_logger().info("Warn: 所请求任务不在列表范围内！")
                continue
            task = get_act(registry)
            if task:
                tasks[idx] = task
                save_actions(tasklist, opt.data_path[0] + "uv_tasks.json")
            continue

        node.get_logger().info("Warn:非法指令")


def main(args: Optional[Sequence[str]] = None) -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--front-topic",
        nargs="+",
        type=str,
        default=["front_cam/rectified"],
        help="前视摄像话题",
    )
    parser.add_argument(
        "--down-topic",
        nargs="+",
        type=str,
        default=["down_cam/rectified"],
        help="下视摄像话题",
    )
    parser.add_argument(
        "--data-path",
        nargs="+",
        type=str,
        default=["/home/nvidia/Workspace/Cruise/datas/"],
        help="数据存储路径",
    )
    parser.add_argument(
        "--debug",
        nargs="+",
        type=bool,
        default=False,
        help="是否启用调试模式",
    )

    opt = parser.parse_args(args=args)

    rclpy.init(args=args)

    if opt.debug:
        node = CoreNode("uv_automaton_debug", opt)
        thread = threading.Thread(target=debug_loop, args=(node, opt))
        thread.start()
    else:
        node = CoreNode("uv_automaton", opt)
        thread = threading.Thread(target=commom_loop, args=(node, opt))
        thread.start()

    node.get_logger().info("节点与调度线程成功启动")

    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
