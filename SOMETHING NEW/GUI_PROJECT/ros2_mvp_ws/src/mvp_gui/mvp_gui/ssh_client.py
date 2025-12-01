"""Paramiko helpers for executing SSH commands in background threads."""
from __future__ import annotations

from PyQt6 import QtCore
import paramiko


class SSHCommandWorker(QtCore.QThread):
    """Runs a single SSH command and reports its output via Qt signals."""

    output_ready = QtCore.pyqtSignal(str)
    error_ready = QtCore.pyqtSignal(str)

    def __init__(
        self,
        hostname: str,
        username: str,
        password: str,
        command: str,
        port: int = 22,
    ) -> None:
        super().__init__()
        self.hostname = hostname
        self.username = username
        self.password = password
        self.command = command
        self.port = port

    def run(self) -> None:
        client = paramiko.SSHClient()
        client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        try:
            client.connect(
                hostname=self.hostname,
                username=self.username,
                password=self.password,
                port=self.port,
                look_for_keys=False,
                allow_agent=False,
                timeout=5.0,
            )
            stdin, stdout, stderr = client.exec_command(self.command)
            out_text = stdout.read().decode("utf-8", errors="ignore")
            err_text = stderr.read().decode("utf-8", errors="ignore")
            if out_text:
                self.output_ready.emit(out_text.strip())
            if err_text:
                self.error_ready.emit(err_text.strip())
        except Exception as exc:  # pragma: no cover - network operations
            self.error_ready.emit(str(exc))
        finally:
            client.close()
