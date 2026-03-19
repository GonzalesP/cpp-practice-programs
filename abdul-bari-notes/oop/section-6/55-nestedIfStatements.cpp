#include <iostream>
#include <cmath>

int main() {
    // use the discriminant of a quadratic formula to
    // determine how many roots to calculate
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

    // based on average marks, determine a grade
    int m1, m2, m3;
    float avg;
    std::cout << "Enter your three marks: " << std::endl;
    std::cin >> m1 >> m2 >> m3;
    avg = (float) (m1 + m2 + m3) / 3.0f;

    if (avg >= 60) {
        std::cout << "Your grade is A" << std::endl;
    }
    else if (avg >=35 && avg < 60) {
        std::cout << "Your grade is B" << std::endl;
    }
    else {
        std::cout << "Your grade is C" << std::endl;
    }
    return 0;
}