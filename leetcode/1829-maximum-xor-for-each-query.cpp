#include <vector>

class Solution {
public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
        std::vector<int> answer;
        int maxXOR = (int) pow(2, maximumBit) - 1;

        int nthXOR = nums.at(0);
        answer.insert(answer.begin(), nthXOR ^ maxXOR);

        for (int i = 1; i < nums.size(); ++i) {
            nthXOR = nthXOR ^ nums.at(i);
            answer.insert(answer.begin(), nthXOR ^ maxXOR);
        }
        return answer;
    }
};