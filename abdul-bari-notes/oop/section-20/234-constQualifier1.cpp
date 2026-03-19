#include <iostream>

// the const qualifer is used to treat data/identifiers as constants
// this means that such constants CAN be accessed, but CANNOT be modified

int main() {
    // x and y are integer constants (cannot be modified after initialization)
    const int x = 10;  // note: constants MUST be initialized during declaration
    int const y = 10;
    // x++;  - error: x cannot be modified!
    // y = 30;  - error: y cannot be modified!
    std::cout << std::endl;
    std::cout << "const int x: " << x << std::endl;  // read allowed! -10
    std::cout << "int const y: " << y << std::endl;  // 10

    // identifiers should be read from right to left
        // int const x - "x is an identifier of type constant integer"
        // const int x - "x is an identifier of type integer constant"



    // you can also make pointers to identifiers of constant types
    // i.e., the pointer can access the identifier, but it CANNOT modify it
    // (because the pointer is treating the data as a constant)
    int a = 10;
    int b = 20;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "a: " << a << std::endl;  // 10
    std::cout << "b: " << b << std::endl;  // 20

    std::cout << "int const *ptrA = &a" << std::endl;
    int const *ptrA = &a;  // ptrA is a pointer of a constant integer
        // note: 'a' itself is not a constant int, BUT it is treated like one
        // because a const int IS-A int
    
    std::cout << "const int *ptrB = &b" << std::endl;
    const int *ptrB = &b;
    
    std::cout << "ptrA: " << ptrA << std::endl;  // read of ptr okay - &a
    std::cout << "*ptrA: " << *ptrA << std::endl;  // read of ptr's data okay-10
    std::cout << "ptrB: " << ptrB << std::endl;  // &b
    std::cout << "*ptrB: " << *ptrB << std::endl;  // 20
    // (*ptrA)++;  - error: ptrA1 points to a constant - it cannot change it!
    
    // ptrA itself CAN be modified (the pointer itself is not constant here,
    // only the integer that it points to)
    std::cout << std::endl;
    std::cout << "ptrA = &b;" << std::endl;
    std::cout << "ptrB = &a;" << std::endl;
    ptrA = &b;  // modifying ptrA1 okay
    ptrB = &a;  // modifying ptrA1 okay
    std::cout << "ptrA: " << ptrA << std::endl;  // &b
    std::cout << "*ptrA: " << *ptrA << std::endl;  // 20
    std::cout << "ptrB: " << ptrB << std::endl;  // &a
    std::cout << "*ptrB: " << *ptrB << std::endl;  // 10



    // you can also make pointers themselves constant. i.e., "once this pointer
    // points to an identifier, it CANNOT point to a different one"
    int c = 30;
    int d = 40;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "c: " << c << std::endl;  // 30
    std::cout << "d: " << d << std::endl;  // 40

    std::cout << "int * const ptrC = &c" << std::endl;
    int * const ptrC = &c;  // ptrC is a CONSTANT that is a pointer to an int
    // int * ptrD const = &d;  - not allowed: const cannot be last!

    std::cout << "ptrC: " << ptrC << std::endl;  // &c
    std::cout << "*ptrC: " << *ptrC << std::endl;  // 30
    // ptrC = &d;  - error: ptrC is a CONSTANT POINTER, so it cannot change
        // what identifier (int) it is pointing to
    
    std::cout << std::endl;
    std::cout << "(*ptrC)++" << std::endl;
    (*ptrC)++;  // allowed to modify the data that ptrC points to,
        // but not ptrC itself
    std::cout << "*ptrC: " << *ptrC << std::endl;  // 31



    // you can also make a CONSTANT POINTER for a CONSTANT IDENTIFIER
    // i.e., both the pointer itself and the data it points to are access only
    int g = 50;
    int h = 60;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "g: " << g << std::endl;
    std::cout << "h: " << h << std::endl;

    std::cout << "const int * const ptrG = &g" << std::endl;
    const int * const ptrG = &g;
    // ptrG is a CONSTANT that is a pointer to an integer constant

    std::cout << "int const * const ptrH = &h" << std::endl;
    int const * const ptrH = &h;
    // ptrH is a CONSTANT that is a pointer to a constant integer

    // 1) int const == const int ; either of them can be used before *
    // 2) if you want to make a ptr identifier constant, const MUST be
    //    between * and identifier

    std::cout << "ptrG: " << ptrG << std::endl;  // &g
    std::cout << "*ptrG: " << *ptrG << std::endl;  // 50
    std::cout << "ptrH: " << ptrH << std::endl;  // &h
    std::cout << "*ptrH: " << *ptrH << std::endl;  // 60

    // ptrG = &h;  - not allowed, ptrG is a constant pointer (no new address)!

    // (*ptrH)++;  - not allowed, ptrH points to a "CONSTANT integer"
        // (meaning the contents of &h CANNOT be modified)
    
    std::cout << std::endl;

    return 0;
}