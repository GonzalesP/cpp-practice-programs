#include <iostream>

class Base {
public:
    void fun1() {
        std::cout << "fun1 from Base" << std::endl;
    }
    virtual void fun2() = 0;  // must be overriden - Abstract
};
class Derived : public Base {
public:
    void fun2() {
        std::cout << "fun2 of Derived" << std::endl;
    }
};

int main() {
    // Base provides both reusability and polymorphism
    Derived d;
    d.fun1();  // reusability (use a function defined in Base)
    d.fun2();  // polymorphism

    // if fun1 was virtual, the only purpose of Base would be to achieve
    // polymorphism, not reusability. Base would also become an "interface"

    return 0;
}