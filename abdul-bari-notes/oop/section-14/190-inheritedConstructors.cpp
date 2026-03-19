#include <iostream>

// when an object of a Derived class is created, a constructor of the Base class
// will be called first (e.g., Base non-parameter/parameter constructor, etc.).
// then, a constructor of the Derived class will be called next.

// in order to choose which constructors are used, you need to use :

class Base {
    public:
        Base() { std::cout << "Non-param of Base" << std::endl; }
        Base(int x) { std::cout << "Param of Base " << x << std::endl; }
};
class Derived : public Base {
    public:
        // the non-param Base() constructor will be called by default
        Derived() { std::cout << "Non-param of Derived" << std::endl; }
        Derived(int y) { std::cout << "Param of Derived " << y << std::endl; }

        // in order to access the param Base(int x) constructor,
        // you need   : Base(x) - here, the Param Base(int) constructor will
        // be called, and the parameter x will be passed into it.
        // afterwards, the rest of this Derived constructor will execute.
        Derived(int x, int y) : Base(x) {
            // Base(x) will print "Param of Base x"
            std::cout << "Param of Derived " << y << std::endl;
        }
};

int main() {
    // Base() default constructor will be used by default
    // when using Derived constructors

    std::cout << "Creating d1:" << std::endl;
    Derived d1;  // calls Base() first and then Derived()
        // "Non-param of Base" \n "Non-param of Derived" \n

    std::cout << std::endl;
    std::cout << "Creating d2:" << std::endl;
    Derived d2(10);  // calls Base() first and then Derived(10)
        // "Non-param of Base" \n "Param of Derived 10" \n
    
    
    // To use a specific Base constructor, you need to design a specialized
    // Derived constructor that calls upon the specific Base constructor
    std::cout << std::endl;
    std::cout << "Creating d3:" << std::endl;
    Derived d3(5, 10);  // calls Base(5) first and then Derived(10)
        // "Param of Base 5" \n "Param of Derived 10" \n
    return 0;
}