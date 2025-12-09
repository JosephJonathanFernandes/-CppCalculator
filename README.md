# Smart Calculator (Learning Project)

Small C++ calculator program intended for learning and demonstration purposes. The project contains a simple CLI calculator that supports + - * / % ^ and persists a short history to `data/calc_history.txt` (ignored by version control).

Key points:
- Modernized C++17 code for clarity and safety.
- Local history saved under `data/` (not checked into Git).
- CI builds via GitHub Actions (see `.github/workflows/ci.yml`).

Build (Linux/macOS) with CMake:

```bash
mkdir -p build && cd build
## Smart Calculator (Learning Project)

Smart Calculator is a small, intentionally simple C++ CLI program used for learning and demonstration. It supports the following operations: `+`, `-`, `*`, `/`, `%` (integer modulus), and `^` (exponentiation). A short history of recent calculations is stored to `calc_history.txt` (kept out of version control).

Status
- Purpose: learning / demo project (suitable for teaching and experimentation).
- Language: C++17
- CI: GitHub Actions builds the project and runs tests.

Highlights
- Small, self-contained codebase to learn modern C++ patterns (RAII, small-library layout).
- Unit tests + a lightweight test runner for quick verification.
- CMake-based build for standard development workflows.

Quick start — build with CMake (recommended)

On Windows (PowerShell):

```powershell
mkdir build
cmake -S . -B build
cmake --build build --config Release
# executable will be at build\Release\smart_calculator.exe (MSVC) or build\smart_calculator (other generators)
.
```

On Linux/macOS:

```bash
mkdir -p build && cmake -S . -B build
cmake --build build --config Release
./build/smart_calculator
```

Quick alternative — compile directly with g++ (no CMake)

```powershell
g++ -std=c++17 -Iinclude src/calculator.cpp smart_calculator.cpp -O2 -o smart_calculator.exe
.\smart_calculator.exe
```

Run tests (no CMake required)
- Lightweight test runner (dependency-free):

```powershell
g++ -std=c++17 -Iinclude src/calculator.cpp tests/simple_tests.cpp -O2 -o run_tests.exe
.\run_tests.exe
```

About tests
- There is also a Catch2-based test target in `CMakeLists.txt` (requires network access to FetchContent or vendored Catch2).

Contributing & Code of Conduct
- This repository is marked as a learning project — contributions are welcome. See `CONTRIBUTING.md` and `CODE_OF_CONDUCT.md` for guidance.

License
- MIT — see `LICENSE`.

If you'd like I can add a CI badge, code coverage badge, or an example walkthrough. Pull requests should target `main` and the branch naming convention is `feature/` or `chore/` for non-feature work.
