import json
import socket
import sys
import threading
import time
from typing import Optional

import cv2
import numpy as np
from PyQt6 import QtCore, QtGui, QtWidgets


CONTROL_PORT = 8000
VIDEO_PORT = 8001


class VideoThread(QtCore.QThread):
    frame_received = QtCore.pyqtSignal(QtGui.QImage)
    message = QtCore.pyqtSignal(str)

    def __init__(self, bind_ip: str = "0.0.0.0", port: int = VIDEO_PORT) -> None:
        super().__init__()
        self.bind_ip = bind_ip
        self.port = port
        self._running = False
        self.sock: Optional[socket.socket] = None

    def run(self) -> None:
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.sock.bind((self.bind_ip, self.port))
        self.sock.settimeout(1.0)
        self._running = True
        while self._running:
            try:
                data, _ = self.sock.recvfrom(70000)
            except socket.timeout:
                continue
            except OSError:
                break
            try:
                frame = self._decode_frame(data)
                if frame is not None:
                    self.frame_received.emit(frame)
            except Exception as exc:  # noqa: BLE001
                self.message.emit(f"Video decode error: {exc}")
        if self.sock:
            self.sock.close()

    @staticmethod
    def _decode_frame(data: bytes) -> Optional[QtGui.QImage]:
        arr = np.frombuffer(data, dtype=np.uint8)
        bgr = cv2.imdecode(arr, cv2.IMREAD_COLOR)
        if bgr is None:
            return None
        rgb = cv2.cvtColor(bgr, cv2.COLOR_BGR2RGB)
        h, w, _ = rgb.shape
        return QtGui.QImage(rgb.data, w, h, 3 * w, QtGui.QImage.Format.Format_RGB888).copy()

    def stop(self) -> None:
        self._running = False
        if self.sock:
            try:
                self.sock.close()
            except Exception:
                pass


class StatusThread(QtCore.QThread):
    status_received = QtCore.pyqtSignal(dict)
    message = QtCore.pyqtSignal(str)

    def __init__(self, bind_ip: str = "0.0.0.0", port: int = CONTROL_PORT) -> None:
        super().__init__()
        self.bind_ip = bind_ip
        self.port = port
        self._running = False
        self.sock: Optional[socket.socket] = None

    def run(self) -> None:
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.sock.bind((self.bind_ip, self.port))
        self.sock.settimeout(1.0)
        self._running = True
        while self._running:
            try:
                data, _ = self.sock.recvfrom(65535)
            except socket.timeout:
                continue
            except OSError:
                break
            try:
                payload = json.loads(data.decode("utf-8"))
                self.status_received.emit(payload)
            except Exception:
                self.message.emit("Status packet malformed; skipped.")
        if self.sock:
            self.sock.close()

    def stop(self) -> None:
        self._running = False
        if self.sock:
            try:
                self.sock.close()
            except Exception:
                pass


