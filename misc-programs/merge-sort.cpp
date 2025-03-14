#include <iostream>
#include <vector>

void printVectorInt(std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printVectorAny(std::vector<T>& vec) {
    for (T item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> sortVector(std::vector<T> vec) {
    printVectorAny(vec);  // lol
    return vec;
}

std::vector<int> sortVectorInt(std::vector<int> vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    // split vector
    std::vector<int>::iterator middle = vec.begin() + vec.size() / 2;
    std::vector<int> leftSet(vec.begin(), middle);
    std::vector<int> rightSet(middle, vec.end());

    // print sets (debug)
    printVectorInt(leftSet);
    printVectorInt(rightSet);

    // recursively continue splitting
    leftSet = sortVectorInt(leftSet);
    rightSet = sortVectorInt(rightSet);

    // merge left and right sets
    std::vector<int> sortedVec;
    int i = 0, j = 0;  // left, right

    while (i < leftSet.size() && j < rightSet.size()) {
        if (leftSet[i] <= rightSet[j]) {
            sortedVec.push_back(leftSet[i]);  // don't use vec[], it's not sorted lol!
            ++i;
        }
        else {
            sortedVec.push_back(rightSet[j]);  // leftSet and rightSet are already sorted!!
            ++j;
        }
    }

    // if (i < leftSet.size()) {  // don't need - for loop will terminate anyways if false
    for (int n = i; n < leftSet.size(); ++n) {
        sortedVec.push_back(leftSet[n]);
    }

    for (int n = j; n < rightSet.size(); ++n) {
        sortedVec.push_back(rightSet[n]);
    }

    return sortedVec;
}

int main() {
    std::vector<int> numbers = {1, 5, 12, 64, 82, 19, 20, 51, 18, 3, 92, 7, 8};
    std::cout << "numbers (before): " << std::endl;
    // printVectorInt(numbers);
    printVectorAny(numbers);

    std::cout << "letters (before): " << std::endl;
    std::vector<char> letters = {'j', 'f', 'b', 'h', 'o', 'a', 'e', 'i', 'c', 'p', 'g', 'l', 'm', 'd', 'k', 'n'};
    printVectorAny(letters);

    numbers = sortVectorInt(numbers);

    std::cout << "numbers (after): " << std::endl;
    printVectorInt(numbers);
    printVectorAny(numbers);
    std::cout << "letters (after): " << std::endl;
    printVectorAny(letters);

    return 0;
}

// happy PI day