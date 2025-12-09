#!/usr/bin/env pwsh
Write-Host "Building and running lightweight tests using g++"
if (-not (Get-Command g++ -ErrorAction SilentlyContinue)) {
    Write-Error "g++ not found in PATH. Please install MinGW or G++ toolchain and try again."
    exit 1
}

$exe = "run_tests.exe"
g++ -std=c++17 -Iinclude src/calculator.cpp tests/simple_tests.cpp -O2 -o $exe
if ($LASTEXITCODE -ne 0) { Write-Error "Compilation failed"; exit $LASTEXITCODE }

.\$exe
exit $LASTEXITCODE