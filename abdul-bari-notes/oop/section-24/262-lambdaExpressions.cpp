#include <iostream>

// lambda expressions are used to create nameless functions
// they behave similarly to inline functions (?)

int main() {
    // nameless function definition (no call, Hello will not be printed)
    [](){ std::cout << "Hello" << std::endl; };
        // [] - capture list (capture variables outside of lambda's scope)
        // () - parameter list (used as input for function)
        // {} - lambda body
    
    // to call a lambda function, replace ; with (); at the end of {}
    [](){ std::cout << "Hi" << std::endl; }();  // prints Hi

    // () - can be used to give the function parameters
    [](int x, int y){ std::cout << "x+y=" << x+y << std::endl; }(10, 30);  // 40

    // lambda functions can also return values
    std::cout << ([](int x, int y){ return x+y; }(2, 2)) << std::endl;  // 4
        // returns 2+2 (4), which will be inserted into std::cout
        // if you're going to use lambda function in cout,
        // you need to wrap it in ()

    int a = [](int x, int y){ return x+y; }(10, 10);  // a = 20
        // no need to wrap lambda in () if it's not in <<
    

    // lambda functions will automatically assign return types, but if you want
    // to write down the return type explicitly, you can use
    // -> returnType before {}  for e.g.,
    int b = [](int x, int y) -> int { return x+y; }(7,7);  // 14
    
    std::cout << "a: " << a << std::endl;  // 20
    std::cout << "b: " << b << std::endl;  // 14


    // normally, lambda functions are not able to access variables outside
    // of their scope. however, when you put variables in the capture list [],
    // they become accessible

    [a](){ std::cout << "a - 1: " << a - 1 << std::endl; }();  // 19
        // a is passed (captured?) by value
    
    // note: when a variable is captured (?) by value, it CANNOT be modified
    // for example, the above lambda expression CANNOT use a--;

    
    // if you want to allow a lambda function to MODIFY outside variables,
    // you need to capture (?) the variables by reference &
    [&a](){ std::cout << "++a: " << ++a << std::endl; }();  // a becomes 21


    // you can also assign lambda functions to REFERENCE variables using auto:

    auto f = [a](){ std::cout << a << std::endl; };
        // f is a reference to this lambda function.
    f();  // calls the same lambda funciton - prints 21

    // IMPORTANT NOTE: when capturing a variable WITHOUT reference, the variable
    // will stay constant throughout its lifetime! (i.e., it will not change,
    // even if the captured variable is modified outside of the function)

    a++;  // a becomes 22
    f();  // prints 21 because a was 21 when it was captured (does not change!)


    // if you want a lambda function to access a variable's ACTUAL value,
    // you must capture by reference

    auto ff = [&a](){ std::cout << a << std::endl; };
    ff();  // prints 22
    a++;
    ff();  // prints 23  - you can also use a++ inside ff() because of &

    return 0;
}