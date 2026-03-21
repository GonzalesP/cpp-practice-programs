#include <iostream>

int main() {
    int a = 10;
    int &r = a;  // & makes r a reference variable (alias to a)

    // note: reference variables must be initialized at the same time as declaration
    // int &r;  results in an error

    // furthermore, you cannot assign another variable after the reference is initialized
    // r = b;  will make a/r the same value as b, but r will not refer to b

    r = 25;
    std::cout << "a: " << a <<std::endl;  // 25 (changing r changes a)
    std::cout << "r: " << r << std::endl;  // 25

    return 0;
}