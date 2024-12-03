#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) {
        std::unordered_map<int, int> prevElements;  // value, index
        for (int i = 0; i < arr.size(); ++i) {
            if (prevElements.count(2 * arr[i]) == 1) {
                return true;
            }
            else if (arr[i] % 2 == 0 && prevElements.count(arr[i] / 2) == 1) {
                return true;
            }
            else {
                prevElements[arr[i]] = i;
            }
        }
        return false;
    }
};