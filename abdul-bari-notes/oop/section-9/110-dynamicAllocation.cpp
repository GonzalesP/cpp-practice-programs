#include <iostream>

int main () {
    int A[5] = {1,2,3,4,5};  // created in stack
    int *p;  // stack
    p = new int[5];  // points to memory allocated in heap

    p[0] = 1;  // p now acts as a variable name for an int array
    p[1] = 2;  // (the int array exists in the heap)
    std::cout << "p[0]: " << p[0] << ", p[1]: " << p[1] << std::endl;

    delete []p;  // deallocate memory borrowed from heap
    p = nullptr;


    // note: one benefit of dynamically allocating an array is that you
    // can update its size during the duration of a program

    // int A[5] will always be stuck with a size of 5

    // you can initialize an array's size with user input,
    // but it will no longer be changeable while the program continues:
    int sizeB;
    std::cout << "Enter a size for int B[]: ";
    std::cin >> sizeB;
    int B[sizeB];  // B's size cannot be changed after user input!

    std::cout << "sizeof B: " << sizeof B << std::endl;  // sizeB * sizeof int


    // here is an example of an array changing size while the program runs
    int *p2 = new int[20];  // new array with 20 ints
    delete []p2;  // deallocate memory before using a new batch (stop leaks!)

    p2 = new int[40];  // now p2 points to an array of 40 ints!
    delete []p2;

    return 0;
}