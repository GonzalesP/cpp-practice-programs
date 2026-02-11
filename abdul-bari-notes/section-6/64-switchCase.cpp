#include <iostream>

int main() {
    int day;  // 0 - sun, 1 - mon, 2 - tue, 3 - wed
    std::cout << "Enter a day no." << std::endl;
    std::cin >> day;

    switch (day) {
        case 0:
            std::cout << "sun" << std::endl;
            break;  // without break, ALL following cases will execute!
        case 1:
            std::cout << "mon" << std::endl;
            break;  // e.g., day = 3 would print wed thu ... Invalid day
        case 2:
            std::cout << "tue" << std::endl;
            break;
        case 3:
            std::cout << "wed" << std::endl;
            break;
        case 4:
            std::cout << "thu" << std::endl;
            break;
        case 5:
            std::cout << "fri" << std::endl;
            break;
        case 6:
            std::cout << "sat" << std::endl;
            break;
        // default is executed at the end, don't need break; (but cases should!)
        default:  std::cout << "Invalid day" << std::endl;
    }

    return 0;
}