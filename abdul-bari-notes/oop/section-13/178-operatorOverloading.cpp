#include <iostream>

class Complex {
public:
    int real;
    int img;

    // add two complex numbers' real and imaginary components
    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    // operator overloading: instead of using a function name to perform
    // an operation, why not design a custom operator? i.e., overload an op?
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
};

int main() {
    Complex c1, c2, c3;
    c1.real = 5;  c1.img = 3;  // 5 + 3i
    c2.real = 10;  c2.img = 5;  // 10 + 5i

    c3 = c1.add(c2);  // 15 + 8i - function called by c1, using c2 as parameter
    std::cout << c3.real << " + " << c3.img << "i" << std::endl;

    // by overloading an operator, you can simplify the syntax needed to perform
    // certain operations (e.g., "adding" two objects together)
    Complex c4 = c1 + c2;
        // same as c1.operator+(c2);
    std::cout << c4.real << " + " << c4.img << "i" << std::endl;  // 15 + 8i
    return 0;
}