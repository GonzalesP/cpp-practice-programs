#include <iostream>

class Base {
public:
    void fun1() {
        std::cout << "fun1 of Base" << std::endl;
    }
};
class Derived : public Base {
public:
    void fun2() {
        std::cout << "fun2 of Derived" << std::endl;
    }
};

int main() {
    Derived d;
    d.fun1();
    d.fun2();

    // pointer of Base, object of Derived
    Base* ptr = &d;
    ptr->fun1();
    // ptr->fun2();  - fun2() is not present in Base, only Derived
    // when you use a pointer of Base, it will only look for the functions that
    // Base class can use (i.e., fun1())

    Base b;
    // Derived *ptr = &b;  - cannot assign address of base class to derived ptr
    // derived classes may have extra features that a Base object cannot access

    return 0;
}