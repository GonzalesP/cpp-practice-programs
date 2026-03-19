#include <iostream>

int g = 5;  // global variable: accessible by all functions
// exists as long as the program is running

void fun() {
    int a = 10;  // local variable: only accessible inside fun()
    a++;
    g++;
    std::cout << a << " " << g << std::endl;  // 11 6
}
// since a is local, it will be removed from memory once fun() terminates


void fun2() {
    int g = 10;  // can make local variables share names as global ones
    g++;  // the local variable g will be incremented
}
// compiler looks for declaration of variable in NEAREST SCOPE


// you can create inner scopes to create more local variables with shared names
// to use a global variable, you can use the scope resolution operator ::
void fun3() {
    int g = 10;
    {
        int g = 0;  // inner local g will be prioritized in this scope
        g++;
        std::cout << "'inner' g: " << g << std::endl;  // 1 (inner local g)
    }
    // outer local g is used because at this point, the inner scope is exited
    std::cout << "'outer' g: " << g << std::endl;  // 10 (from outer local g)
    
    // to use global g, you can use the scope resolution operator
    std::cout << "'global' g: " << ::g << std::endl;  // 6 (global g)
}


int main() {
    std::cout << "g: " << g << std::endl;  // 5
    std::cout << "*fun()...*" << std::endl;
    fun();  // g becomes 6 inside fun() - also prints 11 6
    std::cout << "g: " << g << std::endl;  // 6

    std::cout << std::endl;
    std::cout << "*fun2()...*" << std::endl;
    fun2();  // fun2's local g is modified, not global g
    std::cout << "g: " << g << std::endl;  // so, global g is still = 6

    std::cout << std::endl;
    std::cout << "*fun3()...*" << std::endl;
    fun3();  // will print 1, 10, and 6

    return 0;
}