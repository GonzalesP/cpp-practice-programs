#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    struct Rectangle r = {10, 5};
    std::cout << r.length << std::endl;
    std::cout << r.breadth << std::endl;

    // to access members of an object from a pointer, use -> instead of .
    struct Rectangle* p = &r;
    std::cout << p->length << std::endl;
    std::cout << p->breadth << std::endl;


    struct Rectangle* ptr;
    ptr = (struct Rectangle*) malloc(sizeof(struct Rectangle));
        // new Rectangle;

    ptr->length = 15;
    ptr->breadth = 7;

    std::cout << ptr->length << std::endl;
    std::cout << ptr->breadth << std::endl;

    delete ptr;

    return 0;
}