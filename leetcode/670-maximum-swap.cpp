#include <iostream>
#include <vector>
#include <math.h>

class Solution {
public:
    std::vector<int> listOfDigits(int num) {
        if (num == 0) {
            return std::vector<int> {0};
        }

        std::vector<int> digits;
        while(num > 0) {
            digits.insert(digits.begin(), num % 10);
            num /= 10;
        }

        return digits;
    }
    int vectorToInt(std::vector<int> vec) {
        int sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            sum += (vec.at(i) * pow(10, vec.size() - 1 - i));
        }
        return sum;
    }

    int maximumSwap(int num) {
        std::vector<int> digits = listOfDigits(num);
        bool swapped = false;
        int nthDigit = 0;  // 0 is first digit (leftmost), 1 is second
        int currentBestIndex = nthDigit;

        while(!swapped && nthDigit < digits.size() - 1) {
            for (int i = nthDigit + 1; i < digits.size(); i++) {
                if (nthDigit == currentBestIndex && digits.at(i) > digits.at(currentBestIndex)) {
                    currentBestIndex = i;
                }
                else if (nthDigit != currentBestIndex && digits.at(i) >= digits.at(currentBestIndex)) {
                    currentBestIndex = i;
                }
            }

            // currentBestIndex is not nthDigit -> need to swap
            if (nthDigit != currentBestIndex) {
                swapped = true;
                int temp = digits.at(nthDigit);
                digits.at(nthDigit) = digits.at(currentBestIndex);
                digits.at(currentBestIndex) = temp;
            }
            else {
                ++nthDigit;
                currentBestIndex = nthDigit;
            }
        }

        return vectorToInt(digits);
    }
};

int main() {
  int num = 0;
  std::cout << "Choose a number from [0, 10^8]" << std::endl;
  std::cin >> num;

  Solution s;
  std::cout << "Maximum Swap: " << s.maximumSwap(num) << std::endl;
  return 0;
}