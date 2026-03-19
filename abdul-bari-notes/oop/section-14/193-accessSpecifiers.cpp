#include <iostream>

class Rectangle {
private:
    int length;
    int breadth;
public:
    // to read and write the private data members, you need
    // public accessors and mutators
    void setLength(int l) {
        if (l > 0)
            length = l;
        else   
            length = 1;
    }
    void setBreadth(int b) {
        if (b > 0)
            breadth = b;
        else   
            breadth = 1;
    }
    int getLength() { return length; }
    int getBreadth() { return breadth; }

    int area() {
        return length * breadth;
    }
    int perimeter () {
        return 2 * (length + breadth);
    }
};

int main() {
    Rectangle r1;
    // r1.length=10;  error: length and breadth are private
    // r1.breadth=5;

    r1.setLength(10);
    r1.setBreadth(5);
    std::cout << r1.area() << std::endl;  // allowed bc public
    std::cout << "Length: " << r1.getLength() << std::endl;
    std::cout << "Breadth: " << r1.getBreadth() << std::endl;
    
    return 0;
}