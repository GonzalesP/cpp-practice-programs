#include <iostream>

// function pointers can be used to assign a function to a pointer
// this can be used to achieve runtime polymorphism (i.e., you can assign
// different functions throught a program's runtime)

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    // a function pointer is indicated by () and its signature
    int (*fp)(int, int);  // function pointer matches signature of max and min

    std::cout << std::endl;
    std::cout << "assigning max to fp..." << std::endl;
    fp = max;  // fp now points to max()

    std::cout << "(*fp)(10, 5): " << (*fp)(10, 5) << std::endl;
    // prints max(10, 5) -> 10

    std::cout << std::endl;
    std::cout << "assigning min to fp..." << std::endl;
    fp = min;  // fp now points to min()

    std::cout << "(*fp)(10, 5): " << (*fp)(10, 5) << std::endl;
    // prints min(10, 5) -> 5

    std::cout << std::endl;

    return 0;
}