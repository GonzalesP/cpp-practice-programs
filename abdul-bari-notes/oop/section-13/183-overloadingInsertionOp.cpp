#include <iostream>

class Complex {
private:
    int real;
    int img;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }

    // you could make a function dedicated to printing an object,
    // but overloading the << operator would be more convenient!
    // void display() {
    //     std::cout << real << " + " << img << "i" << std::endl;
    // }


    // overloading the Insertion operator will allow you to print objects
    // using the same syntax as other primitive data types (e.g., cout << x)

    friend std::ostream& operator<<(std::ostream& out, Complex c);
    // friend: two objects of different types are used - need friend function
    // ostream&: want to return the output stream so it can be used again in
    // the same line (e.g. cout << x << y << z -> cout << y << z -> cout << z)
        // otherwise, can't print multiple things using same cout statement!
};

int main() {
    Complex c1(3, 7);
    int x = 10;

    std::cout << "x: " << x << std::endl;  // C++ supports printing ints
    // could use something like c1.display(), but it's less pretty syntax wise

    // in order to use insertion operator (<<) for printing objects,
    // the programmer must define an overloaded function themselves!
    std::cout << "c1: " << c1 << std::endl;
        // equivalent to operator<<(std::cout, c1);

    return 0;
}

std::ostream& operator<<(std::ostream& out, Complex c) {
    out << c.real << " + " << c.img << "i";
    return out;  // don't forget! need to return ostream so that it can continue
    // to be used to print the rest of the line (e.g., other variables/literals)
}

// "you cannot continue an insertion << statement unless the ostream ITSELF & is
// returned to you for reuse." - that's why you cannot use void, need ostream&

// e.g. std::cout << c << endl;  // first is std::cout << c;
// once that statement is complete, you're left with [] << endl;
// in order to print the endl, you want std::cout to be returned to the []
// thus, you need to return cout itself (i.e., an ostream&)