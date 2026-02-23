#include <iostream>

class BasicCar {
public:
    virtual void start() {
        std::cout << "BasicCar started" << std::endl;
    }
};
class AdvancedCar : public BasicCar {
public:
    void start() {
        std::cout << "AdvancedCar started" << std::endl;
    }
};

int main() {
    BasicCar* p = new AdvancedCar();
    p->start();  // "Advanced Car started"
    // pointers will call virtual functions
    // based on the object itself (not the class type)

    // without "virtual", p would call BasicCar's start() function.

    return 0;
}