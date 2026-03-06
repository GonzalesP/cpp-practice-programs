#include <iostream>

// auto is used when you don't want to worry about data types

float fun() {
    return 2.34f;
}

int main() {
    auto x = 2 * 5.7 + 'a';  // x automatically becomes a double
        // int literal, double literal, and char literal

    x = fun();  // becomes 2.34 (double)  - converts from float

    double d = 12.3;
    int i = 9;

    x = 2 * d + i;  // working with double and int var


    // the decltype() function returns the type of another variable and is used
    // when you want to create another variable of the same type

    float y = 90.5f;

    decltype(y) z = 12.3f;  // z becomes the same type as y (float)
        // decltype(y) gives float

    return 0;
}