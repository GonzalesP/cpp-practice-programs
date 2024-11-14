#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        // bit position, # of candidates
        std::unordered_map<int, int> sharedBits;
        int largest_combo = 0;

        for (int can = 0; can < candidates.size(); ++can) {
            int bit = 1;
            int candidate = candidates.at(can);
            while (candidate > 0) {
                // bit is set to 1, increase count
                if (candidate & 1) {
                    // bit already exists
                    // C++ 20 - if (sharedBits.contains(bits))
                    if (sharedBits.find(bit) != sharedBits.end()) {
                        ++sharedBits[bit];
                    }
                    // bit doesn't exist yet
                    else {
                        sharedBits[bit] = 1;
                    }

                    // check if combo record should be updated
                    if (sharedBits[bit] > largest_combo) {
                        largest_combo = sharedBits[bit];
                    }
                }
                ++bit;
                candidate = candidate >> 1;
            }
        }

        return largest_combo;
    }
};

int main() {
    int candidate;
    std::vector<int> candidates;
    Solution s;

    std::cout << "Enter a list of candidates to find the largest combo with "
              << "bitwise AND > 0: " << std::endl;
    
    while (std::cin >> candidate) {
        candidates.push_back(candidate);
    }

    std::cout << "The largest combo of bitwise AND > 0 consists of THIS many "
              << "candidates:" << std::endl;
    std::cout << s.largestCombination(candidates) << std::endl;

    return 0;
}