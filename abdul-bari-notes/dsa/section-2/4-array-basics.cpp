#include <iostream>

int main() {
    int A[5];  // declare array of integers, with size 5
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    std::cout << sizeof(A) << std::endl;  // 4 bytes (int) * 5 = 20
    std::cout << A[1] << std::endl;  // 15
    printf("%d\n", A[2]);  // instead of cout, C-lang uses printf() from stdio.h


    int B[] = {2, 4, 6, 8, 10, 12, 14};  // initialize array
        // automatically given size 7 - exact num of elements

    std::cout << sizeof(B) << std::endl;  //28
    std::cout << B[1] << std::endl;  // 4
    printf("%d\n", B[2]);  // 6


    int C[10] = {2, 4, 6, 8, 10, 12, 14};  // the rest of the array is filled with 0's

    std::cout << sizeof(C) << std::endl;  // 40
    std::cout << C[8] << std::endl;  // 0
    printf("%d\n", C[9]);  // 0

    for (int i = 0; i < 10; i++)
        std::cout << C[i] << std::endl;
    
    for (int x : C)
        std::cout << x << std::endl;


    int n;
    std::cout << "Enter Size: ";
    std::cin >> n;
    int D[n];  // okay to declare variable-sized array (garbage values)
    // however, you cannot initialize it
        // int A[n] = {2,4,6,8,10,12};  - error
        // * results may vary across compilers

    std::cout << "Enter values for D" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "D[" << i << "]: ";
        std::cin >> D[i];
    }

    std::cout << "Elements of D:" << std::endl;
    for (int x : D)
        std::cout << x << " ";

        
    return 0;
}