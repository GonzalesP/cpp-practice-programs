#include <iostream>

// examples of functions (used in main())
float add(float x, float y) {
    float z;
    z = x + y;
    return z;
}  // all variables are deleted from stack once this function ends
// also, the names for variables declared in a function are separate from
// variables declared outside the function, so for e.g., you can reuse x,y,z

int max(int a, int b, int c) {
    if (a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else
        return c;
}

// functions can be "overloaded" - shared function names
// the only condition is that they need different parameter lists
// note: return type is not considered when differentiating overloaded functions
float max(float a, float b, float c) {
    if (a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else
        return c;
}

int main() {
    float x = 2.3f, y = 7.9f, z;
    z = add(x, y);
    std::cout << z << std::endl;  // 10.2

    int a = 10, b = 15, c = 5, r;
    r = max(a, b, c);
    std::cout << r << std::endl;  // 15

    return 0;
}