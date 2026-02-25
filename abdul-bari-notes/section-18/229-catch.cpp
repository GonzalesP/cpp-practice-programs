#include <iostream>
#include <string>

// a try statement can have multiple catch blocks
// one special type of catch block is the catch All block, which uses (...)
// this will catch all thrown exceptions, regardless of data type
// it MUST be written last so that more specific exceptions are handled first

// note: if there is a missing catch() block for a certain data type exception,
// the program will crash during runtime - "uncaught exception"

// custom exceptions
class MyException1 : std::exception {};
class MyException2 : public MyException1 {};
// note: child exceptions should be caught first! if you catch(parent) first,
// the child exception may be caught in the parent block, because the
// child class IS-A parent

int main() {
    int test = 0;
    try {
        // throw 1;  - Int Catch
        // throw 1.5;  - Double Catch
        // throw 'a';  - All Catch
        throw std::string("hi");  // All Catch
    }
    catch (int e) {
        std::cout << "Int Catch" << std::endl;
    }
    catch (double e) {
        std::cout << "Double Catch" << std::endl;
    }
    catch (...) {  // MUST COME LAST!!!
        std::cout << "All Catch" << std::endl;
    }
    // "if any catch block is not available for a specific type of data, the
    // catch All block will be executed (i.e., it is a universal catch)"

    try {
        // throw MyException1();
        throw MyException2();
    }
    // catch Child exception first!
    // or else Parent catch can possibly skip the Child-specific catch
    catch (MyException2 e) {  // catches ME2 only (specific)
        std::cout << "MyException2 Catch" << std::endl;
    }
    catch (MyException1 e) {  // ME1 AND ME2 (more general)
        std::cout << "MyException1 Catch" << std::endl;
    }

    return 0;
}