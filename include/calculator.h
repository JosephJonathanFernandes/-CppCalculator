// calculator.h - public API for Calculator
#pragma once

#include <string>
#include <vector>
#include <ostream>

struct Calculation {
    double num1{};
    double num2{};
    double result{};
    char op{};
};

class Calculator {
public:
    Calculator();
    ~Calculator();

    // Perform the operation. Returns true on success; on failure sets err.
    bool performOperation(double num1, char op, double num2, double& outResult, std::string& err);

    // Print short history to given stream
    void showHistory(std::ostream& os) const;

private:
    // PIMPL-ish: keep minimal public surface in header
    struct Impl;
    Impl* pimpl_ = nullptr;
};

// Utility to parse a number token (returns true if full token consumed)
bool readNumberFromInput(const std::string& token, double& out);
