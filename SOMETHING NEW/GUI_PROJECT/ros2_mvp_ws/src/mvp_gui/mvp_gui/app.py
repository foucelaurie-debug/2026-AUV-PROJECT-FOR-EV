"""Application entry point for the ROS2 GUI MVP."""
from __future__ import annotations

import sys

from PyQt6 import QtWidgets

from .gui import MainWindow
from .ros_client import ROSWorker


def main() -> None:
    app = QtWidgets.QApplication(sys.argv)
    ros_worker = ROSWorker()
    ros_worker.start()
    window = MainWindow(worker=ros_worker)
    window.bind_worker_signals()
    window.show()
    exit_code = app.exec()
    if ros_worker.isRunning():
        ros_worker.stop()
    sys.exit(exit_code)


if __name__ == "__main__":
    main()
