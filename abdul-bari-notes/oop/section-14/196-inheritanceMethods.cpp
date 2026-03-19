#include <iostream>

class Parent
{
private:  int a;
protected:  int b;
public:  int c;

    void funParent() {  // public
        a = 10;
        b = 5;
        c = 15;
    }
};



// Child1 - PUBLICLY INHERITING PARENT

// Parent's private IS NOT accessible by Child  - "available, not accessible"
// Parent's protected becomes Child's protected  - "accessible to class"
// Parent's public becomes Child's public  - "accessible to class + objects"
class Child1 : public Parent {
public:
    void funChild() {
        // a = 10;  // not allowed! a is private in Parent
        b = 5;
        c = 15;
    }
};

// Parent's private IS NOT accessible by GrandChild
// Parent's protected becomes GrandChild's protected
// Parent's public becomes GrandChild's public

// Child's private (pause) IS NOT accessible by Grandchild
// Child's protected becomes GrandChild's protected
// Child's public becomes GrandChild's public
class GrandChild1 : public Child1 {
public:
    void funGrandChild() {
        // a = 10;  // not allowed
        b = 5;
        c = 15;
    }
};



// Child2 - PROTECTEDLY INHERITING PARENT

// Parent's private still not accessible
// Parent's protected becomes Child's protected  - "accessible to class"
// Parent's public ALSO becomes Child's protected  - "NOT accessible to objects"
class Child2 : protected Parent {
public:
    void funChild() {
        // a = 10;  // still not allowed
        b = 5;
        c = 15;
    }
};

// Parent's private IS NOT accessible by GrandChild
// Parent's protected becomes GrandChild's protected
// Parent's public ALSO becomes GrandChild's protected

// Child's private (pause) IS NOT accessible by Grandchild
// Child's protected becomes GrandChild's protected
// Child's public becomes GrandChild's public, but NOTICE that
// none of Parent's public members are public for GrandChild
    // they became protected because Child inherited protectedly
class GrandChild2 : public Child2 {  // note the public Child2
public:
    void funGrandChild() {
        // a = 10;  // still not allowed
        b = 5;
        c = 15;
    }
};



// Child3 - PRIVATELY INHERITING PARENT

// Parent's private still not accessible
// Parent's protected becomes Child's private
// Parent's public ALSO becomes Child's private
    // So, since all of Parent is private to Child, GrandChild will
    // NOT be able to access Parent's protected nor public members
class Child3 : private Parent {
public:
    void funChild() {
        // a = 10;  // still not allowed
        b = 5;
        c = 15;
    }
};

// Parent's private IS NOT accessible by GrandChild
// Parent's protected IS ALSO NOT accessible by Grandchild
// Parent's public IS ALSO NOT accessible by Grandchild
    // Nothing from Parent is accessible by Grandchild!!!

// Child's private (pause) IS NOT accessible by Grandchild
// Child's protected becomes GrandChild's protected
// Child's public becomes GrandChild's public
    // Nothing from Parent transfers over, not even protectedly
    // so it cannot be accessed, even from INSIDE GrandChild
class GrandChild3 : public Child3 {  // note the public Child2
public:
    void funGrandChild() {
        // a = 10;  // same as usual
        // b = 5;  // NOT ALLOWED ANYMORE! Parent's members are private to Child
        // c = 15;  // which means they are not accessible to GrandChild class!
    }
};



// Main: used to show how objects interact with private/protected/public members
int main() {
    Child1 ch1;
    // ch1.a = 10
        // a is private from PARENT, the derived class/object has no access
    // ch1.b = 5;  // b is protected, object has no access
    ch1.c = 20;  // c is public, object CAN access

    Child2 ch2;
    // ch2.a = 10;  // a was private from parent
    // ch2.b = 5;  // b was protected from parent
    // ch2.c = 20;  // NO LONGER ACCESSIBLE BY OBJECT
        // c was public in parent, BUT it became protected in child!

    return 0;
}