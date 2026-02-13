#include <iostream>

int main() {
    // 5 by 5 matrix of coordinates
    // (1,1) (1,2) (1,3) (1,4) (1,5)
    // (2,1) (2,2) (2,3) (2,4) (2,5)
    // ...
    std::cout << "Coordinate square:" << std::endl;
    for (int i = 1; i <= 5; i++) {  // "5 rows"
        for (int j = 1; j <= 5; j++)  // "5 columns"
            std::cout << "(" << i << "," << j << ") ";
        std::cout << std::endl;
    }
    std::cout << std::endl;


    // 5 by 5 triangle patterns

    // upper left triangle:  (j < size - i)
    // * * * 
    // * * 
    // * 
    std::cout << "upper left triangle:" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++)
            std::cout << "* ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // lower left triangle:  (j <= i)
    // * 
    // * * 
    // * * * 
    std::cout << "lower left triangle:" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++)
            std::cout << "* ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // upper right triangle:  (j >= i) *, else pad with space
    // * * * 
    //   * * 
    //     * 
    std::cout << "upper right triangle:" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= i)
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // lower right triangle:  j + i >= size - 1
    //     * 
    //   * * 
    // * * * 
    std::cout << "lower right triangle:" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j >= 4)  // 5 - 1
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // todo: diamond

    return 0;
}