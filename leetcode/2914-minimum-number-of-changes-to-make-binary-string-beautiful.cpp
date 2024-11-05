#include <iostream>

class Solution {
public:
    int minChanges(std::string s) {
        int totalChanges = 0;
        for (int index = 0; index < s.length(); index += 2) {
            if (s[index] != s[index + 1]) {
                ++totalChanges;
            }
        }
        return totalChanges;
    }
};

int main() {
  Solution s;
  std::string originalString;
  std::cout << "Enter a string of 0's and 1's with even length: ";
  std::cin >> originalString;
  std::cout << "The minimum number of changes needed to make this "
            << "string beautiful is: " << s.minChanges(originalString) << std::endl;

  return 0;
}