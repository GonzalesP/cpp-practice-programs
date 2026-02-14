#include <iostream>

// note: these are "traditional" strings, supported by C and C++
// C++ has a built-in class for strings, using the <string> library
// it's a lot easier to use!
int main() {
    // method 1 - strings can be created using char arrays/pointers

    // char arrays
    char S1[10] = "Hello";  // after 'o' is '\0' (null character)
    std::cout << "S1: " << S1 << std::endl;  // so only 5 char are printed by cout

    char S2[] = "Hello";  // can use ambiguous size []
    std::cout << "S2: " << S2 << std::endl;

    char S3[] = {'H', 'e', 'l', 'l', 'o', '\0', 'p'};  // p not printed! bc \0
    std::cout << "S3: " << S3 << std::endl;

    char S4[] = {65, 66, 67, 68, 0};  // ASCII - 'A', 'B', 'C', 'D', '\0'
    std::cout << "S4: " << S4 << std::endl;

    char S5[] = {69, 70, 71, 72, 0, 73, 74};  // I and J not printed (after 0)!
    std::cout << "S5: " << S5 << std::endl;


    // char pointers
    // warning: ISO C++11 FORBIDS conversion from string literal -> char *
    // char *S6 = "Hello";  // "it is suggested not to use this method"
    // std::cout << S6 << std::endl;
        // better to use std::string s = "Hello";

    return 0;
}