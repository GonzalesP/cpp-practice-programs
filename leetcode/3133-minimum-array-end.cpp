#include <bitset>
#include <iostream>

class Solution {
public:
    long long minEnd(int n, int x) {
        std::bitset<32> mergedBits(x);   // used to be CHAR_BIT * sizeof(long long) instead of 32
        std::bitset<32> bitsOfN(n - 1);  // but the algo. yields weird results sometimes
        // Don't use n! Remember, nums[] should start at x (e.g. n = 3, x = 4: [4, 5, 6])
        // [4, 5, 6] is from 100 -> 101 - > 110. you don't need 111, which is from 3 (0b11)

        int bitN = 0;  // start at rightmost bit of n
        for (int i = 0; i < 32; ++i) {
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

int main() {
    int n, x;
    Solution s;

    std::cout << "Enter a number n for the size of the array nums: ";
    std::cin >> n;
    std::cout << "Enter a number x that the array's bitwise AND should be"
                 " equal to: ";
    std::cin >> x;

    std::cout << "The minimum possible value of nums[n - 1] is: "
              << s.minEnd(n, x) << std::endl;

    return 0;
}

// std::bitset - https://en.cppreference.com/w/cpp/utility/bitset
// sizeof operator (how many bytes in an object?) - https://en.cppreference.com/w/cpp/language/sizeof
// CHAR_BIT (how many bits in a byte?) - https://en.cppreference.com/w/cpp/types/climits

// shoutout to knotri (Max Wood) on leetcode!