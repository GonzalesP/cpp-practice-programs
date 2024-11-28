#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int maxEqualRowsAfterFlips(std::vector<std::vector<int>>& matrix) {
        std::unordered_map<std::string, int> patterns;  // pattern (row of binary), count
        // NOTE: you cannot use <int, int> for keys because the constraints allows
        // rows to have up to 300 bits! (most machines use 32-bit ints)
        // so for e.g., 1 << 300 would be invalid

        for (int row = 0; row < matrix.size(); ++row) {
            // convert row (and its inverse) into string patterns
            std::string rowPattern = "";
            std::string rowInverse = "";
            for (int col = 0; col < matrix[row].size(); ++col) {
                if (matrix[row][col] == 0) {
                    rowPattern += '0';
                    rowInverse += '1';
                }
                else {
                    rowPattern += '1';
                    rowInverse += '0';
                }
            }

            if (patterns.count(rowPattern) == 1) {
                ++patterns[rowPattern];
            }
            else if (patterns.count(rowInverse) == 1) {
                ++patterns[rowInverse];
            }
            else {
                patterns[rowPattern] = 1;
            }
        }

        int maxRows = 0;  // equal rows
        for (auto iter = patterns.begin(); iter != patterns.end(); ++iter) {
            if (iter->second > maxRows) {
                maxRows = iter->second;
            }
        }

        return maxRows;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> testMatrix {{0,0,0},{0,0,1},{1,1,0}};

    std::cout << s.maxEqualRowsAfterFlips(testMatrix) << std::endl;

    return 0;
}