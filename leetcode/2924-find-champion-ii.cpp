#include <vector>

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