#include <iostream>
#include <stdio.h>  // C library for input/output
#include <stdlib.h>  // malloc()

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    // pointers save the addresses of variables
    // for example, an int pointer saves the address of an int variable
    int a = 10;
    int *p;
    p = &a;

    std::cout << a << std::endl;  // 10

    printf("using pointer %d", *p);  // 10
    printf("p's value %d", p);  // address of a
    printf("&a: %d", &a);  // same as p


    // pointers can also point to an array
    int A[5] = {2,4,6,8,10};  // created in stack frame of main()
    int *p2;
    p2 = A;  // don't need & when using name of an array
    // because an array's name already points to its beginning element

    int *p3 = &A[0];  // same as p2 = A;  - do NOT use &A
    for (int i = 0; i < 5; i++) {
        std::cout << A[i] << std::endl;
    }

    // you can also use pointer instead of array name
    for (int i = 0; i < 5; i++) {
        std::cout << p3[i] << std::endl;
    }


    // pointers can also be used to create arrays/objects in the heap
    // C-lang uses the malloc() function, which returns a void * to heap memory
    int *p4;  // p4 is int *, need to type cast void *
    p4 = (int *) malloc(5 * sizeof(int));
        // allocates heap memory for 5 integers
        // p4 itself is in the stack, but the 5 integers are in the heap
    
    p4[0] = 10;  p4[1] = 15;  p4[2] = 14;  p4[3] = 21;  p4[4] = 31;

    for (int i = 0; i < 5; i++) {
        std::cout << p4[i] << std::endl;
    }

    // when you're finished using memory, you need to free it
    free(p4);  // C-lang uses the free();  function


    // C++ uses the new keyword to allocate heap memory
    int *p5;
    p5 = new int[5];

    // to free memory in C++, you can use the delete operator
    delete [] p5;  // when deleting an array, you need []
    // for singular objects, just use delete varName;

    // technically, heap memory is freed when the program ends, but it is a
    // good practice to deallocate the memory anyways for raw pointers


    // all pointers have the same size, even if data types are different
    int *ptr1;
    char *ptr2;
    float *ptr3;
    double *ptr4;
    struct Rectangle *ptr5;

    std::cout << sizeof(ptr1) << std::endl;
    std::cout << sizeof(ptr2) << std::endl;
    std::cout << sizeof(ptr3) << std::endl;
    std::cout << sizeof(ptr4) << std::endl;
    std::cout << sizeof(ptr5) << std::endl;

    return 0;
}