#include <iostream>

int main() {
    int A[2][3] = {3,3,3,3,3,3};
    int B[2][3] = {1,1,1,1,1,1};
    int C[2][3];
    int D[2][3];

    // C = A + B = {{4,4,4}, {4,4,4}}
    std::cout << "C = A + B" << std::endl;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            C[r][c] = A[r][c] + B[r][c];
        }
    }

    // Print C
    std::cout << "Array C: " << std::endl;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            std::cout << C[r][c] << " ";
        }
        std::cout << std::endl;
    }

    // D = A - B = {{2,2,2}, {2,2,2}}
    std::cout << "D = A - B" << std::endl;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            D[r][c] = A[r][c] - B[r][c];
        }
    }

    // Print D
    std::cout << "Array D: " << std::endl;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            std::cout << D[r][c] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}