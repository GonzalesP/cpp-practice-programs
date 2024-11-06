#include <iostream>
#include <vector>

class Solution {
public:
    int popcount(int num) {
        int count = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                ++count;
            }
            num = num >> 1;
        }
        return count;
    }

    bool canSortArray(std::vector<int>& nums) {
        bool keepSwapping = true;
        while (keepSwapping) {
            bool swappedOnce = false;
            for (int i = 0; i < nums.size() - 1; ++i) {
                // if same num bits and <, swap
                if (popcount(nums.at(i)) == popcount(nums.at(i + 1)) &&
                    nums.at(i) > nums.at(i + 1)) {
                    
                    int temp = nums.at(i);
                    nums.at(i) = nums.at(i + 1);
                    nums.at(i + 1) = temp;
                    swappedOnce = true;
                }
            }

            if (swappedOnce == false) {
                keepSwapping = false;
            }
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums.at(i) > nums.at(i + 1)) {
                return false;
            }
        }
        return true;
    }
};