// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void printSingleTable(int num);
void printTablesUpToN(int N);

int main() {
    int choice;
    
    cout << "MULTIPLICATION TABLE GENERATOR" << endl;
    cout << "==============================" << endl;
    cout << "1. Print Single Table" << endl;
    cout << "2. Print Tables from 1 to N" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            // PART A: Single Table
            int num;
            cout << "\n--- SINGLE MULTIPLICATION TABLE ---" << endl;
            cout << "Enter a number: ";
            cin >> num;
            
            printSingleTable(num);
            break;
        }
        
        case 2: {
            // PART B: Tables from 1 to N
            int N;
            cout << "\n--- MULTIPLICATION TABLES FROM 1 TO N ---" << endl;
            cout << "Enter a number N: ";
            cin >> N;
            
            if (N <= 0) {
                cout << "Error: N must be a positive integer." << endl;
            } else {
                printTablesUpToN(N);
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

// PART A: Function to print multiplication table for a single number
void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":" << endl;
    cout << "------------------------------" << endl;
    
    for (int i = 1; i <= 12; i++) {
        cout << setw(2) << num 
             << "  x  " 
             << setw(2) << i 
             << "  =  " 
             << setw(3) << (num * i) << endl;
    }
}

// PART B: Function to print multiplication tables from 1 to N
void printTablesUpToN(int N) {
    cout << "\n";
    
    for (int i = 1; i <= N; i++) {
        // Print table for current number
        cout << "Multiplication Table for " << i << ":" << endl;
        cout << "------------------------------" << endl;
        
        for (int j = 1; j <= 12; j++) {
            cout << setw(2) << i 
                 << "  x  " 
                 << setw(2) << j 
                 << "  =  " 
                 << setw(3) << (i * j) << endl;
        }
        
        // Add separator line after each table (except after the last one)
        if (i < N) {
            cout << "---------------------------" << endl;
            cout << endl;  // Add extra blank line for readability
        }
    }
}

