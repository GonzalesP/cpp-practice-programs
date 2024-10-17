#include <iostream>
#include <string>

class Solution {
public:
    std::string greatestStartingLetter(int a, int b, int c) {
        if (a >= b && a >= c) {
            return "a";
        }
        else if (b >= a && b >= c) {
            return "b";
        }
        return "c";
    }

    std::string nextSubstring(int a, int b, int c, std::string nextLetter, int numLetter) {
        std::string nextSub = "";
        if (numLetter == 2) {
            nextSub = nextLetter + nextLetter;
        }
        else {
            nextSub = nextLetter;
        }

        if (nextLetter == "a") {
            a -= numLetter;
            if (b == 0 && c == 0) {
                return nextSub;
            }
            else if (b >= c) {
                if (b >= a) {
                    return nextSub + nextSubstring(a, b, c, "b", 2);
                }
                else {
                    return nextSub + nextSubstring(a, b, c, "b", 1);
                }
            }
            else {
                if (c >= a) {
                    return nextSub + nextSubstring(a, b, c, "c", 2);
                }
                else {
                    return nextSub + nextSubstring(a, b, c, "c", 1);
                }
            }
        }
        else if (nextLetter == "b") {
            b -= numLetter;
            if (a == 0 && c == 0) {
                return nextSub;
            }
            else if (a >= c) {
                if (a >= b) {
                    return nextSub + nextSubstring(a, b, c, "a", 2);
                }
                else {
                    return nextSub + nextSubstring(a, b, c, "a", 1);
                }
            }
            else {
                if (c >= b) {
                    return nextSub + nextSubstring(a, b, c, "c", 2);
                }
                else {
                    return nextSub + nextSubstring(a, b, c, "c", 1);
                }
            }
        }
        else {
            c -= numLetter;
            if (a == 0 && b == 0) {
                return nextSub;
            }
            else if (a >= b) {
                if (a >= c) {
                    return nextSub + nextSubstring(a, b, c, "a", 2);
                }
                else {
                    return nextSub + nextSubstring(a, b, c, "a", 1);
                }
            }
            else {
                if (b >= c) {
                    return nextSub + nextSubstring(a, b, c, "b", 2);
                }
                else {
                    return nextSub + nextSubstring(a, b, c, "b", 1);
                }
            }
        }
    }

    std::string longestDiverseString(int a, int b, int c) {
        std::string output = "";
        std::string nextLetter = greatestStartingLetter(a, b, c);
        int numLetter = 0;

        if (nextLetter == "a") {
            if (a >= 2)
                numLetter = 2;
            else
                numLetter = 1;
        }
        else if (nextLetter == "b") {
            if (b >= 2)
                numLetter = 2;
            else
                numLetter = 1;
        }
        else {
            if (c >= 2)
                numLetter = 2;
            else
                numLetter = 1;
        }

        output += nextSubstring(a, b, c, nextLetter, numLetter);
        return output;
    }
};

int main() {
  Solution s;
  std::cout << s.longestDiverseString(1, 1, 1) << std::endl;
  return 0;
}