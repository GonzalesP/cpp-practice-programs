#include <iostream>

// the final keyword is used when you want to RESTRICT INHERITANCE
// and/or RESTRICT the OVERRIDING of functions

// normally, a class can become a parent class if another inherits it
class Parent {};
class Child : Parent {};  // "Child inherits Parent privately"

// however, if you make a class final, it CANNOT be inherited
class FinalParent final {};
// class FinalChild : FinalParent {};  - error: FinalParent cannot be base class


// lastly, final can also be applied to virtual functions to restrict overriding

// in this example, show() can be overriden
class Parent2 {
public:
    void show() {}
};
class Child2 : public Parent2 {
public:
    void show() {}  // overrides Parent2's show() function
};

// however, in this example, show() is a final function, so it cannot be changed
class Parent3 {
public:
    virtual void show() final {}
        // note: final can only be applied to virtual functions
};
class Child3 : public Parent3 {
public:
    // void show();  - error: you cannot override a final function!
};