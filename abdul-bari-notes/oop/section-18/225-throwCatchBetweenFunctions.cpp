#include <iostream>

// the throw-catch logic can also be used to allow functions to communicate
// with each other. for e.g., division will decide whether or not a result
// can be returned, and give the proper reaction to main
// (i.e., either throw an exception or return a result)
int division(int a, int b) {
    // if (b != 0)
    //     return a / b;  // problem: non-void may not reach return
    // including an else statement for return will return junk
    // instead of communicating an error message via throw

    // better approach: deal with problems first, then have return at end
    if (b == 0)
        throw 1;
    return a / b;
}

int main() {
    int x = 10, y = 0, z;

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    try {
        std::cout << "z = division(x, y)" << std::endl;
        z = division(x, y);
        std::cout << "z: " << z << std::endl;
    }
    catch (int e) {
        std::cout << "Error " << e << ": Division by zero" << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}