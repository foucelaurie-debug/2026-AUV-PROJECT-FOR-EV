# Repository Guidelines

## Project Structure & Module Organization
- `Cruise/` is the ROS 2 workspace; `src/` hosts the Python packages (`uv_ai`, `uv_hm`, `uv_vision`, `uv_control_py`, `uv_launch_pkg`, `utils`, and `models/`).  
- Colcon outputs (`build/`, `install/`, `log/`) are throwaways; delete them from commits.  
- Deployment helpers sit in `scripts/run/`, diagnostics in `scripts/test/`, and reusable captures in `datas/`; keep large artefacts external.

## Build, Test, and Development Commands
- Prime dependencies with `rosdep install --from-paths src --ignore-src -r -y`.  
- Build via `colcon build --symlink-install`, then source the overlay (`call install\setup.bat` or `source install/setup.bash`).  
- Iterate quickly with `colcon build --packages-select <pkg>` and launch nodes using `ros2 launch uv_launch_pkg launch.py`.  
- Run automated checks through `colcon test --event-handlers console_cohesion+`, scoping packages as needed.

## Coding Style & Naming Conventions
- Use 4-space indentation, lowercase modules, CapWords classes, and keep executables aligned with their package (`uv_capture`, `uv_hmu`, etc.).  
- `ament_flake8` and `ament_pep257` run in CI; clear warnings locally before pushing.  
- Add type hints, docstrings, and descriptive topics/parameters (`/uv/vision/raw_image`).  
- Park tunables in helpers or YAML configs rather than hard-coding them.

## Testing Guidelines
- Expand each package's `test/` folder with `pytest`-style files (`test_<feature>.py`) alongside the existing lint checks.  
- Use `colcon test --packages-select <pkg>` for focused runs and include `log/latest_test/` output in bug reports.  
- Reuse `scripts/test/` patterns and saved captures in `datas/` to reproduce sensor and hardware scenarios.  
- Mock devices whenever possible; fall back to lab trials only when behaviour cannot be simulated.

## Commit & Pull Request Guidelines
- The `.git` folder is stripped here, but we follow Conventional Commits; use `<type>(scope): summary` in the imperative mood (`feat(vision): add depth fusion node`).  
- Keep subjects <=72 characters, add rationale in the body, and link issues or ticket IDs in the footer.  
- PRs should describe the change, list verification commands (`colcon build`, `colcon test`, targeted `ros2 launch`), and attach evidence for perception updates.  
- Request review from the package maintainer noted in `package.xml` and merge only after CI passes.

## Environment & Configuration Tips
- Run `scripts/run/permissions.sh` (or a Windows analogue) before connecting new serial hardware.  
- Store large AI weights outside the repo; keep only pointers in `models/` and note source hashes in your PR.  
- Surface new parameters in launch files and mirrored YAML so operators can tune behaviour without rebuilding.

保持简体中文输出
