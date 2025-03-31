 #include <iostream>
#include <cmath>
#include <limits>

using namespace std;

void showMenu() {
    cout << "\n===== Advanced Calculator =====\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%)\n";
    cout << "6. Power (x^y)\n";
    cout << "7. Square Root (vx)\n";
    cout << "8. Logarithm (log base 10)\n";
    cout << "9. Exit\n";
    cout << "Choose an operation: ";
}

double getNumber() {
    double num;
    while (!(cin >> num)) {
        cout << "Invalid input! Please enter a number: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

void performCalculation(int choice) {
    double num1, num2, result;

    switch (choice) {
        case 1: // Addition
            cout << "Enter two numbers: ";
            num1 = getNumber();
            num2 = getNumber();
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;

        case 2: // Subtraction
            cout << "Enter two numbers: ";
            num1 = getNumber();
            num2 = getNumber();
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;

        case 3: // Multiplication
            cout << "Enter two numbers: ";
            num1 = getNumber();
            num2 = getNumber();
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;

        case 4: // Division
            cout << "Enter two numbers: ";
            num1 = getNumber();
            num2 = getNumber();
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed!" << endl;
            } else {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            }
            break;

        case 5: // Modulus
            int int1, int2;
            cout << "Enter two integers: ";
            while (!(cin >> int1 >> int2)) {
                cout << "Invalid input! Please enter two integers: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (int2 == 0) {
                cout << "Error: Modulus by zero is not allowed!" << endl;
            } else {
                cout << "Result: " << int1 % int2 << endl;
            }
            break;

        case 6: // Power
            cout << "Enter base and exponent: ";
            num1 = getNumber();
            num2 = getNumber();
            result = pow(num1, num2);
            cout << "Result: " << result << endl;
            break;

        case 7: // Square Root
            cout << "Enter a number: ";
            num1 = getNumber();
            if (num1 < 0) {
                cout << "Error: Square root of a negative number is not defined!" << endl;
            } else {
                result = sqrt(num1);
                cout << "Result: " << result << endl;
            }
            break;

        case 8: // Logarithm
            cout << "Enter a number: ";
            num1 = getNumber();
            if (num1 <= 0) {
                cout << "Error: Logarithm is only defined for positive numbers!" << endl;
            } else {
                result = log10(num1);
                cout << "Result: " << result << endl;
            }
            break;

        case 9: // Exit
            cout << "Exiting the calculator. Thank you!\n";
            exit(0);

        default:
            cout << "Invalid choice! Please select a valid option.\n";
    }
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice.\n";
            continue;
        }

        performCalculation(choice);
    }

    return 0;
}

