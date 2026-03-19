#include <iostream>
#include <string>

// you can throw anything as an exception; int, double, float, string,
// and even custom-made exception classes

// when making a custom exception class, you can make it inherit
// C++'s std::exception class
class MyException : std::exception {
    //
};


// NOTE: the following passage IS NOT APPLICABLE to standard C++ 17 or later!!!

// when writing functions, you can also declare what data types the function
// can throw. you can use commas to indicate multiple thrown data types.
// leaving the parameter empty indicates that the function does not
// throw anything. these declarations help the programmer anticipate what
// kind of exceptions to look out for when calling the function
// int division (int a, int b) throw(MyException) {  - only before C++17 !!!

int division (int a, int b) {  
    if (b == 0)
        throw MyException();
    return a / b;
}

int main() {
    int x = 10, y = 0, z;

    // throwing an int
    try {
        if (y == 0)
            throw 1;
        z = x / y;
        std::cout << "z: " << z << std::endl;
    }
    catch (int e) {  // e and 1 are type int
        std::cout << "Division by zero. " << e << std::endl;
    }

    // throwing an double
    try {
        if (y == 0)
            throw 1.5;
        z = x / y;
        std::cout << "z: " << z << std::endl;
    }
    catch (double e) {  // e and 1.5 are type double
        std::cout << "Division by zero. " << e << std::endl;
    }

    // throwing a string
    try {
        if (y == 0)
            throw std::string("Div by 0");
        z = x / y;
        std::cout << "z: " << z << std::endl;
    }
    catch (std::string e) {  // e and the thrown object are std::strings
        std::cout << "Division by zero. " << e << std::endl;
    }

    // throwing a MyException object (custom made)
    try {
        if (y == 0)
            throw MyException();
        z = x / y;
        std::cout << "z: " << z << std::endl;
    }
    catch (MyException e) {  // e and the thrown object are MyExceptions
        std::cout << "Division by zero. (MyException)" << std::endl;
    }

    // throwing a MyException FROM a function call
    try {
        z = division(x, y);
        std::cout << "z: " << z << std::endl;
    }
    catch (MyException e) {  // e and the thrown object are MyExceptions
        std::cout << "Division by zero. (MyException)" << std::endl;
    }

    return 0;
}