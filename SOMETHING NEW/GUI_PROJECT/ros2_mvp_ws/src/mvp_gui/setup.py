from setuptools import setup

package_name = "mvp_gui"

setup(
    name=package_name,
    version="0.1.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=False,
    maintainer="AUV Dev Team",
    maintainer_email="dev@example.com",
    description="PyQt6 GUI for interacting with ROS2 nodes and remote shell commands.",
    license="MIT",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "mvp_gui = mvp_gui.app:main",
        ],
    },
)
