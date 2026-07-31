#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (n <= 1) return false
    if (n <= 3) return true
    if (n% 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0)

        return false;
    }
    return true;
    // Numbers less than 2 are not prime
    if (num < 2) {
        return false;
    }
    
    // Check for divisors from 2 to num-1
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;  // Found a divisor, not prime
        }
    }
    
    return true;  // No divisors found, number is prime
}

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }
    
    return 0;
}g++ -std=c++11 assignment_01_prime_checker.cpp -o prime_checker

./prime_checker
 7

./prime_checker

10

./prime_checker
13
