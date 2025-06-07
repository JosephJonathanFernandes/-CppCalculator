#include <iostream>
#include <fstream>
#include <cmath>    // for pow()
#include <limits>   // for numeric_limits

using namespace std;

#define MAX_HISTORY 100
#define HISTORY_FILE "calc_history.txt"

struct Calculation {
    double num1, num2, result;
    char op;
};

class Calculator {
    Calculation history[MAX_HISTORY];
    int historyCount;

public:
    Calculator() : historyCount(0) {
        loadHistory();
    }

    ~Calculator() {
        saveHistory();
    }

    double performOperation(double num1, char op, double num2, bool& valid) {
        valid = true;
        double result = 0;
        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': 
                if (num2 == 0) {
                    cout << "Error: Division by zero!" << endl;
                    valid = false;
                    return 0;
                }
                result = num1 / num2;
                break;
            case '%':
                if (static_cast<int>(num2) == 0) {
                    cout << "Error: Modulus by zero!" << endl;
                    valid = false;
                    return 0;
                }
                result = static_cast<int>(num1) % static_cast<int>(num2);
                break;
            case '^':
                result = pow(num1, num2);
                break;
            default: 
                cout << "Invalid Operator!" << endl;
                valid = false;
                return 0;
        }

        if (valid && historyCount < MAX_HISTORY) {
            history[historyCount] = {num1, num2, result, op};
            historyCount++;
        }

        return result;
    }

    void showHistory() {
        if (historyCount == 0) {
            cout << "No calculations yet!" << endl;
            return;
        }

        cout << "\nCalculation History:\n";
        cout << "-----------------------------\n";
        for (int i = 0; i < historyCount; i++) {
            cout << history[i].num1 << " " << history[i].op << " " << history[i].num2
                 << " = " << history[i].result << endl;
        }
        cout << "-----------------------------\n";
    }

    void saveHistory() {
        ofstream file(HISTORY_FILE);
        if (!file) {
            cerr << "Warning: Unable to save history." << endl;
            return;
        }

        for (int i = 0; i < historyCount; i++) {
            file << history[i].num1 << " " << history[i].op << " " << history[i].num2 << " " << history[i].result << "\n";
        }
        file.close();
    }

    void loadHistory() {
        ifstream file(HISTORY_FILE);
        if (!file) return; // No file exists yet, skip

        historyCount = 0;
        while (file && historyCount < MAX_HISTORY) {
            Calculation calc;
            file >> calc.num1 >> calc.op >> calc.num2 >> calc.result;
            if (file.fail()) break;
            history[historyCount++] = calc;
        }
        file.close();
    }
};

bool getValidNumber(double& num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        return false;
    }
    return true;
}

int main() {
    Calculator calc;
    int choice;
    double num1 = 0, num2 = 0;
    char op;
    double lastResult = 0;
    bool hasLastResult = false;

    do {
        cout << "\n====== Virtual Calculator ======\n";
        cout << "Supported operations:\n";
        cout << "  + (Addition)\n";
        cout << "  - (Subtraction)\n";
        cout << "  * (Multiplication)\n";
        cout << "  / (Division)\n";
        cout << "  % (Modulus - integer only)\n";
        cout << "  ^ (Exponentiation)\n";
        cout << "Instructions:\n";
        cout << "  - Enter two numbers and an operator.\n";
        cout << "  - You can enter 'ans' instead of the first number to reuse the last result.\n";
        cout << "-----------------------------------\n";
        cout << "1. Perform Calculation\n2. View History\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter first number (or 'ans'): ";
            string input1;
            cin >> input1;

            if (input1 == "ans" && hasLastResult) {
                num1 = lastResult;
                cout << "Using previous result: " << num1 << endl;
            } else {
                try {
                    num1 = stod(input1);
                } catch (...) {
                    cout << "Invalid input for first number." << endl;
                    continue;
                }
            }

            cout << "Enter operator (+, -, *, /, %, ^): ";
            cin >> op;

            cout << "Enter second number: ";
            if (!getValidNumber(num2)) {
                cout << "Invalid input for second number." << endl;
                continue;
            }

            bool valid;
            double result = calc.performOperation(num1, op, num2, valid);
            if (valid) {
                cout << "Result: " << result << endl;
                lastResult = result;
                hasLastResult = true;
            }
        } else if (choice == 2) {
            calc.showHistory();
        } else if (choice != 3) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    cout << "Goodbye!\n";
    return 0;
}

