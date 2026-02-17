#include <iostream>

// instead of rewriting functions for different data types,
// you can use a template type class to generalize function logic

// e.g., if x and y are ints, 'T' will be replaced with int
// and the logic will find the max of two int variables
// same with float and etc.
template <class T>
T max(T x, T y) {
    if (x > y)
        return x;
    return y;
}
// a > b ? a : b;  // is a > b ? yes -> return a : no -> return b

int main() {
    int c = max(10, 5);  // T max() is called using int for T
    float d = max(10.5f, 6.9f);  // T is replaced with float

    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    // max(2.3f, 5.6) - won't work because of type ambiguity!
    // the function needs both paramters to match: (T x, T y)
    
    return 0;
}