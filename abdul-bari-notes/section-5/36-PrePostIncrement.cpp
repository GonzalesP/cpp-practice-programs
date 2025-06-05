#include <iostream>

int main()
{
    // PreIncrement example
    int a = 5, b;
    b = ++a;  // a becomes 6, b becomes 6
    std::cout << "a: " << a << ", b: " << b << std::endl;


    // PostIncrement example
    int c = 5, d;
    d = c++;  // d becomes 5, c becomes 6
    std::cout << "c: " << c << ", d: " << d << std::endl;


    // Cursed example - don't use unary op in same line more than once!
    int g = 5, h;
    h = 2 * ++g + 2 * g++;
    std::cout << "g: " << g << ", h: " << h << std::endl;
    // results may vary depending on compiler!!

    return 0;
}