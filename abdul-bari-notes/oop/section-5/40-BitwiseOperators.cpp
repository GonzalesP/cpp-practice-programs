#include <iostream>

int main() {
    int x = 5, y = 11;  // x is 00000101, y is 00001011

    // bitwise AND, OR, XOR, NOT, SHIFT LEFT, SHIFT RIGHT (respectively)
    std::cout << "x & y: " << (x & y) << std::endl;  // 1
    std::cout << "x | y: " << (x | y) << std::endl;  // 15
    std::cout << "x ^ y: " << (x ^ y) << std::endl;  // 14
    std::cout << "~x: " << (~x) << std::endl;  // -6
    std::cout << "x << 1: " << (x << 1) << std::endl;  // 10 (multiply by 2^1)
    std::cout << "x >> 1: " << (x >> 1) << std::endl;  // 2 (divide, drop float)

    return 0;
}