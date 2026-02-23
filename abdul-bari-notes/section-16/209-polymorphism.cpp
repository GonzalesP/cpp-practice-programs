#include <iostream>

// generalized class
class Car {
public:
    virtual void start() {
        std::cout << "Car started" << std::endl;
    }
};
class Innova : public Car {
public:
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
    Car* p = new Innova();
    p->start();  // Car start() is virtual -> calls Innova's start() instead
    delete p;    // "Innova started"

    p = new Swift();
    p->start();  // same statement, but now SWIFT's start() is called
    delete p;    // "Swift started"

    // this is an example of polymorphism, where a pointer to one object will
    // point to another object of a different type, but same parent class
    // and, since the parent class's functions are virtual,
    // they can be overriden by each of the subclasses,
    // producing different results when switching

    return 0;
}