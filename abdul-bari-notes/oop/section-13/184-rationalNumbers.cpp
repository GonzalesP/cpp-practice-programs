#include <iostream>

class Rational {
    private:
        int numerator;
        int denominator;
    public:
        // Constructor
        Rational(int num, int den);

        // Accessors
        int getNumerator();
        int getDenominator();
        
        // Mutators
        void setNumerator(int num);
        void setDenominator(int den);

        // Facilitators (overloading!)
        friend Rational operator+(Rational r1, Rational r2);
        friend std::ostream& operator<<(std::ostream& out, Rational& r);
};  // don't forget to use reference parameters for insertion overload!!!

// helper function for computing the gcd of two numbers
// (used to reduce Rational numbers - helpful when adding them)
int gcd(int, int);

int main() {
    Rational r1(1,2);  // 1/2
    Rational r2(1,4);  // 1/4
    std::cout << "r1: " << r1 << std::endl;
    std::cout << "r2: " << r2 << std::endl;

    std::cout << "r3 = r1 + r2..." << std::endl;
    Rational r3 = r1 + r2;  // 1/2 + 1/4 = 4/8 + 2/8 = 6/8 = 3/4
    std::cout << "r3: " << r3 << std::endl;  // 3/4

    return 0;
}

// constructors
Rational::Rational(int num = 0, int den = 1) {
    setNumerator(num);
    setDenominator(den);
}

// accessors
int Rational::getNumerator() {
    return numerator;
}
int Rational::getDenominator() {
    return denominator;
}

// mutators
void Rational::setNumerator(int num) {
    numerator = num;
}
void Rational::setDenominator(int den) {
    if (den != 0) {
        denominator = den;
    }
    else {
        denominator = 1;
    }
}

// facilitators

// a/b + c/d = ad/bd + bc/bd = (ad + bc) / bd = P / Q -> reduce to p / q
// by dividing p and q by their gcd
// gcd of two numbers: subtract smaller number from bigger number,
// repeat until both numbers are equal
Rational operator+(Rational r1, Rational r2) {
    Rational temp;

    // first follow the formula for P / Q = (ad + bc) / bd
    temp.numerator = (r1.numerator * r2.denominator) + (r1.denominator * r2.numerator);
    temp.denominator = r1.denominator * r2.denominator;

    // then simplify the fraction using the gcd
    int factor = gcd(temp.numerator, temp.denominator);
    temp.numerator /= factor;
    temp.denominator /= factor;

    return temp;
}
std::ostream& operator<<(std::ostream& out, Rational& r) {
    out << r.numerator << "/" << r.denominator;
    return out;
}

// gcd of two numbers: subtract smaller number from bigger number,
// repeat until both numbers are equal
int gcd(int x, int y) {
    while (x != y) {
        if (x > y) {
            x -= y;
        }
        else {
            y -= x;
        }
    }
    return x;
}