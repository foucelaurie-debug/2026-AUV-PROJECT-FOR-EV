from setuptools import setup

package_name = "mvp_talker"

setup(
    name=package_name,
    version="0.1.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="AUV Dev Team",
    maintainer_email="dev@example.com",
    description="Parameter-driven talker node used by the ROS2 GUI MVP",
    license="MIT",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "parameter_talker = mvp_talker.parameter_talker:main",
        ],
    },
)
