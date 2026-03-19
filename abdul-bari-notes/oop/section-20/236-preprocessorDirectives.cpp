#include <iostream>

// preprocessor directives are commands for the compiler to follow before
// compilation starts. for instance, #include is a preprocessor directive
// that asks the compiler to include a library in the program (to use all
// the classes, objects, and functions it has to offer)

// another example of p. directives is #define, which can be used to create
// symbolic constants as well as functions

// every instance of 'PI' in the program is replaced with 3.141953
// before compilation begins (no space occupied, not a variable at all)
#define PI 3.141593

// note: you should not redefine macros (aka preprocessor directives)
// #define PI 3  - doing this after the above define may cause problems


// the #ifndef __ macro ("if not defined") is used to define things AS LONG AS
// they have not been defined already
#ifndef PI
    #define PI 3
#endif  // "if PI is not defined, use #define PI 3"


// #define can be used to create functions like so:
#define max(x,y) (x>y?x:y)  // every instance of max(x,y) is replaced
                            // with the ternary expression (x>y?x:y)
// the () are REQUIRED to write functions (i.e., just x>y?x:y is a syntax error)


// #define can also be used to create strings (i.e., wrap a parameter in "")
#define msg(x) #x
    // whatever is passed in x will become "x"

int main() {
    // compiler replaces PI with 3.141593
    std::cout << PI << std::endl;

    std::cout << max(10,12) << std::endl;  // 12

    std::cout << msg(hello there) << std::endl;  // "hello there"
        // msg() wraps hello there in double quotes

    return 0;
}