#include <vector>

class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& boxGrid) {
        std::vector<std::vector<char>> rotatedBox;

        // make stones fall
        for (int row = 0; row < boxGrid.size(); ++row) {
            for (int col = boxGrid[0].size() - 1; col >= 0; --col) {
                // come across empty cell
                if (boxGrid[row][col] == '.') {
                    for (int c = col - 1; c >= 0; --c) {
                        if (boxGrid[row][c] == '*') {
                            break;
                        }
                        else if (boxGrid[row][c] == '#') {
                            boxGrid[row][col] = '#';
                            boxGrid[row][c] = '.';
                            break;
                        }
                    }
                }
            }
        }

        // rotate box
        for (int col = 0; col < boxGrid[0].size(); ++col) {
            std::vector<char> rotatedRow;
            for (int row = boxGrid.size() - 1; row >= 0; --row) {
                rotatedRow.push_back(boxGrid[row][col]);
            }
            rotatedBox.push_back(rotatedRow);
        }

        return rotatedBox;
    }
};