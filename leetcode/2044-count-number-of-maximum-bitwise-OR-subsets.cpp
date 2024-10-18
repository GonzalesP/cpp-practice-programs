#include <vector>
#include <iostream>
#include <math.h>  // pow

class Solution {
public:
    // create subset of nums using bits of int nthSubset (e.g. 11001)
    std::vector<int> createSubset(std::vector<int>& set, int nthSubset) {
        std::vector<int> subset;
        for (int i = 0; i < set.size(); i++) {
            if (nthSubset % 2 == 1) {
                subset.push_back(set.at(i));
            }
            nthSubset = nthSubset >> 1;
        }

        return subset;
    }

    // calculate the bitwise OR of a subset (array)
    int subsetBitwiseOR(std::vector<int>& subset) {
        int bitwiseOR = 0;
        for (int i = 0; i < subset.size(); i++) {
            bitwiseOR = bitwiseOR | subset.at(i);
        }

        return bitwiseOR;
    }

    int countMaxOrSubsets(std::vector<int>& nums) {
        int maxBOR = 0;  // current best for max possible bit OR
        int totalMaxSubsets = 0;  // number of subsets with maxBOR

        for (int nthSubset = 1; nthSubset <= pow(2, nums.size()) - 1; nthSubset++) {
            std::vector<int> subset = createSubset(nums, nthSubset);
            int subsetBOR = subsetBitwiseOR(subset);
            if (subsetBOR > maxBOR) {
                maxBOR = subsetBOR;
                totalMaxSubsets = 1;
            }
            else if (subsetBOR == maxBOR) {
                ++totalMaxSubsets;
            }
        }

        return totalMaxSubsets;
    }
};

int main() {
    std::vector<int> nums;
    int numInput = 0;

    std::cout << "Enter some integers for a vector<int>: " << std::endl;
    while(std::cin >> numInput) {
        nums.push_back(numInput);
    }

    Solution s;
    std::cout << "Total # of subsets that have the Max Bitwise OR: ";
    std::cout << s.countMaxOrSubsets(nums) << std::endl;

  return 0;
}