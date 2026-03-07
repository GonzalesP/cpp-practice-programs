#include <iostream>

// lambda experssions can even be sent as a parameter to other funcitons

template <typename T>
void fun(T p) {
    p();  // calls function p
}

int main() {
    int a = 10;
    auto f = [&a](){ std::cout << a++ << std::endl; };

    f();  // prints 10, a becomes 11
    fun(f);  // calls f -> prints 11, a becomes 12
    fun(f);  // prints 12, a becomes 13

    std::cout << "a: " << a << std::endl;  // a: 13

    return 0;
}