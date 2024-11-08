#include <vector>

class Solution {
public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
        std::vector<int> answer;
        int maxXOR = (int) pow(2, maximumBit) - 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            int nthXOR = nums.at(0);
            for (int j = 1; j < nums.size() - i; ++j) {
                nthXOR = nthXOR ^ nums.at(j);
            }
            answer.push_back(nthXOR ^ maxXOR);
        }
        return answer;
    }
};