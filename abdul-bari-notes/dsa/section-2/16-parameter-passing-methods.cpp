#include <iostream>

// use when you want to use values for computation and return result
// that does not involve the parameters
int addByValue(int a, int b) {
    int c = a + b;

    a++;  // a = x1 + 1 = 11
    std::cout << "a: " << a << std::endl;
    return c;
}

// when you want function to actively work on the actual parameters
// (e.g., the variables created in main())
void swapByAddress(int* x, int* y) {
    int temp;
    temp = *x;  // x points to x3 -> temp = x3 = 10
    *x = *y;  // value at x3 becomes value at x4 (15)
    *y = temp;  // value at x4 becomes 10
}

// calling by reference gives the actual parameters reference variables
// (i.e., aliases) - use for small, simple functions to possibly avoid
// creating large amounts of inline code (depends on compiler)
void swapByReference(int& x, int& y) {
    int temp;
    temp = x;  // temp = x5
    x = y;  // x5 = x6
    y = temp;  // x6 = temp
}

int main() {
    int x1 = 10, x2 = 15, sumA;
    sumA = addByValue(x1, x2);
    std::cout << x1 << std::endl;  // x1 is still 10, not 11

    int x3 = 20, x4 = 25;
    swapByAddress(&x3, &x4);
    std::cout << "x3: " << x3 << std::endl;  // 15
    std::cout << "x4: " << x4 << std::endl;  // 10

    int x5 = 10, x6 = 15;
    swapByReference(x5, x6);
    std::cout << "x5: " << x5 << std::endl;  // 15
    std::cout << "x6: " << x6 << std::endl;  // 10

    return 0;
}