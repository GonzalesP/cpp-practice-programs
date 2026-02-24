#include <iostream>

// a and b are inaccessible outside of Test. however, since fun1 is a friend
// function, it can access a and b despite being defined outside of Test
class Test {
    private:    int a;
    protected:  int b;
    public:     int c;
    friend void fun1();
};

class Your;  // C++ is top-down: declaration needed before usage (i.e., in My)
class My {
    private:
        int a = 10;
    friend Your;  // makes Your a friend class of My (allows Your to access a)
};
class Your {
    public:
        My m;  // has-a relationship: cannot access private/protected members
        // unless My declares this class as a friend class
        void fun2() {
            std::cout << "m.a: " << m.a << std::endl;
        }  // since Your is a friend class, it can access m's "a" variable
};

void fun1();  // C++ is top-down: declare before usage in main

int main() {
    fun1();  // Test friend function that instantiates a Test obj, initializes
    // its int members (including private and protected ones), and prints them

    Your y;  // My friend class that HAS A My obj
    y.fun2();  // will print m's "a", which is 10

    return 0;
}

// fun1 is defined outside of Test, but since it is a friend function, it can
// access the private members (int a and int b) of a Test instance
void fun1() {
    Test t;
    t.a = 15;
    t.b = 10;
    t.c = 5;

    std::cout << "t's contents" << std::endl;
    std::cout << "t.a: " << t.a << std::endl;
    std::cout << "t.b: " << t.b << std::endl;
    std::cout << "t.c: " << t.c << std::endl;
}