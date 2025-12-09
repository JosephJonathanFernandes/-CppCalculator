// Lightweight tests without external test framework
#include "../include/calculator.h"
#include <iostream>
#include <string>
#include <cmath>

int main() {
    Calculator calc;
    double out{};
    std::string err;
    int failures = 0;

    // addition
    if (!calc.performOperation(2.0, '+', 3.0, out, err) || std::abs(out - 5.0) > 1e-9) {
        std::cerr << "FAIL: 2 + 3 != 5 (got " << out << ")\n";
        failures++;
    }

    // subtraction
    if (!calc.performOperation(10.0, '-', 4.0, out, err) || std::abs(out - 6.0) > 1e-9) {
        std::cerr << "FAIL: 10 - 4 != 6\n";
        failures++;
    }

    // multiplication
    if (!calc.performOperation(3.0, '*', 4.0, out, err) || std::abs(out - 12.0) > 1e-9) {
        std::cerr << "FAIL: 3 * 4 != 12\n";
        failures++;
    }

    // exponent
    if (!calc.performOperation(9.0, '^', 2.0, out, err) || std::abs(out - 81.0) > 1e-9) {
        std::cerr << "FAIL: 9 ^ 2 != 81\n";
        failures++;
    }

    // division by zero
    if (calc.performOperation(1.0, '/', 0.0, out, err)) {
        std::cerr << "FAIL: division by zero should fail\n";
        failures++;
    }

    // modulus integer
    if (!calc.performOperation(10.0, '%', 3.0, out, err) || std::abs(out - (10 % 3)) > 1e-9) {
        std::cerr << "FAIL: 10 % 3 != " << (10 % 3) << "\n";
        failures++;
    }

    // modulus non-integer
    if (calc.performOperation(3.5, '%', 2.0, out, err)) {
        std::cerr << "FAIL: modulus with non-integer should fail\n";
        failures++;
    }

    if (failures == 0) {
        std::cout << "All tests passed\n";
    } else {
        std::cout << failures << " test(s) failed\n";
    }

    return failures == 0 ? 0 : 1;
}
