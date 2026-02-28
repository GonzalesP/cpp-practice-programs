#include <iostream>

// Destructors are used to deallocate resources. They are called when
// an object is deleted via 'delete obj'. They are also called automatically
// when the function using it ends. (e.g., if an object was created in main(),
// its destructor will be called once main() ends, or when the program stops)

// Similar to Constructors, Destructors do not have a return type
// (i.e., they cannot return anything). However, one difference is that
// every class can only have ONE destructor (i.e., a destructor cannot
// be overloaded, unlike how a class can use multiple constructors)

class Demo {
public:
    Demo() {
        std::cout << "Constructor of Demo" << std::endl;
    }
    ~Demo() {
        std::cout << "Destructor of Demo" << std::endl;
    }
};

// when fun1() is called, the constructor Demo() will be called
// when fun1() ends, the destructor ~Demo() will be called AUTOMATICALLY
void fun1() {
    Demo d;  // "Constructor of Demo"
}
// fun1() ends - "Destructor of Demo"


// when fun2() is called, the constructor will be called and memory will be
// dynamically allocated from the heap (via the 'new' statement)
// HOWEVER, when fun2() ends, the destructor WILL NOT be called automatically
// so, in order to deallocate the object (i.e., call the destructor), you MUST
// use the 'delete' operator!
void fun2() {
    // dynamically allocate memory for a Demo object
    Demo *p = new Demo();  // "Constructor of Demo"

    // to call the object's destructor, you must use delete
    // since the object was allocated dynamically (via 'new')
    delete p;  //  "Destructor of Demo"
}

// TL;DR if you create an object inside the stack (without new), it will be
// deleted automatically. otherwise, if it's created in the heap, you MUST
// delete it manually.



// lastly, if a class uses external resources (e.g., heap memory,
// network connections, file input streams), it MUST deallocate those resources!
// remember that dynamic memory (heap memory) will NOT free itself, so you must
// free the resources in the destructor!
class Demo2 {
private:
    int *p;  // dynamic array pointer
public:
    Demo2() {
        p = new int[10];  // heap memory - will not automatically delete!
        std::cout << "Constructor of Demo2" << std::endl;
    }
    ~Demo2() {
        delete[] p;  // when Demo2's destructor is called, p will be freed
        std::cout << "Destructor of Demo2" << std::endl;
    }
    // destructor is called when delete is used (heap) or function ends (stack)
};

void fun3() {
    Demo2 d2;  // Constructor of Demo2 (stack + int array in heap)
}
// Destructor of Demo2 (removed from stack, int array removed from heap)

int main() {
    fun1();
    fun2();
    fun3();

    return 0;
}