#include <iostream>

class Base {
public:
    void fun1() {
        std::cout << "fun1 of Base" << std::endl;
    }
    virtual void fun2() {
        std::cout << "(virtual) fun2 of Base" << std::endl;
    }
};
class Derived : public Base {
public:
    void fun1() {  // overrides Base::fun1()
        std::cout << "fun1 of Derived" << std::endl;
    }
    void fun2() {  // overrides Base::fun2(), AND used by Base pointers as well
        std::cout << "fun2 of Derived" << std::endl;
    }
};

int main() {
    // Base pointers will call a Base's functions, even if overriden
    Derived d;
    d.fun1();  // fun of Derived

    Base* ptr = &d;
    ptr->fun1();  // fun of Base  - ptr expects d to behave like a Base object


    // In order to use the overriden functions, the function needs to be virtual

    ptr->fun2();  // if fun2 was not overriden, it would print virtual fun2 of B
    // however, since it IS overriden in the Derived class,
    // fun2 of Derived is printed instead

    return 0;
}

// "When a base class function is virtual, the function call will not be based
// on the POINTER, but rather the OBJECT"