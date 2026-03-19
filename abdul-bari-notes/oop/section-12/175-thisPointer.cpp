#include <iostream>

class Rectangle
{
private:
    int length;
    int breadth;
public:
    // before, parameter names used int l, int b
    // but if you want to reuse names in parameters and need
    // to distinguish variables, you can use the this pointer
    Rectangle(int length, int breadth)
    {
        // this won't work because local var will be prioritized! (scope):
        // length = length;  // assigning its own value to itself
        // breadth = breadth;

        // 'this' is a pointer to the CURRENT object (i.e., the one
        // invoking this constructor method)
        this->length = length;
        this->breadth = breadth;

        // "this object's (int) length will be assigned the value
        // given by the parameter variable length"
    }

    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

int main () {
    Rectangle r1(10, 5);
    return 0;
}