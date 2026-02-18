#include <iostream>

class Rectangle
{
    private:
        int length;
        int breadth;
    public:
        // constructors (no return type!)
        // once constructor created, compiler constructor is no longer used
        
        // non-parameterized constructor (aka "default con.")
        Rectangle()
        {
            length = 1;
            breadth = 1;
        }

        // parameterized constructor (user chooses values)
        Rectangle(int l, int b)
        {
            setLength(l);  // already programmed to handle misinputs!
            setBreadth(b);  // i.e., nothing less than 0
        }
        // note: in the future, you can write less code by providing default arg
        // e.g., if user doesn't enter l/b, set it = 1 by default
        // it will have the same behavior as non-parameterized constructor
        // i.e., you can have a two in one constructor in this case
            // Rectangle(int l = 1, int b = 1)

        // copy constructor (creates a Rectangle based on another existing Rect)
        Rectangle(Rectangle& r)
        {  // use reference so that you don't create another copy of r
            length = r.length;
            breadth = r.breadth;
        }


        // mutators
        void setLength(int l) {
            if (l > 0)
                length = l;  // set negative values to 1
            else
                length = 1;
        }
        void setBreadth(int b) {
            if (b > 0)
                breadth = b;
            else
                breadth = 1;
        }


        // accessors
        int getLength() {
            return length;
        }
        int getBreadth() {
            return breadth;
        }


        // calculation functions
        int area() {
            return length * breadth;
        }
        int perimeter() {
            return 2 * (length * breadth);
        }
};

int main() {
    Rectangle r1;  // 1 x 1: non-parameterized con. called
    std::cout << "r1 area: " << r1.area() << std::endl;  // 1

    Rectangle r2(10, 5);  // 10 x 5: parameterized con. called
    std::cout << "r2 area: " << r2.area() << std::endl;  // 50

    Rectangle r3(r2);  // copy con. called: copies r2 -> 10 x 5
    std::cout << "r3 area: " << r3.area() << std::endl;  // 50 (same as r2)

    return 0;
}