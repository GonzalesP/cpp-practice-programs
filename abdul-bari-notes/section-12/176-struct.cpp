#include <iostream>

// in C, structs can only have data members. no functions can be created
// inside a struct

// Meanwhile in C++, structs can have functions. so, they are mostly the same
// as Classes. HOWEVER, the difference between structs and Classes is that
// everything in a struct is PUBLIC by default. On the other hand,
// everything in a Class is PRIVATE by default

struct Demo1 {
    int x;
    int y;

    void display() {
        std::cout << x << " " << y << std::endl;
    }
};  // everything is public by default

class Demo2 {
    int x;
    int y;

    void display() {
        std::cout << x << " " << y << std::endl;
    }
};  // everything is PRIVATE by default (would need public: to make accessible)


int main() {
    Demo1 d1;  // -struct
    d1.x = 10;
    d1.y = 20;
    d1.display();  // allowed bc struct's members are public

    Demo2 d2;  // -class
    // d2.x = 10;
    // d2.y = 20;
    // d2.display();  // error: can't access bc they were not under public:
    return 0;
}