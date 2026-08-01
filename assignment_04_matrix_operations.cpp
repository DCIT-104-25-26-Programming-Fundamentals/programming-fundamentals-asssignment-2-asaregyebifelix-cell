// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void readMatrix(int matrix[10][10], int rows, int cols, const string& name);
void displayMatrix(int matrix[10][10], int rows, int cols);
void transposeMatrix(int matrix[10][10], int transposed[10][10], int rows, int cols);
void addMatrices(int A[10][10], int B[10][10], int result[10][10], int rows, int cols);
void multiplyMatrices(int A[10][10], int B[10][10], int result[10][10], int M, int N, int P);

// Main function - Menu driven
int main() {
    int choice;
    int matrixA[10][10], matrixB[10][10], result[10][10];
    int rows, cols, M, N, P;
    
    cout << "MATRIX OPERATIONS MENU" << endl;
    cout << "======================" << endl;
    cout << "1. Transpose Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            // PART A: Transpose
            cout << "\n--- TRANSPOSE MATRIX ---" << endl;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            
            readMatrix(matrixA, rows, cols, "A");
            
            cout << "\nOriginal Matrix:" << endl;
            displayMatrix(matrixA, rows, cols);
            
            int transposed[10][10];
            transposeMatrix(matrixA, transposed, rows, cols);
            
            cout << "\nTransposed Matrix:" << endl;
            displayMatrix(transposed, cols, rows);
            break;
        }
        
        case 2: {
            // PART B: Addition
            cout << "\n--- ADD TWO MATRICES ---" << endl;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            
            readMatrix(matrixA, rows, cols, "A");
            readMatrix(matrixB, rows, cols, "B");
            
            cout << "\nMatrix A:" << endl;
            displayMatrix(matrixA, rows, cols);
            
            cout << "\nMatrix B:" << endl;
            displayMatrix(matrixB, rows, cols);
            
            addMatrices(matrixA, matrixB, result, rows, cols);
            
            cout << "\nSum (A + B):" << endl;
            displayMatrix(result, rows, cols);
            break;
        }
        
        case 3: {
            // PART C: Multiplication
            cout << "\n--- MULTIPLY TWO MATRICES ---" << endl;
            cout << "Matrix A dimensions:" << endl;
            cout << "Enter number of rows (M): ";
            cin >> M;
            cout << "Enter number of columns (N): ";
            cin >> N;
            
            readMatrix(matrixA, M, N, "A");
            
            cout << "\nMatrix B dimensions:" << endl;
            cout << "Enter number of rows (must be " << N << "): ";
            cin >> P;  // P is rows of B, but we need to verify it equals N
            
            if (P != N) {
                cout << "Error: Columns of A (" << N << ") must equal rows of B (" << P << ")" << endl;
                cout << "Multiplication not possible!" << endl;
                break;
            }
            
            int colsB;
            cout << "Enter number of columns (P): ";
            cin >> colsB;
            
            readMatrix(matrixB, P, colsB, "B");
            
            cout << "\nMatrix A (" << M << "x" << N << "):" << endl;
            displayMatrix(matrixA, M, N);
            
            cout << "\nMatrix B (" << N << "x" << colsB << "):" << endl;
            displayMatrix(matrixB, P, colsB);
            
            multiplyMatrices(matrixA, matrixB, result, M, N, colsB);
            
            cout << "\nProduct (A x B):" << endl;
            displayMatrix(result, M, colsB);
            break;
        }
        
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
            
        default:
            cout << "Invalid choice! Please enter 1-4." << endl;
    }
    
    return 0;
}

// Function to read a matrix from user
void readMatrix(int matrix[10][10], int rows, int cols, const string& name) {
    cout << "\nEnter elements for Matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix with nice formatting
void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose a matrix
void transposeMatrix(int matrix[10][10], int transposed[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];  // Swap rows and columns
        }
    }
}

// PART B: Add two matrices
void addMatrices(int A[10][10], int B[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply two matrices
void multiplyMatrices(int A[10][10], int B[10][10], int result[10][10], int M, int N, int P) {
    // Initialize result matrix with zeros
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0;
        }
    }
    
    // Matrix multiplication: A(MxN) * B(NxP) = Result(MxP)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

