// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

// Function prototypes for arithmetic operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int modulus(int a, int b);
double exponentiate(double base, double exponent);
void showMenu();

int main() {
    int choice;
    double num1, num2;
    double result;
    
    cout << "WELCOME TO THE SIMPLE CALCULATOR!" << endl;
    cout << "=================================" << endl;
    
    while (true) {
        showMenu();
        cin >> choice;
        
        // Clear input buffer to handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            cout << endl;
            continue;
        }
        
        // Check if user wants to quit
        if (choice == 7) {
            cout << "\nGoodbye! Thank you for using the calculator!" << endl;
            break;
        }
        
        // Validate menu choice
        if (choice < 1 || choice > 7) {
            cout << "Invalid choice! Please select an option between 1 and 7." << endl;
            cout << endl;
            continue;
        }
        
        // Get numbers from user
        cout << "Enter first number: ";
        cin >> num1;
        
        // Special case for modulus - needs integer inputs
        if (choice == 5) {
            int intNum1, intNum2;
            intNum1 = static_cast<int>(num1);
            cout << "Enter second number: ";
            cin >> intNum2;
            
            if (intNum2 == 0) {
                cout << "Error: Cannot perform modulus by zero." << endl;
            } else {
                int modResult = modulus(intNum1, intNum2);
                cout << "Result: " << intNum1 << " % " << intNum2 << " = " << modResult << endl;
            }
            cout << endl;
            continue;
        }
        
        cout << "Enter second number: ";
        cin >> num2;
        
        // Perform the selected operation
        switch(choice) {
            case 1: // Addition
                result = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " 
                     << fixed << setprecision(2) << result << endl;
                break;
                
            case 2: // Subtraction
                result = subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " 
                     << fixed << setprecision(2) << result << endl;
                break;
                
            case 3: // Multiplication
                result = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " 
                     << fixed << setprecision(2) << result << endl;
                break;
                
            case 4: // Division
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    result = divide(num1, num2);
                    cout << "Result: " << num1 << " / " << num2 << " = " 
                         << fixed << setprecision(2) << result << endl;
                }
                break;
                
            case 6: // Exponentiation
                result = exponentiate(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " 
                     << fixed << setprecision(2) << result << endl;
                break;
                
            default:
                cout << "Unexpected error occurred." << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}

// Function to display the menu
void showMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// Addition function
double add(double a, double b) {
    return a + b;
}

// Subtraction function
double subtract(double a, double b) {
    return a - b;
}

// Multiplication function
double multiply(double a, double b) {
    return a * b;
}

// Division function
double divide(double a, double b) {
    return a / b;
}

// Modulus function (only works with integers)
int modulus(int a, int b) {
    return a % b;
}

// Exponentiation function
double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}