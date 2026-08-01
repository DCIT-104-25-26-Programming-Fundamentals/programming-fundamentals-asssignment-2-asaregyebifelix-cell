// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int calculateSum(int arr[], int n);
double calculateAverage(int arr[], int n);
int findMaximum(int arr[], int n);
int findMinimum(int arr[], int n);

int main() {
    int n;
    
    // Get array size
    cout << "How many numbers? ";
    cin >> n;
    
    // Check for valid input
    if (n <= 0) {
        cout << "Error: N must be a positive integer!" << endl;
        return 1;
    }
    
    int array[100]; // Maximum 100 numbers
    
    // Get numbers from user
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> array[i];
    }
    
    // Calculate statistics
    int sum = calculateSum(array, n);
    double average = calculateAverage(array, n);
    int max = findMaximum(array, n);
    int min = findMinimum(array, n);
    
    // Display results
    cout << "\nResults:" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << fixed << setprecision(1) << average << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    
    return 0;
}

// Function to calculate sum
int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate average
double calculateAverage(int arr[], int n) {
    int sum = calculateSum(arr, n);
    return (double)sum / n;
}

// Function to find maximum
int findMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find minimum
int findMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}