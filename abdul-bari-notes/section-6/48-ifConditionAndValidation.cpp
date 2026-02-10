#include <iostream>

int main() {
    int a, b, c;
    // in fractions, dividend is numerator, divisor is denominator
    std::cout << "Enter a dividend and divisor: " << std::endl;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << "ERROR: Cannot divide by zero" << std::endl;
    }
    else {
        c = a / b;
        std::cout << "The quotient is " << c << std::endl;
    }
    return 0;
}