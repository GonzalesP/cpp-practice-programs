#include <iostream>

class Solution {
public:
    std::string makeFancyString(std::string s) {
        std::string fancyS = "";
        char currentChar = s[0];  // current char
        int consecutiveCounts = 0;

        for (int readerIndex = 0; readerIndex < s.length(); ++readerIndex) {
            char r = s[readerIndex];  // char at readerIndex
            if (r != currentChar) {
                fancyS += r;
                currentChar = r;
                consecutiveCounts = 1;
            }
            else if (consecutiveCounts < 2) {
                fancyS += r;
                ++consecutiveCounts;
            }
        }

        return fancyS;
    }
};