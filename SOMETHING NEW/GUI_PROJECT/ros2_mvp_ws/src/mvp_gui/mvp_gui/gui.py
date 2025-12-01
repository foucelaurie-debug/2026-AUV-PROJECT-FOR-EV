"""PyQt6 GUI for the ROS2 cross-platform MVP."""
from __future__ import annotations

from functools import partial
from typing import Any, Dict, List, Optional

from PyQt6 import QtCore, QtWidgets

from .ssh_client import SSHCommandWorker


class ParametersTab(QtWidgets.QWidget):
    """Dynamic parameter editor bound to a ROSWorker."""

    def __init__(self, worker, parent=None) -> None:
        super().__init__(parent)
        self._worker = worker
        self._param_widgets: Dict[str, QtWidgets.QWidget] = {}
        self._target_node = "/parameter_talker"
        self._build_ui()

    def _build_ui(self) -> None:
        layout = QtWidgets.QVBoxLayout(self)
        form_layout = QtWidgets.QHBoxLayout()
        self._node_input = QtWidgets.QLineEdit(self._target_node)
        self._connect_button = QtWidgets.QPushButton("Connect")
        self._connect_button.clicked.connect(self._on_connect_clicked)
        form_layout.addWidget(QtWidgets.QLabel("节点:"))
        form_layout.addWidget(self._node_input)
        form_layout.addWidget(self._connect_button)
        layout.addLayout(form_layout)

        self._scroll_area = QtWidgets.QScrollArea()
        self._scroll_area.setWidgetResizable(True)
        self._param_container = QtWidgets.QWidget()
        self._form_layout = QtWidgets.QFormLayout(self._param_container)
        self._scroll_area.setWidget(self._param_container)
        layout.addWidget(self._scroll_area)

    def _on_connect_clicked(self) -> None:
        self._target_node = self._node_input.text().strip() or "/parameter_talker"
        self._worker.request_parameter_snapshot(self._target_node)

    def populate_parameters(self, params: Dict[str, Any]) -> None:
        # Clear previous widgets
        while self._form_layout.count():
            item = self._form_layout.takeAt(0)
            widget = item.widget()
            if widget is not None:
                widget.deleteLater()
        self._param_widgets.clear()
        for name, value in params.items():
            widget = self._create_widget(name, value)
            if widget:
                self._form_layout.addRow(QtWidgets.QLabel(name), widget)
                self._param_widgets[name] = widget

    def _create_widget(self, name: str, value: Any) -> Optional[QtWidgets.QWidget]:
        if isinstance(value, bool):
            checkbox = QtWidgets.QCheckBox()
            checkbox.setChecked(value)
            checkbox.stateChanged.connect(
                partial(self._on_param_changed, name, checkbox, "bool")
            )
            return checkbox
        if isinstance(value, float):
            spinbox = QtWidgets.QDoubleSpinBox()
            spinbox.setDecimals(2)
            spinbox.setRange(0.0, 100.0)
            spinbox.setValue(value)
            spinbox.valueChanged.connect(
                partial(self._on_param_changed, name, spinbox, "float")
            )
            return spinbox
        if isinstance(value, int):
            spinbox = QtWidgets.QSpinBox()
            spinbox.setRange(-1000, 1000)
            spinbox.setValue(value)
            spinbox.valueChanged.connect(
                partial(self._on_param_changed, name, spinbox, "int")
            )
            return spinbox
        if isinstance(value, str):
            line_edit = QtWidgets.QLineEdit(value)
            line_edit.textChanged.connect(
                partial(self._on_param_changed, name, line_edit, "str")
            )
            return line_edit
        return None

    def _on_param_changed(self, name: str, widget: QtWidgets.QWidget, value_type: str) -> None:
        if value_type == "bool":
            value = bool(widget.isChecked())  # type: ignore[union-attr]
        elif value_type == "float":
            value = float(widget.value())  # type: ignore[union-attr]
        elif value_type == "int":
            value = int(widget.value())  # type: ignore[union-attr]
        else:
            value = str(widget.text())  # type: ignore[union-attr]
        self._worker.push_parameter_update(self._target_node, name, value)


