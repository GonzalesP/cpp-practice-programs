#include <iostream>

// there are three methods to passing parameters into functions
// 1. pass by value
// 2. pass by address
// 3. pass by reference


// pass by value DOES NOT modify the actual parameters (passed by main)
// it should be used when the parameters are only needed for their data
// i.e., returning data after calculations/operations
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
// note: when this is called by main(), the variables declared in main WILL NOT
// swap. this is because int a and b are part of the activiation record of swap.
// when swap terminates, all of its content is removed from the stack, which
// includes int a and b


// pass by address uses pointers to access variables from outside functions
// to access AND modify the data of the actual parameters, you use
// the deallocation operator *
void swapByAddress(int *a, int *b) {
    int temp = *a;  // *a gives the value stored at address a
    *a = *b;  // give the value stored at address b to address a
    *b = temp;  // give b the vlaue previously stored at address a
}
// note: a and b are addresses, *a will give the value of the parameter passed
// by main() (i.e., x), and *b will do the same with the other parameter
// lastly, since a and b are pointers, the calling function needs to use &
// to pass the actual addresses!


// pass by reference will treat the formal parameters like aliases for
// the actual parameters. in machine code, this function will be copied
// into the main() function's machine code.
void swapByReference(int &a, int &b) {
    int temp = a;  // same variable as x from main (don't need dereference *)
    a = b;
    b = temp;
}
// a is an alias for main's x, and b is an alias for main's y

int main() {
    int x, y;
    
    // pass by value
    x = 10;
    y = 20;

    std::cout << std::endl;
    std::cout << "DEMO: pass by value" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    std::cout << "*swap: pass by value...*" << std::endl;
    swapByValue(x, y);  // note: will NOT actually swap
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    // pass by address
    x = 10;
    y = 20;

    std::cout << std::endl;
    std::cout << "DEMO: pass by address" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "&x: " << &x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "&y: " << &y << std::endl;

    std::cout << "*swap: pass by address...*" << std::endl;
    swapByAddress(&x, &y);  // WILL swap, also need to pass addresses (use &)!
    std::cout << "x: " << x << std::endl;
    std::cout << "&x: " << &x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "&y: " << &y << std::endl;

    return 0;
}