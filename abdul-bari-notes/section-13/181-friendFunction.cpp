#include <iostream>

class Complex {
private:
    int real;
    int img;
public:
    Complex (int r = 0, int i = 0) {
        real = r;
        img = i;
    }
    void display() {
        std::cout << real << " + " << img << "i";
    }

    // friend function operator overloaders take both objects as parameters
    // they are defined outside of the class and don't need scope resolution
    friend Complex operator+(Complex c1, Complex c2);
};

int main() {
    Complex c1(5, 3), c2(10, 5), c3;
    c3 = c1 + c2;  // 5+3i + 10+5i = 15+8i
        // same as c3 = operator+(c1, c2);
    c3.display();  // 15+8i

    return 0;
}

// hand both objects to this "third party", and it will handle all calculations
// note: no need for scope resolution because this is a friend function
Complex operator+(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real + c2.real;  // also allowed to access private members,
    temp.img = c1.img + c2.img;  // even though this is an outside function!
    return temp;
}