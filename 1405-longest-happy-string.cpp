#include <iostream>
#include <string>

class Solution {
public:
    int startingLetter(int a, int b, int c) {
        if (a >= b && a >= c) {
            return 0;
        }
        else if (b >= a && b >= c) {
            return 1;
        }
        else {
            return 2;
        }
    }

    std::string longestDiverseString(int a, int b, int c) {
        std::string output = "";
        int nextLetter = startingLetter(a, b, c);
        int numLetter = 0;

        if (nextLetter == 0) {
            if (a >= 2)
                numLetter = 2;
            else
                numLetter = 1;
        }
        else if (nextLetter == 1) {
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

        bool moreOptions = true;

        while(moreOptions) {
            if (nextLetter == 0) {
                if (numLetter == 2) {
                    output += "aa";
                }
                else {
                    output += "a";
                }
                a -= numLetter;

                if (b == 0 && c == 0) {
                    moreOptions = false;
                }
                else if (b >= c) {
                    nextLetter = 1;
                    if (b >= a && b >= 2) {
                        numLetter = 2;
                    }
                    else {
                        numLetter = 1;
                    }
                }
                else {
                    nextLetter = 2;
                    if (c >= a && c >= 2) {
                        numLetter = 2;
                    }
                    else {
                        numLetter = 1;
                    }
                }
            }
            else if (nextLetter == 1) {
                if (numLetter == 2) {
                    output += "bb";
                }
                else {
                    output += "b";
                }
                b -= numLetter;

                if (a == 0 && c == 0) {
                    moreOptions = false;
                }
                else if (a >= c) {
                    nextLetter = 0;
                    if (a >= b && a >= 2) {
                        numLetter = 2;
                    }
                    else {
                        numLetter = 1;
                    }
                }
                else {
                    nextLetter = 2;
                    if (c >= b && c >= 2) {
                        numLetter = 2;
                    }
                    else {
                        numLetter = 1;
                    }
                }
            }
            else {
                if (numLetter == 2) {
                    output += "cc";
                }
                else {
                    output += "c";
                }
                c -= numLetter;

                if (a == 0 && b == 0) {
                    moreOptions = false;
                }
                else if (a >= b) {
                    nextLetter = 0;
                    if (a >= c && a >= 2) {
                        numLetter = 2;
                    }
                    else {
                        numLetter = 1;
                    }
                }
                else {
                    nextLetter = 1;
                    if (b >= c && b >= 2) {
                        numLetter = 2;
                    }
                    else {
                        numLetter = 1;
                    }
                }
            }
        }

        return output;
    }
};

int main() {
  int a = 0, b = 0, c = 0;
  std::cout << "Choose 3 numbers for a, b, c" << std::endl;
  std::cout << "0 <= a, b, c <= 100 AND a + b + c > 0" << std::endl;
  std::cin >> a >> b >> c;

  Solution s;
  std::cout << s.longestDiverseString(a, b, c) << std::endl;
  return 0;
}