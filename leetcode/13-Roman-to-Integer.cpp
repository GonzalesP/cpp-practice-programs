#include <iostream>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        // character weight, count
        std::unordered_map<int, int> digits = {{1, 0}, {4, 0}, {5, 0}, {9, 0},
                                          {10, 0}, {40, 0}, {50, 0}, {90, 0},
                                          {100, 0}, {400, 0}, {500, 0},
                                          {900, 0}, {1000, 0}};

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'I') {
                if (i < s.length() - 1) {
                    if (s[i+1] == 'V') {
                        ++digits[4];
                        ++i;
                    }
                    else if (s[i+1] == 'X') {
                        ++digits[9];
                        ++i;
                    }
                    else {
                        ++digits[1];
                    }
                }
                else {
                    ++digits[1];
                }
            }
            else if (c == 'X') {
                if (i < s.length() - 1) {
                    if (s[i+1] == 'L') {
                        ++digits[40];
                        ++i;
                    }
                    else if (s[i+1] == 'C') {
                        ++digits[90];
                        ++i;
                    }
                    else {
                        ++digits[10];
                    }
                }
                else {
                    ++digits[10];
                }
            }
            else if (c == 'C') {
                if (i < s.length() - 1) {
                    if (s[i+1] == 'D') {
                        ++digits[400];
                        ++i;
                    }
                    else if (s[i+1] == 'M') {
                        ++digits[900];
                        ++i;
                    }
                    else {
                        ++digits[100];
                    }
                }
                else {
                    ++digits[100];
                }
            }
            else if (c == 'V') {
                ++digits[5];
            }
            else if (c == 'L') {
                ++digits[50];
            }
            else if (c == 'D') {
                ++digits[500];
            }
            else if (c == 'M') {
                ++digits[1000];
            }
        }

        return digits[1] + 4 * digits[4] + 5 * digits[5] + 9 * digits[9] +
               10 * digits[10] + 40 * digits[40] + 50 * digits[50] +
               90 * digits[90] + 100 * digits[100] + 400 * digits[400] +
               500 * digits[500] + 900 * digits[900] + 1000 * digits[1000];
    }
};

// better alternative: use {1, 0}, {4, 0}, {5, 0}, and {9, 0}
// and add 1, 10, 100, or 1000 depending on symbol (save more space)