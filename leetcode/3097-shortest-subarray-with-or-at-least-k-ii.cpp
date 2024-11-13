#include <bitset>
#include <vector>

class Solution {
public:
    void updateBitFrequency(std::vector<int>& frequencies, std::bitset<CHAR_BIT * sizeof(int)> numBits, bool increase) {
        for (int i = 0; i < frequencies.size(); ++i) {
            if (numBits[i] == 1) {
                if (increase) {
                    ++frequencies[i];
                }
                else {
                    --frequencies[i];
                }
            }
        }
    }

    int cumulativeOR(std::vector<int> frequencies) {
        int cOR = 0;
        for (int i = 0; i < frequencies.size(); ++i) {
            if (frequencies.at(i) > 0) {
                cOR += (1 << i);
            }
        }
        return cOR;
    }

    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        int length = -1;
        int start = 0;  // 1st pointer
        int end = 0;  // 2nd pointer
        std::vector<int> bitCount(CHAR_BIT * sizeof(int), 0);

        while (end < nums.size()) {
            std::bitset<CHAR_BIT * sizeof(int)> endBits(nums[end]);
            updateBitFrequency(bitCount, endBits, true);

            int cOR = cumulativeOR(bitCount);
            if (cOR >= k) {  // special array found
                if (length == -1 || (end - start + 1) < length) {
                    length = end - start + 1;
                }

                // now try sliding window to find smaller subarray
                while (start < end) {
                    std::bitset<CHAR_BIT * sizeof(int)> startBits(nums[start]);
                    updateBitFrequency(bitCount, startBits, false);
                    cOR = cumulativeOR(bitCount);
                    ++start;

                    if (cOR >= k) {
                        if (end - start  + 1 < length) {
                            length = end - start + 1;
                        }
                    }
                    else {
                        break;
                    }
                }
            }

            ++end;
        }

        return length;
    }
};