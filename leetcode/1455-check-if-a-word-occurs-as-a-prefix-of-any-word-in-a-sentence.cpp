#include <iostream>

class Solution {
public:
    int isPrefixOfWord(std::string sentence, std::string searchWord) {
        // check if prefix is in first word
        if (sentence.substr(0, searchWord.length()) == searchWord) {
            return 1;
        }

        int wordIndex = 2;
        // check other words (always after space)
        for (int i = 1; i < sentence.length(); ++i) {
            if (sentence[i - 1] == ' ') {
                if (sentence.substr(i, searchWord.length()) == searchWord) {
                    return wordIndex;
                }
                ++wordIndex;
            }
        }

        return -1;
    }
};