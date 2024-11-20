#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> powerless_indices;
        std::vector<int> powers;

        // record indices that are not consecutive (invalid)
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                powerless_indices[i] = i;
            }
        }

        for (int i = 0; i < nums.size() - k + 1; ++i) {
            bool powerless = false;
            // for each element in subarray (except first), find out if duplicates exist
            // using hash table lookup. if so, the subarray is invalid (powerless)
            for (int j = i + 1; j < i + k; ++j) {
                if (powerless_indices.find(j) != powerless_indices.end()) {
                    powerless = true;
                    break;
                }
            }
            if (powerless) {
                powers.push_back(-1);
            }
            // otherwise, if there are no duplicates, add the power of the subarray
            else {
                powers.push_back(nums[i + k - 1]);
            }
        }

        return powers;
    }
};