#include <iostream>

struct Rectangle {
    int length;
    int breadth;
    // char x;
};
// 2 ints should make 8 bytes of size
// char technically takes 1 byte, but if it is included in struct,
// the size will be rounded up from 4 + 4 + 1 = 9 to 12
// because some compilers like to read data 4 bytes at a time (a word)
// this is known as "padding"

/*
struct Rectangle {
    int length;
    int breadth;
} r1, r2, r3;  // define struct objects along with struct definition
*/


int main() {
    struct Rectangle r1 = {10, 5};

    printf("%lu", sizeof(r1));  // int + int (4 + 4) = 8 bytes

    // %d - expects int, but sizeof() returns a long unsigned int
    // better to use %lu


    // the dot operator is used to access members
    r1.length = 15;
    r1.breadth = 7;

    std::cout << r1.length << std::endl;
    std::cout << r1.breadth << std::endl;

    return 0;
}