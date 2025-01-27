#include <iostream>
#include <vector>

void printVectorInt(std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// void sortVectorInt(std::vector<int>& vec) {
//     for (int i = 0; i < vec.size(); ++i) {
//         int lowestNum = vec[i];
//         int lowestIndex = i;

//         // find next lowest number + its index
//         for (int j = i + 1; j < vec.size(); ++j) {
//             if (vec[j] < lowestNum) {
//                 lowestNum = vec[j];
//                 lowestIndex = j;
//             }
//         }

//         // move it to the ith position of the array
//         if (i != lowestIndex) {  // save memory?
//             vec.erase(vec.begin() + lowestIndex);
//             vec.insert(vec.begin() + i, lowestNum);
//         }
//     }
// }

void betterInsertionSort(std::vector<int>& v) {
    for (int i = 1; i < v.size(); ++i) {
        int key = v[i];
        int j = i - 1;
        while (j > -1 && v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}

int main() {
    std::vector<int> numbers = {1, 5, 12, 64, 82, 19, 20, 51, 18, 3, 92, 7, 8};
    std::cout << "numbers (before): " << std::endl;
    printVectorInt(numbers);

    // sortVectorInt(numbers);
    betterInsertionSort(numbers);
    std::cout << "numbers (after): " << std::endl;
    printVectorInt(numbers);
    return 0;
}