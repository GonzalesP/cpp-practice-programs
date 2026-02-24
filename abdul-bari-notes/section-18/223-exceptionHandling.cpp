#include <iostream>

int main() {
    int x = 10, y = 0, z;
    
    std::cout << std::endl;
    std::cout << "TRY CATCH BLOCK 1" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z = x / y" << std::endl;
    try {
        if (y == 0)
            throw 1;
        z = x / y;  // during runtime, causes division by zero error (crash)
        std::cout << "z: " << z << std::endl;
        // checking y before division prevents program from crashing
            // the 'throw' statement will make program jump to catch block
            // (without executing z = x / y; and so on)
    }
    catch (int e) {
        std::cout << "Error " << e << ": Division by zero" << std::endl;
    }
    std::cout << "END OF BLOCK 1" << std::endl;
    // at the end of try catch block, program will always end up here
    // (regardless if try() was successful or if catch() executes)

    y = 2;

    std::cout << std::endl;
    std::cout << "TRY CATCH BLOCK 2" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z = x / y" << std::endl;
    try {
        if (y == 0)
            throw 1;
        z = x / y;  // y is not zero, this part can run with no problem
        std::cout << "z: " << z << std::endl;  // z is printed out properly
    }
    catch (int e) {  // catch() block is skipped (no exception to catch)
        std::cout << "Error " << e << ": Division by zero" << std::endl;
    }
    std::cout << "END OF BLOCK 2" << std::endl;
    
    std::cout << std::endl;
    return 0;
}