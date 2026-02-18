#include <iostream>

class Rectangle
{
// OOP principle: data should not be directly accessible to prevent misuse
private:
    int length;
    int breadth;

// since length and breadth are private, you'll need accessors and mutators
// aka getters and setters
public:
    // mutators

    // benefit of mutator: you can incorporate logic to prevent users from
    // misusing the class (e.g., don't allow negative values for length)
    // "this is a form of input validation"
    void setLength(int l) {
        if (l < 0)
            length = 1;  // set negative values to 1
        else
            length = l;
    }
    void setBreadth(int b) {
        if (b < 0)
            breadth = 1;
        else
            breadth = b;
    }

    // accessors
    int getLength() {
        return length;
    }
    int getBreadth() {
        return breadth;
    }

    int area() {
        return length * breadth;
    }
    int perimeter() {
        return 2 * (length * breadth);
    }
};

int main() {
    Rectangle r1;
    // r1.length = 10;  // not allowed since length is private! need mutator!
    r1.setLength(10);
    r1.setBreadth(5);

    std::cout << "r1 area: " << r1.area() << std::endl;  // 50
    // std::cout << r1.length << std::endl;  // need accessor!
    std::cout << "r1 length: " << r1.getLength() << std::endl;  // 10

    // r1.setLength(-10);  // will be set to 1 instead

    return 0;
}