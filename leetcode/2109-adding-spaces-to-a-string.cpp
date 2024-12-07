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

int main() {
    Solution sol;
    std::string noSpace;
    std::vector<int> spaceIndices;
    int index = 0;

    std::cout << "Enter a string to add spaces to: ";
    std::cin >> noSpace;

    std::cout << "Enter the indices where spaces should be inserted: " << std::endl;
    while(std::cin >> index) {
        spaceIndices.push_back(index);
    }

    std::cout << "Formatted string: " << std::endl;
    std::cout << sol.addSpaces(noSpace, spaceIndices) << std::endl;

    return 0;
}

// lesson: concatenating a new stream saves a LOT more memory than
// copy assignment (especially with really long strings)