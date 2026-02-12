#include <iostream>

int main() {
    int A1[5];  // empty array size 5, filled with garbage values (usually 0)
    std::cout << "int A1[5];" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << A1[i] << std::endl;

    int A2[5] = {3, 4, 10, 12, 5};
    std::cout << "int A2[5] = {3, 4, 10, 12, 5};" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << A2[i] << std::endl;
    
    int A3[5] = {3, 4};  // A2[2] thru A2[4] filled with zeros
    std::cout << "int A3[5] = {3, 4};" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << A3[i] << std::endl;

    int A4[5] = {0};  // all zeros, not just garbage (bc A4[1] is initialized)
    std::cout << "int A4[5] = {0};" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << A4[i] << std::endl;

    // int A[5] = {2, 4, 6, 8, 10, 12};  // error: 6 elements, not enough space

    int A5[] = {2, 4, 6, 8, 10, 12};  // automatically makes arr size 6
    std::cout << "int A5[] = {2, 4, 6, 8, 10, 12};" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << A5[i] << std::endl;
    
    // C++ 11 introduced for each loops:

    std::cout << "for (int x : A5)" << std::endl;
    for (int x : A5)  // for EACH int x in the int array A5
        std::cout << x << std::endl;  // x is an int element, not an array index
    // for each goes through ALL ELEMENTS in an array (based on size of array)


    float B1[] = {2.5f, 5.6f, 9, 8, 7};
    std::cout << "float B1[] = {2.5f, 5.6f, 9, 8, 7};" << std::endl;

    // note: using int x will convert (truncate) floats into ints
    std::cout << "for (int x : B1)" << std::endl;
    for (int x : B1)
        std::cout << x << std::endl;

    std::cout << "for (float x : B1)" << std::endl;
    for (float x : B1)
        std::cout << x << std::endl;

    
    // the 'auto' keyword lets the compiler worry about using the correct type
    std::cout << "for (auto x : B1)" << std::endl;
    for (auto x : B1)
        std::cout << x << std::endl;

    
    char C[] = {'A', 66, 'C', 68};
    std::cout << "char C[] = {'A', 66, 'C', 68};" << std::endl;

    std::cout << "for (auto x : C)" << std::endl;
    for (auto x : C)  // prints 'A' 'B' 'C' 'D' because C[] is a char[]
        std::cout << x << std::endl;
    
    std::cout << "for (int x : C)" << std::endl;
    for (int x : C)  // prints 65 66 67 68 because x is an int (ASCII codes)
        std::cout << x << std::endl;

    return 0;
}