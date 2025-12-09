# 🧮 C++ CLI Calculator

A simple yet powerful **command-line calculator** written in C++ that supports:

- Basic arithmetic: `+`, `-`, `*`, `/`
- Modulus: `%` (integer only)
- Exponentiation: `^`
- History tracking of up to 100 calculations
- Reuse of previous result using `ans`
- Persistent history saved to a text file

---

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
## 📦 Features

- Perform calculations with two numbers and an operator
- Use `ans` to reference the result of the last calculation
- View past calculations at any time
- Saves calculation history to `calc_history.txt` automatically
- Input validation to handle bad data and divide-by-zero

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



