#include <iostream>

int main() {
    int A[10] = {6, 8, 13, 17, 20, 22, 25, 28, 30, 35};
    int l = 0, h = 9, mid, key;
    std::cout << "Enter key to search for in A: ";
    std::cin >> key;

    while (l <= h) {
        mid = (l + h) / 2;  // int division: removes decimals
        if (A[mid] == key) {
            std::cout << "Found " << key << " at index " << mid << std::endl;
            return 0;
        }
        else if (A[mid] > key)  // too large, check smaller side (left)
            h = mid - 1;
        else  // A[mid] < key, too small, check larger side (right)
            l = mid + 1;
    }
    std::cout << "Key " << key << " not found in A." << std::endl;

    return 0;
}