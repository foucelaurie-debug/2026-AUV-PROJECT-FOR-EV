# Repository Guidelines

## Project Structure & Module Organization
Work inside `Cruise/`, the ROS 2 workspace. Packages live under `Cruise/src` (uv_ai, uv_hm, uv_vision, uv_control_py, uv_launch_pkg, utils, models). Tests sit beside each package in `test/`; runtime helpers stay in `scripts/run/`, diagnostics in `scripts/test/`, captures in `datas/`. Keep `models/` to pointers or download scripts and store large weights elsewhere. Purge `build/`, `install/`, and `log/` artifacts-they are colcon outputs.

## Build, Test, and Development Commands
Prime dependencies with `rosdep install --from-paths src --ignore-src -r -y`. Build everything via `colcon build --symlink-install`, then source the overlay (`call install\setup.bat` on Windows or `source install/setup.bash`). Use `colcon build --packages-select <pkg>` for tight loops, `ros2 launch uv_launch_pkg launch.py` for integrated bring-up, and `colcon test --event-handlers console_cohesion+` (optionally with `--packages-select`) for automated checks.

## Coding Style & Naming Conventions
Use 4-space indentation, lowercase module names, CapWords classes, and executables prefixed with their package (e.g., `uv_vision` -> `uv_vision_node`). Keep tunables in YAML or helper modules rather than hard-coding. Add type hints and concise docstrings for every ROS topic, service, or parameter. Run `ament_flake8` and `ament_pep257` until clean before committing.

## Testing Guidelines
Write pytest-style files named `test_<feature>.py` inside each package's `test/` folder. Mock hardware whenever possible; otherwise reuse captures from `datas/` or diagnostics from `scripts/test/`. Execute `colcon test --packages-select <pkg>` to reproduce issues and attach `log/latest_test/` snippets to bug reports. Keep tests deterministic so the `console_cohesion` handler stays readable.

## Commit & Pull Request Guidelines
Adopt Conventional Commits (`feat(vision): add depth fusion node`) with <=72-character subjects and explanatory bodies referencing tickets in the footer. Pull requests must summarize the change, list verification commands (`colcon build`, focused `colcon test`, relevant `ros2 launch`), and link evidence for perception updates. Never commit `build/`, `install/`, `log/`, or large binaries; store weight references only.

## Environment & Configuration Tips
Run `scripts/run/permissions.sh` (or the Windows analogue) before connecting new serial hardware. Surface every new parameter both in launch files and mirrored YAML configs so operators can tune without rebuilding. Record external model sources and hashes in PR descriptions, and keep credentials or proprietary captures outside the repo.
