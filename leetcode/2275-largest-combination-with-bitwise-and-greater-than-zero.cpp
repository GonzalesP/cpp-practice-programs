#include <iostream>
#include <vector>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int largestComboSize = 0;
        for (int i = 1; i < pow(2, candidates.size()); ++i) {
            // select combo of candidates
            int bitwiseMap = i;
            std::vector<int> comboI;
            for (int candidate = 0; candidate < candidates.size(); ++candidate) {
                if (bitwiseMap % 2 == 1) {
                    comboI.push_back(candidates.at(candidate));
                }
                bitwiseMap = bitwiseMap >> 1;
            }

            // calculate bitwise AND of combo I
            int comboAND = comboI.at(0);
            for (int cand = 1; cand < comboI.size(); ++cand) {
                comboAND = comboAND & comboI.at(cand);
            }

            if (comboAND > 0 && comboI.size() > largestComboSize) {
                largestComboSize = comboI.size();
            }
        }

        return largestComboSize;
    }
};