#include <iostream>
#include <cmath>

int main() {
    float a, b, c, d, r1, r2;
    std::cout << "Enter a, b, and c for a quadratic equation: " << std::endl;
    std::cin >> a >> b >> c;
    d = b * b - 4 * a * c;

    if (d == 0) {
        r1 = -b / (2 * a);
        std::cout << "The solutions are real and equal: " << r1 << std::endl;
    }
    else {
        if (d > 0) {
            r1 = (-b + std::sqrt(d)) / (2 * a);
            r2 = (-b - std::sqrt(d)) / (2 * a);
            std::cout << "The solutions are real and unequal: "
                << r1 << " " << r2 << std::endl;
        }
        else {
            std::cout << "The solutions are imaginary." << std::endl;
        }
    }
    return 0;
}