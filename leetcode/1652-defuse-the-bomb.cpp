#include <vector>

class Solution {
public:
    std::vector<int> decrypt(std::vector<int>& code, int k) {
        if (k == 0) {
            std::vector<int> zeroVector(code.size(), 0);
            return zeroVector;
        }

        std::vector<int> decryption;
        for (int i = 0; i < code.size(); ++i) {
            int sum = 0;
            if (k > 0) {
                for (int j = 1; j <= k; ++j) {
                    sum += code.at((i + j) % code.size());
                }
            }
            else {
                for (int j = -1; j >= k; --j) {
                    if (i + j >= 0) {
                        sum += code.at((i + j) % code.size());
                    }
                    else {
                        sum += code.at((code.size() + i + j) % code.size());
                    }
                }
            }

            decryption.push_back(sum);
        }
        return decryption;
    }
};