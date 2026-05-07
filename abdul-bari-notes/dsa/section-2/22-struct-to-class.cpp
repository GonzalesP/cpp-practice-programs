#include <iostream>

struct RectangleA {
    int length;  // data members are public by default
    int breadth;
};

// in C, structs are usually passed into functions by address or value.
// to update a struct's data members from an outside function,
// you need to pass by address (so that the actual parameter will change too)
void initialize(struct RectangleA* r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

int area(struct RectangleA r) {
    return r.length * r.breadth;
}

void changeLength(struct RectangleA* r, int l) {
    r->length = l;
}


class RectangleB {
    private:  // data members are private by default
        int length;
        int breadth;
    public:
        // instead of using a function for initialization, use a constructor
        // this will allow simultaneous declaration and initialization
        RectangleB(int l, int b) {
            length = l;
            breadth = b;
        }

        // since functions are a part of the class, they have direct access
        // to the data members
        int area() {
            return length * breadth;
        }

        void changeLength(int l) {
            length = l;
        }
};

int main() {
    // struct
    struct RectangleA r1;
    initialize(&r1, 10, 5);
    std::cout << area(r1) << std::endl;  // 50
    changeLength(&r1, 20);
    std::cout << area(r1) << std::endl;  // 100

    // class
    RectangleB r2(10, 5);
    std::cout << r2.area() << std::endl;  // 50
    r2.changeLength(20);
    std::cout << r2.area() << std::endl;  // 100
    
    return 0;
}