#include <iostream>

// static variables persist throughout program's run
// (i.e., same data is saved even when function terminates)

// however, they are NOT accessible outside of their function,
// unlike global variables
void staticTest() {
    static int totalCalls = 0;  // declared and initialized ONCE
    int a = 5;  // created/removed everytime function starts/ends
    totalCalls++;

    std::cout << "a (local): " << a << std::endl;
    std::cout << "totalCalls (static): " << totalCalls << std::endl;
    std::cout << std::endl;
}
// totalCalls will maintain its value, even when staticTest() terminates
// its value will be preserved throughout the program's duration

int main() {
    std::cout << "*calling staticTest()...*" << std::endl;
    staticTest();  // 5 1
    std::cout << "*calling staticTest()...*" << std::endl;
    staticTest();  // 5 2
    std::cout << "*calling staticTest()...*" << std::endl;
    staticTest();  // 5 3
    std::cout << "*calling staticTest()...*" << std::endl;
    staticTest();  // 5 4

    // since it is a static variable, int totalCalls will maintain
    // its value throughout the program's duration and all
    // function calls/terminations

    return 0;
}