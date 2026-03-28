#include <iostream>

struct Rectangle {
    int length;
    int breadth;
};

// pass by value
int area(struct Rectangle r1) {
    return r1.length * r1.breadth;
}

// pass by reference
void changeLength(struct Rectangle& r1, int l) {
    r1.length = l;
}

// pass by address
void changeBreadth(struct Rectangle* r1, int b) {
    r1->breadth = b;
}


struct Test {
    int A[5];
    int n;
};

// although you cannot pass an array by value,
// a struct that HAS an array CAN be passed by value (the array will be copied)
void fun(struct Test t1) {
    std::cout << "fun()" << std::endl;
    t1.A[0] = 10;  // this will not change the actual parameter's array
    t1.A[1] = 9;
    t1.A[2] = 8;
    t1.A[3] = 7;
    t1.A[4] = 6;

    for (int x : t1.A)
        std::cout << x << " ";
    std::cout << std::endl;
}

void fun2(struct Test& t1) {
    std::cout << "fun2()" << std::endl;
    
    for (int i = 0; i < t1.n; i++)
        t1.A[i] = i + 1;  // 1 2 3 4 5 ...
}

void fun3(struct Test* t1) {
    std::cout << "fun3()" << std::endl;

    for (int i = 0; i < t1->n; i++)
        t1->A[i] = 0 - i - 1;
}

int main() {
    struct Rectangle r = {10, 5};
    std::cout << "area(r): " << area(r) << std::endl;

    changeLength(r, 8);
    changeBreadth(&r, 8);

    std::cout << "area(r) after update: " << area(r) << std::endl;


    struct Test t = {{2, 4, 6, 8, 10}, 5};
    fun(t);

    std::cout << "main t:" << std::endl;
    for (int x : t.A)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}