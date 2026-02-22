#include <iostream>

class Base {
public:
    void display() {
        std::cout << "Display of Base" << std::endl;
    }
};
class Derived1 : public Base {
    // no contents - if display() called, it will use the method from Base
};
class Derived2 : public Base {
public:
    // function overriding occurs when a function from the Base class
    // is redefined in the Derived class
    void display() {
        std::cout << "Display of Derived" << std::endl;
    }
};

int main() {
    Base b;
    b.display();  // Display of Base

    Derived1 d1;
    d1.display();  // Display of Base - inherited from Base

    Derived2 d2;
    d2.display();  // Display of Derived - overriden function
        // does not need to "borrow" the function from Base

    // NOTE: function overriding requires the same function SIGNATURE
        // e.g., if Derived2::display was display(int x)
        // then there would be two separate functions, AND an error would occur
        // because d2.display() would be missing an int parameter
    
    // If you want to call a non-overriden function (i.e., use the function
    // defined in the Base class), use the scope resolution operator
    d2.Base::display();  // Display of Base

    return 0;
}