#include <iostream>

int main() {
    int i, n;
    std::cout << "Enter n: ";
    std::cin >> n;

    // 73: generate multiplication with first 10 terms of n
    for (i = 1; i <= 10; ++i) {
        std::cout << n << " x " << i << " = " << n * i << std::endl;
    }

    // 74: summation of first N natural numbers
    int j, sum = 0;
    for (j = 1; j <= n; ++j) {
        sum += j;
    }
    std::cout << "Sum of first " << n << " numbers = " << sum << std::endl;

    // 75: factorial n!
    int k, prod = 1;
    for (k = 1; k <= n; ++k) {
        prod *= k;
    }
    std::cout << n << "! = " << prod << std::endl;

    // 76: factors of n
    int f;
    std::cout << "Factors of n: ";
    for (f = 1; f <= n; ++f) {
        if (n % f == 0)
            std::cout << f << " ";
    }
    std::cout << std::endl;

    // 77: perfect number check
    int p;
    int sumFactor = 0;
    for (p = 1; p <= n; ++p) {
        if (n % p == 0)
            sumFactor += p;
    }
    if (sumFactor == 2 * n) {
        std::cout << n << " is a perfect number." << std::endl;
    }
    else {
        std::cout << n << " is NOT a perfect number." << std::endl;
    }

    // 78: checking if a number is prime
    // primes only have two factors: itself and 1
    int q;
    bool prime = true;
    for (q = 2; q < n; ++q) {
        if (n % q == 0) {
            prime = false;
            break;
        }
    }

    if (prime) {
        std::cout << n << " is prime." << std::endl;
    }
    else {
        std::cout << n << " is not prime." << std::endl;
    }

    return 0;
}