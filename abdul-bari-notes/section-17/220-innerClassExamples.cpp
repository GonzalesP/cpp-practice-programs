#include <iostream>

// 1) Inner classes cannot access outer class variables unless they are static
// 2) An outer class can access all of the public members of an Inner class
// 3) An outer class can create instances (objects) of an Inner class
// 4) The inner class is local to the scope of the Outer class
    // so, to access/interact with the inner class, you need to use Outer::
class Outer {
public:
    int a = 10;
    static int b;
    void fun() {
        i.show();
        std::cout << i.x << std::endl;
    }
    class Inner {
        public:
        int x = 25;
        void show() {
            std::cout << "x: " << x << ", ";
            // std::cout << "a: " << a << std::endl;
                // a is an outer variable AND it is non-static
            std::cout << "b: " << b << std::endl;
        }
    };
    Inner i;
};
int Outer::b = 20;

int main() {
    std::cout << std::endl;
    std::cout << "Creating Outer o." << std::endl;
    Outer o;
    std::cout << "o.a: " << o.a << std::endl;  // 10
    std::cout << "o.b: " << o.b << std::endl;  // 20
    std::cout << "Outer::b: " << Outer::b << std::endl;  // 20
    std::cout << "Calling o.fun()" << std::endl;
    o.fun();  // i.show() -> x: 25, b: 20 ; i.x -> 25
    std::cout << "Calling o.i.show()" << std::endl;
    o.i.show();  // x: 25, b: 20
    std::cout << "o.i.x: " << o.i.x << std::endl;  // 25

    std::cout << std::endl;
    std::cout << "Creating Outer::Inner oi." << std::endl;
    Outer::Inner oi;
    std::cout << "Calling oi.show()" << std::endl;
    oi.show();  // x: 25, b: 20
    std::cout << "oi.x: " << oi.x << std::endl;  // 25
    
    std::cout << std::endl;
    return 0;
}

class LinkedList {
    class Node {
        int data;
        Node* next;
    };
    Node* Head;
};