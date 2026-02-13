#include <iostream>

int main() {
    int A[] = {2,4,6,8,10,12};
    int *p = A;  // point to address of first element of A
    std::cout << "p: " << p << std::endl;  // starting address of A
    std::cout << "*p: " << *p << std::endl;  // 2

    p++;  // p now points to second (next) element of A (location of 4)
    std::cout << "p++: " << p << std::endl;  // next address
    std::cout << "*p: " << *p << std::endl;  // 4

    p--;  // back to start
    std::cout << "p--: " << p << std::endl;  // first address
    std::cout << "*p: " << *p << std::endl;  // 2

    // print the element 3 spots down, i.e., A[3]
    std::cout << "p+3: " << p + 3 << std::endl;
    std::cout << "*(p + 3): " << *(p + 3) << std::endl;  // 8
        // need () so that you don't add *p and 3 (2 + 3)
        // i.e., move down 3 spots before dereferencing

    int *q = &A[3];  // address of A's 3rd element
    std::cout << "int *q = &A[3]: " << q << std::endl;  // p + 3

    // to see if a pointer is ahead of (right) or behind (left) another, use -
    std::cout << "q - p: " << q - p << std::endl;  // 3 (bc q is 3 spots ahead)

    int d = q - p;  // to save this difference, use an int

    return 0;
}