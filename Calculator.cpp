#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    char operation;
    double num1, num2;

    cout << "Complex Calculator" << endl;
    cout << "------------------" << endl;

    // Input the operation
    cout << "Choose an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exponentiation (^)" << endl;
    cout << "6. Square root (sqrt)" << endl;
    cout << "7. Factorial (!)" << endl;
    cout << "Enter the operation: ";
    cin >> operation;

    // Perform the operation based on user's choice
    switch (operation) {
        case '+':
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            cout << "Enter dividend: ";
            cin >> num1;
            cout << "Enter divisor: ";
            cin >> num2;
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        case '^':
            cout << "Enter base: ";
            cin >> num1;
            cout << "Enter exponent: ";
            cin >> num2;
            cout << "Result: " << pow(num1, num2) << endl;
            break;
        case 'sqrt':
            cout << "Enter number: ";
            cin >> num1;
            if (num1 >= 0) {
                cout << "Result: " << sqrt(num1) << endl;
            } else {
                cout << "Error: Cannot calculate square root of a negative number!" << endl;
            }
            break;
        case '!':
            cout << "Enter a non-negative integer: ";
            cin >> num1;
            if (num1 >= 0 && num1 == int(num1)) {
                cout << "Result: " << factorial(num1) << endl;
            } else {
                cout << "Error: Factorial is defined only for non-negative integers!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
    }

    return 0;
}
