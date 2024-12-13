#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int readerIndex = 0;  // nth char of all strings in strs
        int prefixLength = 0;  // length of common prefix
        char r;  // character at readerIndex
        bool prefixEnd = false;

        while(!prefixEnd) {
            if (readerIndex >= strs.at(0).length()) {
                break;
            }

            r = strs.at(0)[readerIndex];
            for (int i = 1; i < strs.size(); ++i) {
                if (readerIndex >= strs.at(i).length()) {
                    prefixEnd = true;
                    break;
                }
                else if (strs.at(i)[readerIndex] != r) {
                    prefixEnd = true;
                    break;
                }
            }

            if (!prefixEnd) {
                ++prefixLength;
            }
            ++readerIndex;
        }

        return strs.at(0).substr(0, prefixLength);
    }
};

int main() {
    Solution s;
    std::vector<std::string> strings = {"flower", "flow", "flight"};
    std::cout << "The longest common prefix in strings is: "
              << s.longestCommonPrefix(strings) << std::endl;

    return 0;
}