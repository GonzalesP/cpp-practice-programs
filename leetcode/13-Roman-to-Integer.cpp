#include <iostream>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        // character weight, count
        std::unordered_map<int, int> digits = {{1, 0}, {4, 0}, {5, 0}, {9, 0}};

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
                        digits[4] += 10;
                        ++i;
                    }
                    else if (s[i+1] == 'C') {
                        digits[9] += 10;
                        ++i;
                    }
                    else {
                        digits[1] += 10;
                    }
                }
                else {
                    digits[1] += 10;
                }
            }
            else if (c == 'C') {
                if (i < s.length() - 1) {
                    if (s[i+1] == 'D') {
                        digits[4] += 100;
                        ++i;
                    }
                    else if (s[i+1] == 'M') {
                        digits[9] += 100;
                        ++i;
                    }
                    else {
                        digits[1] += 100;
                    }
                }
                else {
                    digits[1] += 100;
                }
            }
            else if (c == 'V') {
                ++digits[5];
            }
            else if (c == 'L') {
                digits[5] += 10;
            }
            else if (c == 'D') {
                digits[5] += 100;
            }
            else if (c == 'M') {
                digits[1] += 1000;
            }
        }

        return digits[1] + 4 * digits[4] + 5 * digits[5] + 9 * digits[9];
    }
};

int main() {
    Solution s;
    std::string romanNumeral;
    std::cout << "Enter a roman numeral: " << std::endl;
    std::cin >> romanNumeral;
    std::cout << "The roman numeral " << romanNumeral << " is equal to: "
              << s.romanToInt(romanNumeral) << std::endl;

    return 0;
}

// better alternative: use {1, 0}, {4, 0}, {5, 0}, and {9, 0}
// and add 1, 10, 100, or 1000 depending on symbol (save more space)