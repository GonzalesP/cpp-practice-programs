#include <iostream>

// Inner classes (aka nested classes) are a way to "hide/organize" classes
// that may not be as useful/applicable to other classes. They are not
// available outside of the scope of the Outer class.
class Outer {
public:
    // Inner i;  - error: variable created before Inner declared/defined
    
    void fun() {  // allowed to use i since it is declared outside
        i.display();  // of the function (and fun() isn't used right away)
    }

    class Inner {
    public:
        void display() {
            std::cout << "Display of Inner" << std::endl;
        }
    };
    Inner i;  // create i after Inner's definition
    // "all Outer objects will have an Inner object named i"
};

int main() {
    Outer o;
    o.fun();  // calls i.display();  -> "Display of Inner" ; i belongs to o

    // Inner i;  // not allowed bc Inner is not visible outside of Outer (local)
        // since Inner is local to Outer, you need the Outer:: scope

    Outer::Inner i;  // create an Inner object without creating an Outer object
    i.display();  // "Display of Inner"

    return 0;
}