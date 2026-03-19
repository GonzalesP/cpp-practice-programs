#include <iostream>

int main() {
    int i = 0;
    while (i < 10) {
        std::cout << "Hi " << i << std::endl;
        ++i;
    }

    int j = 0;
    do {
        std::cout << "Hello " << j << std::endl;
        ++j;
    } while (j < 10);

    for (int m = 0; m < 10; ++m) {
        std::cout << "Sup " << m << std::endl;
    }

    return 0;
}