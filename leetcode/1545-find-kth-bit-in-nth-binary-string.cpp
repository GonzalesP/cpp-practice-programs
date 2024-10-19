#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, std::string> binaryStrings;

    std::string invert(std::string binString) {
        std::string invertedBinString = "";

        for (int bit = 0; bit < binString.length(); bit++) {
            if (binString[bit] == '0') {
                invertedBinString += "1";
            }
            else {
                invertedBinString += "0";
            }
        }

        return invertedBinString;
    }

    std::string reverse(std::string binString) {
        std::string reversedBinString = "";

        for (int bit = binString.length() - 1; bit >= 0; bit--) {
            reversedBinString += binString[bit];
        }

        return reversedBinString;
    }

    // write the Nth Binary String
    std::string nthBinaryString(int n) {
        // S_1 = "0"
        if (n == 1) {
            return "0";
        }

        // S_n already exists in cache, retrieve and return it
        else if (binaryStrings.count(n)) {
            return binaryStrings[n];
        }

        // find S_n-1
        std::string prevBinString = nthBinaryString(n - 1);
        std::string nthBString = prevBinString + "1" + reverse(invert(prevBinString));

        // add S_n to cache
        binaryStrings[n] = nthBString;

        return nthBString;
    }

    char findKthBit(int n, int k) {
        std::string nthBinString = nthBinaryString(n);
        
        return nthBinString[k - 1];
    }
};

int main() {
    Solution s;
    std::cout << s.findKthBit(3, 1) << std::endl;
    std::cout << s.findKthBit(4, 11) << std::endl;

    return 0;
}