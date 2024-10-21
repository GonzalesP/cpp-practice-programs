#include <iostream>
#include <unordered_map>

class Solution {
public:
    int maxUniqueSplit(std::string s) {
        std::unordered_map<std::string, int> substrings;  // substr, index
        int readerIndex = 0;
        while (readerIndex < s.length()) {
            std::string sub = s.substr(readerIndex, readerIndex + 1);
            if (substrings.count(sub) < 1) {
                substrings[sub] = readerIndex;
            }
            ++readerIndex;
        }
        return substrings.size();
    }
};

// use a hash table to keep track of set of substrings

// first, try to split s into the smallest substring at eachindex
// (i.e., start off with one character at a time)

// then, when reading the rest of s, if a substring is repeated,
// backtrack to where the first occurrence is. then, extend it
// to the NEXT smallest substring (e.g., two characters)

// to check if a substring is repeated, do a look-up in the hash
// table: if the index of the entry in the hash table is different
// than the index you are currently on when reading the string, then
// you have encountered a repeated substring!