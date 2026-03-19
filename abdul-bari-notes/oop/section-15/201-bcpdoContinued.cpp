#include <iostream>

class Rectangle {
public:
    void area() {
        std::cout << "Area of Rectangle" << std::endl;
    }
};
class Cuboid : public Rectangle {
public:
    void volume() {
        std::cout << "Cuboid Volume" << std::endl;
    }
};


class BasicCar {
public:
    void start() {
        std::cout << "Car started" << std::endl;
    }
};
class AdvancedCar : public BasicCar {
public:
    void playMusic() {
        std::cout << "Music playing" << std::endl;
    }
};


int main() {
    Cuboid c;
    c.area();
    c.volume();

    Rectangle* p = &c;
    p->area();
    // p->volume();  - Even though c is a cuboid, the pointer p believes
    // that you are pointing to a Rectangle object. So, p does not have the
    // full knowledge of the Cuboid class.

    Rectangle r;
    // Cuboid* q = &r;  - you cannot call a Rectangle a Cuboid bc it's 2D not 3D



    AdvancedCar a;
    a.start();
    a.playMusic();

    BasicCar* ptr = &a;
    ptr->start();
    // ptr->playMusic();  - BasicCars cannot playMusic
    // a is viewed/treated as a BasicCar because ptr is a BasicCar*

    BasicCar b;
    // AdvancedCar* q = &b;  - b is not an advanced car
    // it cannot play music, so it cannot be viewed as an advanced car
    // and so, an AdvancedCar pointer cannot point to it (i.e. save its address)

    return 0;
}