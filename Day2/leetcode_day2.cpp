#include <iostream>
#include <string>
#include <cmath>

// Function to implement the Fizz Buzz game
void fizzBuzz() {
    std::cout << "--- Fizz Buzz Game ---" << std::endl;
    int n;
    std::cout << "Enter a number (up to which to play Fizz Buzz): ";
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "FizzBuzz" << std::endl;
        } else if (i % 3 == 0) {
            std::cout << "Fizz" << std::endl;
        } else if (i % 5 == 0) {
            std::cout << "Buzz" << std::endl;
        } else {
            std::cout << i << std::endl;
        }
    }
    std::cout << std::endl;
}

// Function to check if a number is prime
void primeNumberChecker() {
    std::cout << "--- Prime Number Checker ---" << std::endl;
    int num;
    std::cout << "Enter a positive integer to check for primality: ";
    std::cin >> num;

    if (num <= 1) {
        std::cout << num << " is not a prime number." << std::endl;
        return;
    }

    bool isPrime = true;

    // We only need to check divisors up to sqrt(num)
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }
    std::cout << std::endl;
}

// Function to generate a simple pattern (e.g., right-angled triangle of asterisks)
void patternGenerator() {
    std::cout << "--- Pattern Generator (Right-Angled Triangle) ---" << std::endl;
    int rows;
    std::cout << "Enter the number of rows for the pattern: ";
    std::cin >> rows;

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Function to check if a number is an Armstrong number
// An Armstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
// For example, 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
void armstrongNumberChecker() {
    std::cout << "--- Armstrong Number Checker ---" << std::endl;
    int num, originalNum, remainder, n = 0;
    double result = 0.0;

    std::cout << "Enter a positive integer to check for Armstrong number: ";
    std::cin >> num;

    originalNum = num;

    // Count the number of digits
    int tempNum = originalNum;
    while (tempNum != 0) {
        tempNum /= 10;
        ++n;
    }

    // Calculate the sum of nth powers of its digits
    tempNum = originalNum;
    while (tempNum != 0) {
        remainder = tempNum % 10;
        result += pow(remainder, n);
        tempNum /= 10;
    }

    if (static_cast<int>(result) == originalNum) {
        std::cout << originalNum << " is an Armstrong number." << std::endl;
    } else {
        std::cout << originalNum << " is not an Armstrong number." << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Call each function
    fizzBuzz();
    primeNumberChecker();
    patternGenerator();
    armstrongNumberChecker();

    return 0;
}

