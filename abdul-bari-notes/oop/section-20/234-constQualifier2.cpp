#include <iostream>

// constants can also be used in classes. specifically, if you want a
// member function to access BUT NOT MODIFY data members, you can add const
// to the end of the member function's prototype
class Demo {
public:
    int x = 10;
    int y = 20;
    static int z;

    void Display() const {
        // x++;  - not allowed!
        z++;  // allowed, since z is static
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
    // "cannot assign to non-static data member within const member function"
};
int Demo::z = 30;


// lastly, constants can also be used to make sure a function's
// formal parameters cannot modify its respective actual parameters
// this is useful for call by reference functions (i.e., if you want to make
// a function inline BUT NOT allowed to modify the actual parameters)
void fun(const int &a, int const &b) {
    // a++;  - not allowed! a is an integer constant
    // b++;  - not allowed! b is a constant integer
    std::cout << "fun()" << std::endl;
    std::cout << a << " " << b << std::endl;
}


int main() {
    std::cout << std::endl;

    Demo d;
    d.Display();  // x: 10, y: 20

    int m = 10;
    int n = 20;

    std::cout << std::endl;

    // a becomes an alias for m, b becomes an alias for n
    fun(m, n);  // 10 20
    std::cout << "main()" << std::endl;
    std::cout << m << " " << n << std::endl;  // 10 20

    std::cout << std::endl;

    return 0;
}