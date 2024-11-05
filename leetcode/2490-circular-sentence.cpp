#include <iostream>

class Solution {
public:
    bool isCircularSentence(std::string sentence) {
        // last word's last char ?= first word's first char?
        if (sentence[0] != sentence[sentence.length() - 1]) {
            return false;
        }

        // otherwise, at each space, make sure left/right chars are the same
        // (space will never be at front/end of sentence, so no out of bounds)
        for (int reader = 1; reader < sentence.length() - 1; ++reader) {
            if (sentence[reader] == ' ' && (sentence[reader - 1] != sentence[reader + 1])) {
                return false;
            }
        }

        return true;
    }
};