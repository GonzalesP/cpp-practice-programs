#include <iostream>

int main() {
    int x = 10;
    int &y = x;  // y is a reference to (alias for) x

    std::cout << "x: " << x << std::endl;
    x++;  // x = 11
    y++;  // x = 12 (because y is also x)
    std::cout << "x after x++ and y++: " << x << std::endl;
    std::cout << std::endl;

    std::cout << "&x: " << &x << ", &y: " << &y << std::endl;

    // references MUST be initialized DURING declaration
    // int &z;  - illegal, needs to reference something!
    int &z = y;

    // you cannot change references after they are initialized
    int b = 20;
    // z = b;  // okay: x = 20, y = 20, z = 20 (but &z will not == &b)
    // &z = b;  // illegal!

    int *p = &b;
    int * &q = p;  // q is a reference to the int pointer p

    return 0;
}