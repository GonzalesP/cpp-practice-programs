#include <iostream>

int main() {
    int A[2][3] = {{2,4,6}, {3,5,7}};

    // print everything in A
    std::cout << "Array A: " << std::endl;
    for (int i = 0; i < 2; i++) {  // rows
        for (int j = 0; j < 3; j++) {  // columns
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // print everything using for EACH loops
    std::cout << "Array A (for each loop): " << std::endl;
    for (auto& x : A) {  // rows (1D arrays, 2 total) - MUST USE &
        for (auto& y : x) {  // ints from row x - MUST USE &
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    // & is needed because A[2][3] is just syntax candy for int* !!!
    // also need 'auto' because... it handles the data type better lol;;


    int B[2][3];
    // initialize B with user input
    std::cout << "Enter values for Array B: " << std::endl;
    for (auto& x : B) {
        for (auto& y : x) {
            std::cin >> y;
        }
    }
    // print B
    std::cout << "Array B: " << std::endl;
    for (auto& x : B) {
        for (auto& y : x) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}