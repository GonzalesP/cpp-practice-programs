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
    // Creating a Rectangle object (i.e., instance)
    Rectangle r1;  // created in the stack
    r1.length = 10;
    r1.breadth = 5;
    std::cout << "Area of r1 is: " << r1.area() << std::endl;
    std::cout << "Perimeter of r1 is: " << r1.perimeter() << std::endl;

    // Using pointers

    // Pointer to a Rectangle created in the STACK
    Rectangle r2;
    Rectangle *ptrA = &r2;
    ptrA->length = 5;
    ptrA->breadth = 3;
    std::cout << "Area of r2 is: " << ptrA->area() << std::endl;  // 50
    std::cout << "Perimeter of r2 is: "
              << ptrA->perimeter() << std::endl;  // 30

    // Pointer to a Rectangle created in the HEAP
    Rectangle *ptrB = new Rectangle;
    ptrB->length = 15;
    ptrB->breadth = 10;
    std::cout << "Area of ptrB is: " << ptrB->area() << std::endl;  // 150
    std::cout << "Perimeter of ptrB is: "
              << ptrB->perimeter() << std::endl;  // 150

    delete ptrB;  // delete is for a single, non-array object
    ptrB = nullptr;  // delete[] is for an ARRAY of objects

    // make sure to use the right delete, or else undefined behavior occurs

    return 0;
}