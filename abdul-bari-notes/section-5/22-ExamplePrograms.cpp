#include <iostream>
int main()
{
    int a, b, c;
    std::cout << "Please enter two numbers:" << std::endl;
    std::cin >> a >> b;
    c = a + b;
    std::cout << "The sum is: " << c << std::endl;

    std::string name;
    std::cout << "May I know your name?" << std::endl;
    // std::cin >> name;  // only takes first string (e.g. First)
    std::getline(std::cin, name);  // takes entire line (e.g. First Last)
    std::cout << "Welcome, " << name << std::endl;

    return 0;
}