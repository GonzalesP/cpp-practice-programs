#include <iostream>

class Base {
    public:
        int a;
        void display() {
            std::cout << "Display of Base " << a << std::endl;
        }
};
class Derived : public Base {
    public:
        void show() {
            std::cout << "Show of Derived" << std::endl;
        }
};

int main() {
    Base b;
    b.a = 100;
    b.display();  // "Display of Base"

    Derived d;
    d.a = 100;
    d.display();  // "Display of Base"
    d.show();  // "Show of Derived"

    return 0;
}