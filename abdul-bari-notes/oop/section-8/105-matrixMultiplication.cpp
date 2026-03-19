#include <iostream>

int main() {
    int A[10][10];
    int B[10][10];
    int C[10][10];
    int rowA, colA, rowB, colB, rowC, colC;

    // get the sizes of matrices A and B
    // the length of a ROW in A must match the length of a COLUMN in B
    // i.e., the number of columns in A must match the number of rows in B
    bool invalidInput = true;
    while (invalidInput) {
        std::cout << "Enter the dimensions of matrix A." << std::endl;
        std::cout << "rows (max 10): ";
        std::cin >> rowA;
        std::cout << "cols (max 10): ";
        std::cin >> colA;
        std::cout << std::endl;

        std::cout << "Enter the dimensions of matrix B." << std::endl;
        std::cout << "rows (max 10): ";
        std::cin >> rowB;
        std::cout << "cols (max 10): ";
        std::cin >> colB;
        std::cout << std::endl;

        if (colA != rowB) {
            std::cout << "Invalid input. A cols must == B rows." << std::endl;
            std::cout << std::endl;
        }
        else if (rowA > 10) {
            std::cout << "Invalid input. A has too many rows." << std::endl;
            std::cout << std::endl;
        }
        else if (colA > 10) {
            std::cout << "Invalid input. A has too many cols." << std::endl;
            std::cout << std::endl;
        }
        else if (rowB > 10) {
            std::cout << "Invalid input. B has too many rows." << std::endl;
            std::cout << std::endl;
        }
        else if (colB > 10) {
            std::cout << "Invalid input. B has too many cols." << std::endl;
            std::cout << std::endl;
        }
        else {
            invalidInput = false;
            rowC = rowA;
            colC = colB;
        }
    }

    // get input for matrix A
    std::cout << "Enter the values of matrix A:" << std::endl;
    for (int r = 0; r < rowA; r++) {
        for (int c = 0; c < colA; c++) {
            std::cout << "a" << r << c << ": ";
            std::cin >> A[r][c];
        }
        std::cout << std::endl;
    }

    // print matrix A
    std::cout << "Matrix A: " << std::endl;
    for (int r = 0; r < rowA; r++) {
        for (int c = 0; c < colA; c++) {
            std::cout << A[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // get input for matrix B
    std::cout << "Enter the values of matrix B:" << std::endl;
    for (int r = 0; r < rowB; r++) {
        for (int c = 0; c < colB; c++) {
            std::cout << "b" << r << c << ": ";
            std::cin >> B[r][c];
        }
        std::cout << std::endl;
    }

    // print matrix B
    std::cout << "Matrix B: " << std::endl;
    for (int r = 0; r < rowB; r++) {
        for (int c = 0; c < colB; c++) {
            std::cout << B[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // form matrix C = AB
    for (int r = 0; r < rowC; r++) {
        for (int c = 0; c < colC; c++) {
            // row r of A will multiply into col c of B
            // their dimensions match, so they can use same loop
            int sum = 0;
            for (int i = 0; i < colA; i++)
                sum += A[r][i] * B[i][c];
            C[r][c] = sum;
        }
    }

    // print matrix C
    std::cout << "Matrix C = AB: " << std::endl;
    for (int r = 0; r < rowC; r++) {
        for (int c = 0; c < colC; c++) {
            std::cout << C[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}