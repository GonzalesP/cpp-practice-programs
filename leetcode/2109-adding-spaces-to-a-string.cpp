#include <iostream>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        std::stringstream formatedS;
        int spaceIndex = 0;

        for (int sIndex = 0; sIndex < s.size(); ++sIndex) {
            if (spaceIndex < spaces.size() && spaces[spaceIndex] == sIndex) {
                formatedS << ' ';
                ++spaceIndex;
            }
            formatedS << s[sIndex];
        }
        return formatedS.str();
    }
};

// lesson: concatenating a new stream saves a LOT more memory than
// copy assignment (especially with really long strings)