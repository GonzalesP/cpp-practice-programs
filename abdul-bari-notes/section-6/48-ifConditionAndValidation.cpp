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
    std::cout << std::endl;

    // 50 - Compound Conditional Statement
    int hour;  // from 0 to 23
    std::cout << "Enter an hour: " << std::endl;
    std::cin >> hour;
    if (hour >= 9 && hour <= 17) {  // assume work is from 9-5
        std::cout << "This is a working hour" << std::endl;
    }
    else {
        std::cout << "This is a leisure hour" << std::endl;
    }

    // 51 - Practice Program using Compound Conditions
    // "suppose children (12 and under) and seniors (50+) get discounts"
    // "check if the age is eligible or not"
    int age;
    std::cout << "Enter an age: " << std::endl;
    std::cin >> age;
    if (age <= 12 || age >= 50)
        std::cout << "You are eligible for discounts" << std::endl;
    else   
        std::cout << "You are ineligible for discounts" << std::endl;
    
    return 0;
}