#include <iostream>
// library provides built in objects or functions
// these will be attached to the program by the compiler

// main - starting point of all C++ programs (int return type)
int main()
{
    // built in object - cout (console out) to print text onto monitor
    // std - standard namespace (has the cout object)
    // :: - scope resolution
    // << - insertion operator, gives a string to cout
    std::cout << "Hello, world!" << std::endl;

    return 0;
}

// can also add 'using namespace std;' before main to avoid using std::
// but less efficient bc you're not using everything from std

// to compile, navigate to directory and use g++ First.cpp
// to run, use ./a