class TopicViewerTab(QtWidgets.QWidget):
    """Simple subscriber tab for monitoring a text topic."""

    def __init__(self, worker, parent=None) -> None:
        super().__init__(parent)
        self._worker = worker
        self._build_ui()

    def _build_ui(self) -> None:
        layout = QtWidgets.QVBoxLayout(self)
        form_layout = QtWidgets.QHBoxLayout()
        self._topic_input = QtWidgets.QLineEdit("/mvp/data")
        self._subscribe_button = QtWidgets.QPushButton("Subscribe")
        self._subscribe_button.clicked.connect(self._on_subscribe)
        form_layout.addWidget(QtWidgets.QLabel("话题:"))
        form_layout.addWidget(self._topic_input)
        form_layout.addWidget(self._subscribe_button)
        layout.addLayout(form_layout)

        self._output = QtWidgets.QTextEdit()
        self._output.setReadOnly(True)
        layout.addWidget(self._output)

    def _on_subscribe(self) -> None:
        topic = self._topic_input.text().strip() or "/mvp/data"
        self._worker.subscribe_to_topic(topic)

    def append_message(self, text: str) -> None:
        self._output.append(text)


class RemoteTerminalTab(QtWidgets.QWidget):
    """Executes SSH commands in worker threads."""

    def __init__(self, parent=None) -> None:
        super().__init__(parent)
        self._active_workers: List[SSHCommandWorker] = []
        self._build_ui()

    def _build_ui(self) -> None:
        layout = QtWidgets.QVBoxLayout(self)
        grid = QtWidgets.QGridLayout()
        self._ip_input = QtWidgets.QLineEdit("192.168.16.151")
        self._user_input = QtWidgets.QLineEdit("auv")
        self._password_input = QtWidgets.QLineEdit()
        self._password_input.setEchoMode(QtWidgets.QLineEdit.EchoMode.Password)
        grid.addWidget(QtWidgets.QLabel("IP:"), 0, 0)
        grid.addWidget(self._ip_input, 0, 1)
        grid.addWidget(QtWidgets.QLabel("用户名:"), 1, 0)
        grid.addWidget(self._user_input, 1, 1)
        grid.addWidget(QtWidgets.QLabel("密码:"), 2, 0)
        grid.addWidget(self._password_input, 2, 1)
        layout.addLayout(grid)

        command_layout = QtWidgets.QHBoxLayout()
        self._command_input = QtWidgets.QLineEdit("ls -l")
        self._execute_button = QtWidgets.QPushButton("Execute")
        self._execute_button.clicked.connect(self._execute_command)
        command_layout.addWidget(self._command_input)
        command_layout.addWidget(self._execute_button)
        layout.addLayout(command_layout)

        self._output = QtWidgets.QTextEdit()
        self._output.setReadOnly(True)
        layout.addWidget(self._output)

    def _execute_command(self) -> None:
        command = self._command_input.text().strip()
        if not command:
            return
        hostname = self._ip_input.text().strip()
        username = self._user_input.text().strip()
        password = self._password_input.text()
        self._output.append(f"> {command}")
        worker = SSHCommandWorker(hostname, username, password, command)
        worker.output_ready.connect(self._append_output)
        worker.error_ready.connect(self._append_output)
        worker.finished.connect(partial(self._cleanup_worker, worker))
        self._active_workers.append(worker)
        worker.start()

    def _append_output(self, text: str) -> None:
        if text:
            self._output.append(text)

    def _cleanup_worker(self, worker: SSHCommandWorker) -> None:
        if worker in self._active_workers:
            self._active_workers.remove(worker)
        worker.deleteLater()


class MainWindow(QtWidgets.QMainWindow):
    """Main tabbed GUI window."""

    def __init__(self, worker, parent=None) -> None:
        super().__init__(parent)
        self._worker = worker
        self.setWindowTitle("ROS2 Cross-Platform GUI MVP")
        self.resize(900, 600)
        self._build_ui()

    def _build_ui(self) -> None:
        tabs = QtWidgets.QTabWidget()
        self.parameters_tab = ParametersTab(self._worker)
        self.topic_tab = TopicViewerTab(self._worker)
        self.terminal_tab = RemoteTerminalTab()
        tabs.addTab(self.parameters_tab, "ROS2 Parameters")
        tabs.addTab(self.topic_tab, "Topic Viewer")
        tabs.addTab(self.terminal_tab, "Remote Terminal")
        self.setCentralWidget(tabs)

    def bind_worker_signals(self) -> None:
        self._worker.parameters_ready.connect(self.parameters_tab.populate_parameters)
        self._worker.topic_message.connect(self.topic_tab.append_message)
        self._worker.ros_feedback.connect(self.statusBar().showMessage)

    def closeEvent(self, event) -> None:  # type: ignore[override]
        self._worker.stop()
        super().closeEvent(event)

