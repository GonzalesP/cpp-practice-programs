#include <iostream>

int main() {
    float A[100], sum = 0.0f, average;  // find the average of up to 100 numbers
    int n;  // amount of numbers to average
    std::cout << "How many numbers will you enter (max 100)?" << std::endl;
    std::cin >> n;
    if (n > 100) {
        std::cout << "size is too large. exiting." << std::endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ". Enter number: ";
        std::cin >> A[i];
        sum += A[i];
    }

    average = sum / n;
    std::cout << "Average: " << average << std::endl;

    return 0;
}