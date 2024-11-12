#include <bitset>

class Solution {
public:
    long long minEnd(int n, int x) {
        std::bitset<CHAR_BIT * sizeof(long long)> mergedBits(x);
        std::bitset<CHAR_BIT * sizeof(int)> bitsOfN(n - 1);
        // Don't use n! Remember, nums[] should start at x (e.g. n = 3, x = 4: [4, 5, 6])
        // [4, 5, 6] is from 100 -> 101 - > 110. you don't need 111, which is from 3 (0b11)

        int bitN = 0;  // start at rightmost bit of n
        for (int i = 0; i < CHAR_BIT * sizeof(long long); ++i) {
            if (mergedBits[i] == 0) {
                if (bitsOfN[bitN] == 1) {
                    mergedBits.set(i);
                }
                ++bitN;
            }
        }

        return mergedBits.to_ullong();
    }
};

// std::bitset - https://en.cppreference.com/w/cpp/utility/bitset
// sizeof operator (how many bytes in an object?) - https://en.cppreference.com/w/cpp/language/sizeof
// CHAR_BIT (how many bits in a byte?) - https://en.cppreference.com/w/cpp/types/climits

// shoutout to knotri (Max Wood) on leetcode!