#include <iostream>

int main () {
    // 67 - bills and discounts
    float billAmount, totalAmount, discount;
    std::cout << "Enter a bill and see if you can get discounts:" << std::endl;
    std::cin >> billAmount;

    if (billAmount < 100) {
        std::cout << "No discount." << std::endl;
        discount = 0.0f;
    }
    else if (billAmount >= 100 && billAmount < 500) {
        std::cout << "10\% discount." << std::endl;
        discount = billAmount * 0.10f;
    }
    else {
        std::cout << "20\% discount."  << std::endl;
        discount = billAmount * 0.20f;
    }

    totalAmount = billAmount - discount;
    std::cout << "discount: " << discount << std::endl;
    std::cout << "totalAmount: " << totalAmount << std::endl;

    return 0;
}