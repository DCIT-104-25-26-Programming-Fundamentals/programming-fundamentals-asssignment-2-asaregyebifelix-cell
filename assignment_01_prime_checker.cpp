#include <iostream>
using namespace std;

// Optimized function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
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
#7
./prime_checker
#10
./prime_checker
#13


