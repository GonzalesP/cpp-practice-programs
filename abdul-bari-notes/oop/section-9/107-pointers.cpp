#include <iostream>

int main() {
    int a = 10;
    int *p = &a;  // save the address (memory location) of int a

    std::cout << "a: " << a << std::endl;  // 10
    std::cout << "&a: " << &a << std::endl;  // address of a
    std::cout << "p: " << p << std::endl;  // p = address of a
    std::cout << "&p: " << &p << std::endl;  // address of p itself
    std::cout << "*p: " << *p << std::endl;  // data that p points to (a = 10)

    return 0;
}