#include <iostream>
#include <vector>

void printVectorInt(std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void sortVectorInt(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        int lowestNum = vec[i];
        int lowestIndex = i;

        // find next lowest number + its index
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < lowestNum) {
                lowestNum = vec[j];
                lowestIndex = j;
            }
        }

        // swap elements instead of deleting + inserting
        if (i != lowestIndex) {  // save memory?
            vec[lowestIndex] = vec[i];
            vec[i] = lowestNum;
        }
    }
}

int main() {
    std::vector<int> numbers = {1, 5, 12, 64, 82, 19, 20, 51, 18, 3, 92, 7, 8};
    std::cout << "numbers (before): " << std::endl;
    printVectorInt(numbers);

    sortVectorInt(numbers);
    std::cout << "numbers (after): " << std::endl;
    printVectorInt(numbers);
    return 0;
}