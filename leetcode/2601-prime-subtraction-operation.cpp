#include <vector>

class Solution {
public:
    bool isPrime(int n) {
        for (int i = 2; i < n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int getOptimalPrime(int elem, int min) {  // nums[i] vs. nums[i - 1]
        for (int i = elem - 1; i > 1; --i) {
            if (isPrime(i) && elem - i > min) {
                return i;
            }
        }
        return -1;
    }

    bool primeSubOperation(std::vector<int>& nums) {
        int subPrime = getOptimalPrime(nums.at(0), 0);
        if (subPrime != -1) {
            nums.at(0) -= subPrime;
        }

        for (int i = 1; i < nums.size(); ++i) {
            subPrime = getOptimalPrime(nums.at(i), nums.at(i - 1));
            if (subPrime != -1) {
                nums.at(i) -= subPrime;
            }
            else {
                if (nums.at(i) <= nums.at(i - 1)) {
                    return false;
                }
            }
        }

        return true;
    }
};