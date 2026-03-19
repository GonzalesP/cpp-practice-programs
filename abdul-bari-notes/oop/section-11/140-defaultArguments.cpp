#include <iostream>

// overloading allows you to have same name with different # of parameters
// but you can also let users omit input by setting default/optional parameters

// e.g., instead of making two functions for adding 2 vs. 3 ints,
// you can make the third int optional (i.e., equal to 0)
// the output would be equivalent to a + b + 0 = a + b
// which means you don't need a separate function for (int, int)
int sum(int a, int b, int c = 0) {
    return a + b + c;
}
// "if c omitted, it will be 0 -> a + b + 0 = a + b"
// "if c has a value, it will be a + b + c"


// essentially gives 4 different function call options
// max(), max(a), max(a, b), and max(a, b, c)
int max(int a = INT_MIN, int b = INT_MIN, int c = INT_MIN) {
    return a > b && a > c ? a : (b > c ? b : c);
}
// if (...) return a, else -> if (b > c) return b, else -> return c


// note: if you want to set up default arguments, start with the rightmost
// parameter and work towards the left (defaults should be last!)

int main() {
    std::cout << "2 + 3: " << sum(2, 3) << std::endl;
    std::cout << "2 + 3 + 4: " << sum (2, 3, 4) << std::endl;
    std::cout << "max(): " << max() << std::endl;
    std::cout << "max(1): " << max(1) << std::endl;
    std::cout << "max(1, 2): " << max(1, 2) << std::endl;
    std::cout << "max(1, 2, 3): " << max(1, 2, 3) << std::endl;

    return 0;
}