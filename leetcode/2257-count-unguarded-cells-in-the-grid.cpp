#include <vector>

class Solution {
public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>>& guards, std::vector<std::vector<int>>& walls) {
        int unguardedCells = 0;
        // int grid[m][n];  // DOESN'T WORK! only vectors can use dynamic sizes!
        std::vector<std::vector<int>> grid(m, std::vector<int> (n, 0));
        
        // 0 - unguarded, 1 - guard, 2 - wall, 3 - guarded
        for (int g = 0; g < guards.size(); ++g) {
            grid[guards[g][0]][guards[g][1]] = 1;
        }
        for (int w = 0; w < walls.size(); ++w) {
            grid[walls[w][0]][walls[w][1]] = 2;
        }

        // for each guard, mark the cells that they cover
        for (int guard = 0; guard < guards.size(); ++guard) {
            int guardRow = guards[guard][0];
            int guardCol = guards[guard][1];

            // north
            for (int north = guardRow - 1; north >= 0; --north) {
                if (grid[north][guardCol] == 1 || grid[north][guardCol] == 2) {
                    break;
                }
                else {
                    grid[north][guardCol] = 3;
                }
            }

            // east
            for (int east = guardCol + 1; east < n; ++east) {
                if (grid[guardRow][east] == 1 || grid[guardRow][east] == 2) {
                    break;
                }
                else {
                    grid[guardRow][east] = 3;
                }
            }

            // south
            for (int south = guardRow + 1; south < m; ++south) {
                if (grid[south][guardCol] == 1 || grid[south][guardCol] == 2) {
                    break;
                }
                else {
                    grid[south][guardCol] = 3;
                }
            }

            // west
            for (int west = guardCol - 1; west >= 0; --west) {
                if (grid[guardRow][west] == 1 || grid[guardRow][west] == 2) {
                    break;
                }
                else {
                    grid[guardRow][west] = 3;
                }
            }
        }

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    ++unguardedCells;
                }
            }
        }

        return unguardedCells;
    }
};