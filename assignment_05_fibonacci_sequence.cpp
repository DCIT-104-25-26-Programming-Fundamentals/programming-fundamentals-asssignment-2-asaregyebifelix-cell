// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacci(int N);
bool isFibonacci(int num);

int main() {
    int choice;
    
    cout << "FIBONACCI SEQUENCE MENU" << endl;
    cout << "======================" << endl;
    cout << "1. Print First N Terms" << endl;
    cout << "2. Check if a Number is Fibonacci" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            int N;
            cout << "\n--- PRINT FIRST N TERMS ---" << endl;
            cout << "How many terms? ";
            cin >> N;
            
            if (N <= 0) {
                cout << "Error: Number of terms must be positive." << endl;
            } else {
                printFibonacci(N);
            }
            break;
        }
        
        case 2: {
            int num;
            cout << "\n--- CHECK FIBONACCI NUMBER ---" << endl;
            cout << "Enter a number to check: ";
            cin >> num;
            
            if (isFibonacci(num)) {
                cout << num << " is a Fibonacci number." << endl;
            } else {
                cout << num << " is NOT a Fibonacci number." << endl;
            }
            break;
        }
        
        case 3:
            cout << "Exiting program. Goodbye!" << endl;
            break;
            
        default:
            cout << "Invalid choice! Please enter 1-3." << endl;
    }
    
    return 0;
}

// PART A: Function to print first N Fibonacci numbers
void printFibonacci(int N) {
    if (N == 1) {
        cout << "Fibonacci sequence: 0" << endl;
        return;
    }
    if (N == 2) {
        cout << "Fibonacci sequence: 0 1" << endl;
        return;
    }
    
    long long first = 0;
    long long second = 1;
    long long next;
    
    cout << "Fibonacci sequence: " << first << " " << second;
    
    for (int i = 3; i <= N; i++) {
        next = first + second;
        cout << " " << next;
        first = second;
        second = next;
    }
    cout << endl;
}

bool isFibonacci(int num) {
    if (num < 0) {
        return false;
    }
    
    if (num == 0 || num == 1) {
        return true;
    }
    
    long long first = 0;
    long long second = 1;
    long long next = first + second;
    
    while (next < num) {
        first = second;
        second = next;
        next = first + second;
    }
    
    return (next == num);
}

