#include <iostream>

// to demonstrate inheritance, here are two classes: Rectangle and Cuboid
// Cuboid is derived from Rectangle and inherits its properties,
// including length and breadth

class Rectangle {
private:
    int length;
    int breadth;
public:
    Rectangle();
    Rectangle(int, int);
    Rectangle(Rectangle& r);
    int getLength() {return length;}
    int getBreadth() {return breadth;}
    void setLength(int l);
    void setBreadth(int b);
    int area();
    int perimeter();
    bool isSquare();
    ~Rectangle();
};

class Cuboid : public Rectangle {
private:
    int height;
public:
    Cuboid(int h = 1) {height = h;}
    int getHeight() {return height;}
    void setHeight(int h) {height = h;}
    int volume(){
        // return length * breadth * height;  // not allowed!
        // private members of a base class are not accessible in derived classes
        return getLength() * getBreadth() * height;
    }
};

int main() {
    Cuboid c(5);  // height = 5, default Rectangle() used to set l=1, b=1
    c.setLength(10);
    c.setBreadth(7);
    std::cout << "Volume is " << c.volume() << std::endl;  // 350

    return 0;
}


// Rectangle member functions
Rectangle::Rectangle() {
    length = 1;
    breadth = 1;
}
Rectangle::Rectangle(int l, int b) {
    length = l;
    breadth = b;
}
Rectangle::Rectangle(Rectangle& r) {
    length = r.length;
    breadth = r.breadth;
}
void Rectangle::setLength(int l) {
    length = l;
}
void Rectangle::setBreadth(int b) {
    breadth = b;
}
int Rectangle::area() {
    return length * breadth;
}
int Rectangle::perimeter() {
    return 2 * (length + breadth);
}
bool Rectangle::isSquare() {
    return length == breadth;
}
Rectangle::~Rectangle() {
    // deleting Rectangle
}