#include <iostream>
#include <cmath>

int main() {
    // Area of a Triangle
    float base, height, area;
    std::cout << "AREA OF A TRIANGLE" << std::endl;
    std::cout << "Enter the base and height:" << std::endl;
    std::cin >> base >> height;
    
    area = (base * height) / 2;
    std::cout << "The area is " << area << std::endl << std::endl;



    // Sum of first n numbers
    int n, sum;
    std::cout << "SUM OF FIRST N NUMBERS" << std::endl;
    std::cout << "Enter n:" << std::endl;
    std::cin >> n;

    sum = n * (n + 1) / 2;
    std::cout << "The sum is " << sum << std::endl << std::endl;



    // Roots of a Quadratic Equation
    float a, b, c, root1, root2;
    std::cout << "ROOTS OF A QUADRATIC EQUATION" << std::endl;
    std::cout << "ax^2 + bx + c = 0" << std::endl;
    std::cout << "Enter a, b, c:" << std::endl;
    std::cin >> a >> b >> c;

    root1 = (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a);
    root2 = (-b - std::sqrt(b * b - 4 * a * c)) / (2 * a);
    std::cout << "The roots are " << root1 << " and " << root2 << std::endl
              << std::endl;
    
    
    
    // Area of a Circle
    float r, circleArea;
    std::cout << "AREA OF A CIRCLE" << std::endl;
    std::cout << "Enter the radius:" << std::endl;
    std::cin >> r;

    circleArea = 3.141593f * r * r;
    std::cout << "The area is " << circleArea << std::endl << std::endl;



    // Speed
    int u, v, acc;  // initial velocity, final velocity, acceleration
    float speed;
    std::cout << "SPEED" << std::endl;
    std::cout << "Enter u, v, a:" << std::endl;
    std::cin >> u >> v >> acc;

    speed = (float) (v * v - u * u) / (2 * acc);
    std::cout << "Speed is " << speed << std::endl << std::endl;

    // Simple Interest
    // SI = Principle Amount * Time * Rate of Interest / 100.0

    // Volume of a Cylinder
    // volume = 3.14 * radius * radius * height;

    // Euclidean Distance between two points
    // dist = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));

    return 0;
}