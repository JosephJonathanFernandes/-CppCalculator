# 🧮 C++ CLI Calculator

A simple yet powerful **command-line calculator** written in C++ that supports:

- Basic arithmetic: `+`, `-`, `*`, `/`
- Modulus: `%` (integer only)
- Exponentiation: `^`
- History tracking of up to 100 calculations
- Reuse of previous result using `ans`
- Persistent history saved to a text file

---

## 📦 Features

- Perform calculations with two numbers and an operator
- Use `ans` to reference the result of the last calculation
- View past calculations at any time
- Saves calculation history to `calc_history.txt` automatically
- Input validation to handle bad data and divide-by-zero

---

## 💡 Usage


g++ smart_calculator.cpp -o calculator

./calculator

📝 Sample Input

====== Virtual Calculator ======

Supported operations:

  + (Addition)
  + 
  - (Subtraction)
  - 
  * (Multiplication)
  * 
  / (Division)

  % (Modulus - integer only)
  
  ^ (Exponentiation)
  
Instructions:

  - Enter two numbers and an operator.
  - 
  - You can enter 'ans' instead of the first number to reuse the last result.

1. Perform Calculation
   
2. View History
   
3. Exit
   
Enter choice: 1

Enter first number (or 'ans'): ans

Enter operator (+, -, *, /, %, ^): *

Enter second number: 5

Result: 25

📂 Files

smart_calculator.cpp – Main source file

calc_history.txt – Automatically created; stores past calculations

.gitignore – Ignores build files and editor clutter

README.md – Project documentation

👨‍💻 Author

Joseph Fernandes

Feel free to fork or improve this project!

🔗 License

MIT License 

