#include <iostream>

int main() {
    // find the Greatest Common Denominator of two numbers
    int m, n;
    std::cout << "Enter two numbers to find their GCD: ";
    std::cin >> m >> n;

    while (m != n) {
        if (m > n)
            m -= n;
        else
            n -= m;
    }
    std::cout << "The GCD is " << m << std::endl;
    
    return 0;
}