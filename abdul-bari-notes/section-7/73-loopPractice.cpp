#include <iostream>

int main() {
    int i, n;
    std::cout << "Enter n: ";
    std::cin >> n;

    // generate multiplication with first 10 terms of n
    for (i = 1; i <= 10; ++i) {
        std::cout << n << " x " << i << " = " << n * i << std::endl;
    }

    // summation of first N natural numbers
    int j, sum = 0;
    for (j = 1; j <= n; ++j) {
        sum += j;
    }
    std::cout << "Sum of first " << n << " numbers = " << sum << std::endl;

    // factorial n!
    int k, prod = 1;
    for (k = 1; k <= n; ++k) {
        prod *= k;
    }
    std::cout << n << "! = " << prod << std::endl;

    // factors of n
    int f;
    std::cout << "Factors of n: ";
    for (f = 1; f <= n; ++f) {
        if (n % f == 0)
            std::cout << f << " ";
    }
    std::cout << std::endl;

    // perfect number check
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

    return 0;
}