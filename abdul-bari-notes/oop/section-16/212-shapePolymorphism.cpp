#include <iostream>

class Shape {
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};
class Rectangle : public Shape {
private:
    float length;
    float breadth;
public:
    Rectangle(float l = 1.0f, float b = 1.0f) {
        l >= 1.0f ? length = l : length = 1.0f;
        b >= 1.0f ? breadth = b : breadth = 1.0f;
    }
    float area() {
        return length * breadth;
    }
    float perimeter() {
        return 2.0f * (length + breadth);
    }
};
class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r = 1.0f) {
        r >= 1.0f ? radius = r : radius = 1.0f;
    }
    float area() {
        return 3.141593f * radius * radius;
    }
    float perimeter() {
        return 2.0f * 3.141593f * radius;
    }
};

int main() {
    Shape* s;

    std::cout << std::endl;
    std::cout << "S will turn into a 10 x 5 Rectangle." << std::endl;
    s = new Rectangle(10.0f, 5.0f);
    std::cout << "Area of S: " << s->area() << std::endl;
    std::cout << "Perimeter of S: " << s->perimeter() << std::endl;
    delete s;

    std::cout << std::endl;
    std::cout << "S will turn into a Circle with 10 radius." << std::endl;
    s = new Circle(10.0f);
    std::cout << "Area of S: " << s->area() << std::endl;
    std::cout << "Perimeter of S: " << s->perimeter() << std::endl;
    delete s;

    std::cout << std::endl;
    return 0;
}