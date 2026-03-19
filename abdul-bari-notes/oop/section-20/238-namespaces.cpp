#include <iostream>

// namespaces are used to distinguish independent functions that share
// the same name (outside of classes/objects)  e.g., global functions

namespace First {
    void fun() {
        std::cout << "First" << std::endl;
    }
};

namespace Second {
    void fun() {
        std::cout << "Second" << std::endl;
    }
};
// both functions are called fun(), but they are distinguished
// by their namespaces. without the namespaces, the compiler would
// give a syntax error for function redefinition



// if you want to avoid rewriting the scope operator over and over again
// when using one namespace for the majority of the program, you can use
// a "using namespace" statement:

// using namespace First;
// using namespace Second;

int main() {
    First::fun();  // First
    Second::fun();  // Second

    // if 'using namespace First;' was used, you wouldn't have to write
    // First:: in order to use First's fun().
    // however, when using namespace First, you will need Second:: when you
    // want to use Second's fun() instead.

    return 0;
}

// another prominent example of a namespace is the std namespace
// which provides a lot of classes/objects commonly used in C++ programs
    // e.g. std::cout