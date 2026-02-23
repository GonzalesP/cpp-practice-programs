#include <iostream>

// when a class has a pure virtual function, it becomes an "Abstract Class"
// Abstract classes cannot be instantiated (i.e., no Objects can be made)
// they can only have pointers
class Car {
public:
    virtual void start() = 0;  // setting a virtual function = 0; makes it a
    // "pure virtual function"
    // these functions MUST be implemented (overriden) by deriving classes.
    // otherwise, the derived class will ALSO become abstract.
};
// when a function ONLY has pure virtual functions, it can also be referred to
// as an "interface"

class Innova : public Car {
public:
    // overriding pure virtual functions make a class "Concrete",
    // opposite of Abstract
    void start() {
        std::cout << "Innova started" << std::endl;
    }
};
class Swift : public Car {
public:
    void start() {
        std::cout << "Swift started" << std::endl;
    }
};

int main() {
    // Car c;  // error: Car is an abstract class, it cannot have objects!
    Car* p;  // pointers are allowed for abstract classes

    p = new Innova();
    p->start();
    delete p;

    p = new Swift();
    p->start();
    delete p;
    
    return 0;
}

// "virtual functions are used to achieve polymorphism"
// "the purpose of PURE virtual functions is to FORCE child classes to override
// them within their own classes - otherwise they become abstract classes too"