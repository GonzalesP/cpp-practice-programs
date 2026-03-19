#include <iostream>

class Rectangle
{
private:
    int length;
    int breadth;
public:
    // Constructors
    Rectangle();
    Rectangle(int l, int b);
    Rectangle(Rectangle &r);
    // Accessors
    int getLength();
    int getBreadth();
    // Mutators
    void setLength(int);   // no need to give parameter variable names
    void setBreadth(int);  // in prototypes
    // Facilitators
    int area();
    int perimeter();
    // Inquiry - gather info about an object
    bool isSquare();
    // Destructor - deconstruct (delete) an object
    ~Rectangle();
};

int main () {
    Rectangle r1(10, 10);
    std::cout << "r1 area: " << r1.area() << std::endl;
    if (r1.isSquare()) {
        std::cout << "r1 is a square" << std::endl;
    }
    return 0;

    // at the end of main(), the destructor of Rectangle is automatically called
}

// when you define functions inside their class, the machine code
// will generate inline functions (repeated code) inside main

// however, if you use function PROTOTYPES inside a class, AND define
// them outside of the class, the compiler will generate the machine code
// for the functions SEPARATELY from the mc for the main function.
// this will reduce code size and increase efficiency (:
    // you should especially avoid generating inline functions when
    // complex logic gets involved!

// in order to define functions outside of their classes, you need to use
// the scope resolution operator to indicate that said function is THE SAME
// function as the PROTOTYPE declared INSIDE the class

// without the scope resolution operator, this function WILL NOT belong to
// the class (and will be treated as a separate function, while the class
// will remain WITHOUT an implementation for its prototype)



// CLASS METHODS

// constructors
Rectangle::Rectangle() {
    length = 1;
    breadth = 1;
}
Rectangle::Rectangle(int l, int b) {
    setLength(l);
    setBreadth(b);
}
Rectangle::Rectangle(Rectangle &r) {
    length = r.length;
    breadth = r.breadth;
}

// accessors
int Rectangle::getLength() {
    return length;
}
int Rectangle::getBreadth() {
    return breadth;
}

// mutators
void Rectangle::setLength(int l) {  // implemented functions need var names
    if (l > 0)
        length = l;
    else
        length = 1;
}
void Rectangle::setBreadth(int b) {  // implemented functions need var names
    if (b > 0)
        breadth = b;
    else
        breadth = 1;
}

// facilitators
int Rectangle::area() {
    return length * breadth;
}
int Rectangle::perimeter() {
    return 2 * (length + breadth);
}

// inquiry
bool Rectangle::isSquare() {
    return length == breadth;
}

// destructor
Rectangle::~Rectangle() {
    std::cout << "Rectangle Destroyed." << std::endl;
}