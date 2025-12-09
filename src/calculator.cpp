// calculator.cpp - implementation for Calculator
#include "../include/calculator.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
#include <sstream>
#include <iomanip>

static constexpr std::size_t MAX_HISTORY = 100;
static const std::string HISTORY_PATH = "calc_history.txt";

struct Calculator::Impl {
    std::vector<Calculation> history;
    Impl() { history.reserve(64); }
};

Calculator::Calculator() : pimpl_(new Impl()) {
    // load history
    std::ifstream ifs(HISTORY_PATH);
    if (!ifs) return;
    std::string line;
    while (std::getline(ifs, line) && pimpl_->history.size() < MAX_HISTORY) {
        Calculation c;
        std::istringstream iss(line);
        if (iss >> c.num1 >> c.op >> c.num2 >> c.result) pimpl_->history.push_back(c);
    }
}

Calculator::~Calculator() {
    // save history
    std::ofstream ofs(HISTORY_PATH, std::ios::trunc);
    if (!ofs) return;
    for (const auto& c : pimpl_->history) ofs << std::setprecision(12) << c.num1 << ' ' << c.op << ' ' << c.num2 << ' ' << c.result << '\n';
    delete pimpl_;
}

bool Calculator::performOperation(double num1, char op, double num2, double& outResult, std::string& err) {
    err.clear();
    switch (op) {
        case '+': outResult = num1 + num2; break;
        case '-': outResult = num1 - num2; break;
        case '*': outResult = num1 * num2; break;
        case '/':
            if (num2 == 0.0) { err = "Division by zero"; return false; }
            outResult = num1 / num2; break;
        case '%':
            if (std::floor(num1) != num1 || std::floor(num2) != num2) { err = "Modulus requires integer operands"; return false; }
            if (static_cast<long long>(num2) == 0) { err = "Modulus by zero"; return false; }
            outResult = static_cast<long long>(static_cast<long long>(num1) % static_cast<long long>(num2));
            break;
        case '^': outResult = std::pow(num1, num2); break;
        default: err = "Invalid operator"; return false;
    }

    if (pimpl_->history.size() < MAX_HISTORY) pimpl_->history.push_back({num1, num2, outResult, op});
    return true;
}

void Calculator::showHistory(std::ostream& os) const {
    if (pimpl_->history.empty()) { os << "No calculations yet!\n"; return; }
    os << "\nCalculation History:\n";
    os << "-----------------------------\n";
    for (const auto& c : pimpl_->history) os << c.num1 << ' ' << c.op << ' ' << c.num2 << " = " << c.result << '\n';
    os << "-----------------------------\n";
}

bool readNumberFromInput(const std::string& token, double& out) {
    try {
        size_t idx = 0;
        out = std::stod(token, &idx);
        return idx == token.size();
    } catch (...) { return false; }
}
