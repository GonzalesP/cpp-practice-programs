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

    int menuOption;
    int choice;
    std::cout << "Menu Options:"  << std::endl;
    std::cout << "1. Add" << std::endl << "2. Sub" << std::endl
                << "3. Mul" << std::endl << "4. Div" << std::endl;
    
    std::cout << "Enter a choice: " << std::endl;
    std::cin >> choice;

    int a, b, c;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> a >> b;
    switch (choice) {
        case 1:
            c = a + b;
            break;  // don't forget break; !!
        case 2:
            c = a - b;
            break;
        case 3:
            c = a * b;
            break;
        case 4:
            c = a / b;  // note: int division
            break;
    }

    std::cout << "c = " << c << std::endl;

    return 0;
}