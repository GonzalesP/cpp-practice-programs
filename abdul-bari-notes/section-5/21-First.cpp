#include <iostream>
#include <string>

// based on lessons 21-23
int main()
{
    std::cout << "Hello, world!" << std::endl;

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

// can also add 'using namespace std;' before main to avoid using std::
// but less efficient bc you're not using everything from std

// to compile, navigate to directory and use g++ First.cpp
// to run, use ./a