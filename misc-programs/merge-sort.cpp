#include <iostream>
#include <vector>

void printVectorInt(std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

std::vector<int> sortVectorInt(std::vector<int> vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    // split vector
    std::vector<int>::iterator middle = vec.begin() + vec.size() / 2;
    std::vector<int> leftSet(vec.begin(), middle);
    std::vector<int> rightSet(middle, vec.end());

    // recursively continue splitting
    leftSet = sortVectorInt(leftSet);
    rightSet = sortVectorInt(rightSet);

    // merge left and right sets
    std::vector<int> sortedVec;
    int i = 0, j = 0;  // left, right

    while (i < leftSet.size() && j < rightSet.size()) {
        if (leftSet[i] < rightSet[j]) {
            sortedVec.push_back(vec[i]);
            ++i;
        }
        else {
            sortedVec.push_back(vec[j]);
            ++j;
        }
    }

    if (i < leftSet.size()) {
        for (int n = i; n < leftSet.size(); ++n) {
            sortedVec.push_back(leftSet[n]);
        }
    }
    if (j < rightSet.size()) {
        for (int n = j; n < rightSet.size(); ++n) {
            sortedVec.push_back(rightSet[n]);
        }
    }

    return sortedVec;
}

int main() {
    std::vector<int> numbers = {1, 5, 12, 64, 82, 19, 20, 51, 18, 3, 92, 7, 8};
    std::cout << "numbers (before): " << std::endl;
    printVectorInt(numbers);

    numbers = sortVectorInt(numbers);

    std::cout << "numbers (after): " << std::endl;
    printVectorInt(numbers);
    return 0;
}