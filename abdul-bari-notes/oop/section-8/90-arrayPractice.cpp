#include <iostream>

int main() {
    // 90 - adding all elements in an array
    std::cout << "int A1[7] = {4, 8, 6, 9, 5, 2, 7};" << std::endl;
    int A1[7] = {4, 8, 6, 9, 5, 2, 7};
    int sum = 0;

    for (int i = 0; i < 7; i++)
        sum += A1[i];
    std::cout << "sum is " << sum << std::endl;

    // 91 - max element of an array
    std::cout << "int A2[7] = {4, 8, 6, 9, 5, 2, 7};" << std::endl;
    int A2[7] = {4, 8, 6, 9, 5, 2, 7};
    int max = A2[0];

    for (int i = 1; i < 7; i++) {
        if (A2[i] > max)
            max = A2[i];
    }
    std::cout << "max is " << max << std::endl;

    // 92 - linear search
    std::cout << "linear search - enter 10 numbers:" << std::endl;
    int A3[10], n = 10, key, index = -1;
    for (int i = 0; i < n; i++)
        std::cin >> A3[i];
    std::cout << "Enter a key to search for: ";
    std::cin >> key;
    for (int i = 0; i < n; i++) {
        if (key == A3[i]) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        std::cout << "key " << key << " found at index " << index << std::endl;
    }
    else {
        std::cout << "key " << key << " not found in array." << std::endl;
    }

    return 0;
}