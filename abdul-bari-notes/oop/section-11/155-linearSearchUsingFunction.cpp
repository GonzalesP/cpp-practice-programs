#include <iostream>

// size: how many elements are in A
// key: the element to search for in A
// return the index where key is found in A, otherwise return -1 if not found
int linearSearch(int A[], int size, int key) {
    // search through all elements to find key
    for (int i = 0; i < size; i++) {
        if (A[i] == key)  // key found at index i
            return i;
    }

    // if not found in A, return -1
    return -1;
}

int main() {
    int test1[5] = {10, 20, 30, 40, 50};

    std::cout << "test1 index of 10: "
              << linearSearch(test1, 5, 10) << std::endl;
    
    std::cout << "test1 index of 40: "
              << linearSearch(test1, 5, 40) << std::endl;

    std::cout << "test1 index of 25: "
              << linearSearch(test1, 5, 25) << std::endl;

    return 0;
}