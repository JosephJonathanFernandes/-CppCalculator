// Smart Calculator - improved for maintainability and safety
// - Uses modern C++ containers
// - Safer file handling and parsing
// - History persisted to `data/calc_history.txt` (ignored by VCS)

#include "include/calculator.h"
#include <iostream>
#include <limits>
#include <string>

int main() {
    Calculator calc;
    int choice = 0;
    double lastResult = 0.0;
    bool hasLast = false;

    do {
        std::cout << "\n====== Smart Calculator (learning) ======\n";
        std::cout << "Supported operations: + - * / % ^\n";
        std::cout << "1. Perform calculation\n2. View history\n3. Exit\n";
        std::cout << "Enter choice: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice.\n";
            continue;
        }

        if (choice == 1) {
            std::cout << "Enter first number or 'ans': ";
            std::string t1;
            std::cin >> t1;
            double n1 = 0.0;
            if (t1 == "ans" && hasLast) {
                n1 = lastResult;
                std::cout << "Using previous result: " << n1 << '\n';
            } else if (!readNumberFromInput(t1, n1)) {
                std::cout << "Invalid first number input." << std::endl;
                continue;
            }

            std::cout << "Enter operator (+ - * / % ^): ";
            char op{};
            std::cin >> op;

            std::cout << "Enter second number: ";
            std::string t2;
            std::cin >> t2;
            double n2 = 0.0;
            if (!readNumberFromInput(t2, n2)) {
                std::cout << "Invalid second number input." << std::endl;
                continue;
            }

            double result = 0.0;
            std::string err;
            if (calc.performOperation(n1, op, n2, result, err)) {
                std::cout << "Result: " << result << '\n';
                lastResult = result;
                hasLast = true;
            } else {
                std::cout << "Error: " << err << '\n';
            }

        } else if (choice == 2) {
            calc.showHistory(std::cout);
        } else if (choice != 3) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 3);

    std::cout << "Goodbye!\n";
    return 0;
}

