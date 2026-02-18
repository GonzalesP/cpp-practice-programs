#include <iostream>

class Rectangle
{
public:
    int length;
    int breadth;

    int area() {
        return length * breadth;
    }
    int perimeter() {
        return 2 * (length + breadth);
    }
};

int main() {
    Rectangle r1;
    r1.length = 10;
    r1.breadth = 5;
    std::cout << "Area of r1 is: " << r1.area() << std::endl;
    std::cout << "Perimeter of r1 is: " << r1.perimeter() << std::endl;

    return 0;
}