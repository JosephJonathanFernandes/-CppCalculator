# Smart Calculator (Learning Project)

Small C++ calculator program intended for learning and demonstration purposes. The project contains a simple CLI calculator that supports + - * / % ^ and persists a short history to `data/calc_history.txt` (ignored by version control).

Key points:
- Modernized C++17 code for clarity and safety.
- Local history saved under `data/` (not checked into Git).
- CI builds via GitHub Actions (see `.github/workflows/ci.yml`).

Build (Linux/macOS) with CMake:

```bash
mkdir -p build && cd build
cmake ..
cmake --build . --config Release
./smart_calculator
```

On Windows (PowerShell):

```powershell
mkdir build; cd build; cmake ..; cmake --build . --config Release; .\Release\smart_calculator.exe
```

This repository is marked as a learning project. Contributions welcome — see `CONTRIBUTING.md`.
