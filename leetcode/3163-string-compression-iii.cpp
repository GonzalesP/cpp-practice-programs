#include <iostream>
#include <string>

class Solution {
public:
    std::string compressedString(std::string word) {
        std::string comp = "";
        char currentLetter = word[0];
        int streak = 1;
        for (int reader = 1; reader < word.length(); ++reader) {
            // same letter
            if (word[reader] == word[reader - 1]) {
                // <= 9 times (9 max allowed)
                if (streak < 9) {
                    ++streak;
                }
                // 10th time, need to add 9 * letter now
                else {
                    comp += std::to_string(9) + currentLetter;
                    streak = 1;
                }
            }
            // not same letter -> update comp
            else {
                comp += std::to_string(streak) + currentLetter;
                currentLetter = word[reader];
                streak = 1;
            }
        }

        comp += std::to_string(streak) + currentLetter;
        return comp;
    }
};

int main() {
	Solution s;
	std::string word;
	std::cout << "Enter a word to compress (1 <= word.length() <= 2e5): ";
	std::cin >> word;

	std::cout << "The compressed result is: " << std::endl;
	std::cout << s.compressedString(word) << std::endl;
	return 0;
}