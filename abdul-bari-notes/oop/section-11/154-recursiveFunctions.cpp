#include <iostream>

// a recursive function is one that calls itself
// each call will pass a different value
void fun1(int n) {
    if (n > 0) {
        // first 5 will be printed by fun1(5)
        // then 4 by fun1(4), which is called by fun1(5)
        // then 3 by fun1(3), which is called by fun1(4) ...
        // once n = 0, there will be no more prints/recursive calls

        std::cout << n << std::endl;
        fun1(n - 1);
    }
}
// note: every recursive function needs a base case that will stop future calls
// (i.e., terminate). otherwise, an infinite loop will occur


void fun2(int n) {
    if (n > 0) {
        // first, fun2(5) is called, which calls fun2(4)
        // which calls fun2(3), which calls fun2(2) ...
        // eventually n = 0 when fun2(0) is called, which will
        // stop recursive calls

        // so, with fun2(0) over, fun2(1) continues, and prints 1
        // then fun2(1) ends and fun2(2) continues, and prints 2
        // then fun2(2) ends and fun2(3) continues, ...
        // until fun2(5) prints 5 and finishes the last fun2 call
        fun2(n - 1);
        std::cout << n << std::endl;
    }
}

int main() {
    std::cout << "*fun1()...*" << std::endl;
    fun1(5);  // prints 5 4 3 2 1

    std::cout << "*fun2()...*" << std::endl;
    fun2(5);  // prints 1 2 3 4 5

    return 0;
}