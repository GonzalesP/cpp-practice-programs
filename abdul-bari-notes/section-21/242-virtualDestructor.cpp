#include <iostream>

// an inherited class calls the Base() constructor first, and then
// it calls the Derived() constructor second.
// however, when a Derived object is destroyed, the ~Derived() destructor
// will be called first! the ~Base() destructor is called last.

class Base1 {
public:
    Base1() {
        std::cout << "Constructor of Base1" << std::endl;
    }
    ~Base1() {
        std::cout << "Destructor of Base1" << std::endl;
    }
};
class Derived1 : public Base1 {
public:
    Derived1() {
        std::cout << "Constructor of Derived1" << std::endl;
    }
    ~Derived1() {
        std::cout << "Destructor of Derived1" << std::endl;
    }
};


// during construction, base is called before derived
// during destruction, derived is called before base
void fun1() {
    Derived1 d1;  // "Const of B1" "Const of D1"
}
// "Dest of D1" "Dest of B1"



// however, when using a BASE pointer to a DERIVED object, the pointer
// will treat the object like a Base object. so, the ~Derived() destructor
// will not be called normally.
// the solution to calling the Derived() destructor is making
// the ~Base() destructor VIRTUAL
// doing so will make the pointer call the destructor function of the object
// rather than the pointer class

class Base2 {
public:
    Base2() {
        std::cout << "Constructor of Base2" << std::endl;
    }
    virtual ~Base2() {
        std::cout << "Destructor of Base2" << std::endl;
    }
};
class Derived2 : public Base2 {
public:
    Derived2() {
        std::cout << "Constructor of Derived2" << std::endl;
    }
    ~Derived2() {
        std::cout << "Destructor of Derived2" << std::endl;
    }
};


// first, Base2() constructor is called then Derived2() constructor
// last, ~Derived2() destructor is called because Base2's destructor is virtual
// (meaning the object's destructor method is used). Base2's destructor
// is called last.

void fun2() {
    Base2* p = new Derived2();  // "Base2 const" "Derived2 const"
    delete p;  // "Derived2 dest" "Base2 dest"
}



// if you don't make Base's destructor virtual, then base pointer will NOT
// call Derived's destructor (which may lead to memory leaks depending on
// what Derived allocates during runtime)

int main() {
    fun1();
    fun2();

    return 0;
}