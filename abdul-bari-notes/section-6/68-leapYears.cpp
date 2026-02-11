#include <iostream>

int main() {
    // all years that are divisble by 4 are leap years EXCEPT for century years
    // (i.e., years ending with 00), which need to be divisible by 400

    // e.g., 2012, 2004, 1968 are divisible by 4 -> leap years
    // e.g., 1971, 2006 are not divisible by 4 -> not leap years
    // e.g., 1200, 1600, 2000, 2400 are leap years (end with 00, div by 400)
    // e.g., 1700, 1800, 1900 end with 00 but not div by 400 -> not leap years

    int year;
    std::cout << "Enter a year: " << std::endl;
    std::cin >> year;

    if (year % 4 == 0) {
        if (year % 100 == 0 && !(year % 400 == 0)) {
            std::cout << year << " IS NOT a leap year." << std::endl;
        }
        else {
            std::cout << year << " IS a leap year." << std::endl;
        }
    }
    else {
        std::cout << year << " IS NOT a leap year." << std::endl;
    }
    return 0;
}