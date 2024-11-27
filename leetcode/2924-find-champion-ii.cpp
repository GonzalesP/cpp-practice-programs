#include <vector>
#include <iostream>

class Solution {
public:
    int findChampion(int n, std::vector<std::vector<int>>& edges) {
        int champ = -1;
        int championCount = 0;
        std::vector<int> indegrees(n, 0);

        for (int edge = 0; edge < edges.size(); ++edge) {
            ++indegrees[edges[edge][1]];
        }

        for (int degree = 0; degree < indegrees.size(); ++degree) {
            if (indegrees[degree] == 0) {
                champ = degree;
                ++championCount;
            }
        }

        if (championCount != 1) {
            return -1;
        }
        else {
            return champ;
        }
    }
};

int main() {
    Solution s;

    int n1 = 3;
    std::vector<std::vector<int>> edges1 {{0,1}, {1,2}};

    int n2 = 4;
    std::vector<std::vector<int>> edges2 {{0,2}, {1,3}, {1,2}};

    std::cout << s.findChampion(n1, edges1) << std::endl;
    std::cout << s.findChampion(n2, edges2) << std::endl;

    return 0;
}