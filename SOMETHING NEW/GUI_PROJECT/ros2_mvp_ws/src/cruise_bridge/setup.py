from setuptools import setup

package_name = "cruise_bridge"

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
    description="ROS2 UDP bridge for streaming telemetry/video and accepting parameter/control commands.",
    license="MIT",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "udp_server = cruise_bridge.udp_server:main",
        ],
    },
)