class DashboardWindow(QtWidgets.QWidget):
    def __init__(self) -> None:
        super().__init__()
        self.setWindowTitle("AUV UDP Dashboard")
        self.target_ip = "192.168.16.151"
        self.video_thread: Optional[VideoThread] = None
        self.status_thread: Optional[StatusThread] = None
        self.send_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self._build_ui()

    def _build_ui(self) -> None:
        layout = QtWidgets.QGridLayout(self)

        # Connection row
        layout.addWidget(QtWidgets.QLabel("AGX IP:"), 0, 0)
        self.ip_edit = QtWidgets.QLineEdit(self.target_ip)
        layout.addWidget(self.ip_edit, 0, 1)
        self.connect_btn = QtWidgets.QPushButton("Connect")
        self.connect_btn.clicked.connect(self._on_connect)
        layout.addWidget(self.connect_btn, 0, 2)

        # Video
        self.video_label = QtWidgets.QLabel("Waiting for video...")
        self.video_label.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
        self.video_label.setMinimumSize(640, 360)
        layout.addWidget(self.video_label, 1, 0, 1, 3)

        # Telemetry
        telemetry_box = QtWidgets.QGroupBox("Telemetry")
        t_layout = QtWidgets.QFormLayout()
        self.status_value = QtWidgets.QLabel("disconnected")
        self.depth_value = QtWidgets.QLabel("-")
        self.att_value = QtWidgets.QLabel("-")
        self.batt_value = QtWidgets.QLabel("-")
        t_layout.addRow("Heartbeat:", self.status_value)
        t_layout.addRow("Depth (m):", self.depth_value)
        t_layout.addRow("Attitude (r/p/y):", self.att_value)
        t_layout.addRow("Battery (V):", self.batt_value)
        telemetry_box.setLayout(t_layout)
        layout.addWidget(telemetry_box, 2, 0, 1, 3)

        # Tuning panel
        tuning_box = QtWidgets.QGroupBox("Parameter Tuning")
        tune_layout = QtWidgets.QGridLayout()
        self.node_combo = QtWidgets.QComboBox()
        self.node_combo.setEditable(True)
        self.node_combo.addItems(["uv_hm", "uv_vision", "uv_ai"])
        self.param_combo = QtWidgets.QComboBox()
        self.param_combo.setEditable(True)
        self.param_combo.addItems(["pid_p", "pid_i", "pid_d", "exposure"])
        self.value_slider = QtWidgets.QSlider(QtCore.Qt.Orientation.Horizontal)
        self.value_slider.setMinimum(-1000)
        self.value_slider.setMaximum(1000)
        self.value_slider.setValue(0)
        self.value_spin = QtWidgets.QDoubleSpinBox()
        self.value_spin.setRange(-100.0, 100.0)
        self.value_spin.setSingleStep(0.1)
        self.value_spin.setDecimals(2)
        self.value_spin.setValue(0.0)
        self.value_slider.valueChanged.connect(self._slider_changed)
        self.value_spin.valueChanged.connect(self._spin_changed)
        apply_btn = QtWidgets.QPushButton("Apply")
        apply_btn.clicked.connect(self._send_parameter_update)
        tune_layout.addWidget(QtWidgets.QLabel("Node"), 0, 0)
        tune_layout.addWidget(self.node_combo, 0, 1)
        tune_layout.addWidget(QtWidgets.QLabel("Param"), 1, 0)
        tune_layout.addWidget(self.param_combo, 1, 1)
        tune_layout.addWidget(self.value_slider, 2, 0, 1, 2)
        tune_layout.addWidget(self.value_spin, 3, 0, 1, 2)
        tune_layout.addWidget(apply_btn, 4, 0, 1, 2)
        tuning_box.setLayout(tune_layout)
        layout.addWidget(tuning_box, 3, 0, 1, 3)

        # Command/log area
        cmd_box = QtWidgets.QGroupBox("Command & Log")
        cmd_layout = QtWidgets.QVBoxLayout()
        cmd_row = QtWidgets.QHBoxLayout()
        self.cmd_edit = QtWidgets.QLineEdit()
        self.cmd_edit.setPlaceholderText("Command text, e.g., arm or disarm")
        cmd_send_btn = QtWidgets.QPushButton("Send Command")
        cmd_send_btn.clicked.connect(self._send_command)
        cmd_row.addWidget(self.cmd_edit)
        cmd_row.addWidget(cmd_send_btn)
        self.log_area = QtWidgets.QPlainTextEdit()
        self.log_area.setReadOnly(True)
        cmd_layout.addLayout(cmd_row)
        cmd_layout.addWidget(self.log_area)
        cmd_box.setLayout(cmd_layout)
        layout.addWidget(cmd_box, 4, 0, 1, 3)

    def _on_connect(self) -> None:
        self.target_ip = self.ip_edit.text().strip()
        self._start_threads()
        self._send_payload({"action": "ping", "source": "dashboard"})
        self._append_log(f"Connecting to {self.target_ip}:{CONTROL_PORT}")

    def _start_threads(self) -> None:
        if self.video_thread is None:
            self.video_thread = VideoThread()
            self.video_thread.frame_received.connect(self._update_video)
            self.video_thread.message.connect(self._append_log)
            self.video_thread.start()
        if self.status_thread is None:
            self.status_thread = StatusThread()
            self.status_thread.status_received.connect(self._update_status)
            self.status_thread.message.connect(self._append_log)
            self.status_thread.start()

    def _send_payload(self, payload: dict) -> None:
        if not self.target_ip:
            self._append_log("No target IP set.")
            return
        try:
            payload["ts"] = time.time()
            data = json.dumps(payload).encode("utf-8")
            self.send_sock.sendto(data, (self.target_ip, CONTROL_PORT))
            self._append_log(f"Sent: {payload}")
        except Exception as exc:  # noqa: BLE001
            self._append_log(f"Send error: {exc}")

    def _send_parameter_update(self) -> None:
        payload = {
            "action": "set_param",
            "node": self.node_combo.currentText().strip(),
            "param": self.param_combo.currentText().strip(),
            "value": float(self.value_spin.value()),
        }
        self._send_payload(payload)

    def _send_command(self) -> None:
        cmd = self.cmd_edit.text().strip()
        if not cmd:
            return
        self._send_payload({"action": "command", "cmd": cmd})

    def _update_video(self, frame: QtGui.QImage) -> None:
        pixmap = QtGui.QPixmap.fromImage(frame)
        self.video_label.setPixmap(pixmap.scaled(
            self.video_label.width(),
            self.video_label.height(),
            QtCore.Qt.AspectRatioMode.KeepAspectRatio,
        ))

    def _update_status(self, status: dict) -> None:
        self.status_value.setText(time.strftime("%H:%M:%S", time.localtime(status.get("heartbeat", time.time()))))
        depth = status.get("depth")
        self.depth_value.setText(f"{depth:.2f}" if depth is not None else "-")
        att = status.get("attitude") or {}
        self.att_value.setText(
            f"{att.get('roll', 0):.2f}/{att.get('pitch', 0):.2f}/{att.get('yaw', 0):.2f}"
        )
        batt = status.get("battery")
        self.batt_value.setText(f"{batt:.2f}" if batt is not None else "-")
        if "ai" in status and status["ai"] is not None:
            self._append_log(f"AI: {status['ai']}")
        if "last_command" in status and status["last_command"]:
            self._append_log(f"Last cmd: {status['last_command']}")

    def _slider_changed(self, value: int) -> None:
        self.value_spin.blockSignals(True)
        self.value_spin.setValue(value / 10.0)
        self.value_spin.blockSignals(False)

    def _spin_changed(self, value: float) -> None:
        self.value_slider.blockSignals(True)
        self.value_slider.setValue(int(value * 10))
        self.value_slider.blockSignals(False)

    def _append_log(self, text: str) -> None:
        timestamp = time.strftime("%H:%M:%S")
        self.log_area.appendPlainText(f"[{timestamp}] {text}")

    def closeEvent(self, event: QtGui.QCloseEvent) -> None:  # noqa: N802
        if self.video_thread:
            self.video_thread.stop()
            self.video_thread.wait(1000)
        if self.status_thread:
            self.status_thread.stop()
            self.status_thread.wait(1000)
        self.send_sock.close()
        super().closeEvent(event)
        event.accept()


def main() -> None:
    app = QtWidgets.QApplication(sys.argv)
    window = DashboardWindow()
    window.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
