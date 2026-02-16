#include <iostream>
#include <string>

int main() {
    // find the length of a string (without using length())
    std::cout << "#1: find string length without length()" << std::endl;

    std::string str = "WELCOME";  // length should be 7
    std::cout << "str: " << str << std::endl;

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)  // \0 is at the end of all strings
        count++;
    std::cout << "count (for loop using i): " << count << std::endl;

    count = 0;
    std::string::iterator it;
    for (it = str.begin(); it != str.end(); it++)
        count++;
    std::cout << "count (iterator): " << count << std::endl;


    // convert an upper case string into lowercase
    // note: all lowercase letters are +32 of their respective uppercase letters
    std::cout << std::endl;
    std::cout << "#2a: convert a string to lowercase" << std::endl;

    str = "WELcoME2";
    std::cout << "str: " << str << std::endl;

    std::cout << "*converting to lowercase...*" << std::endl;
    // for (int i = 0; str[i] != '\0'; i++)
        // str[i] += 32;  // *if between 65 and 90 inclusive
    for (it = str.begin(); it != str.end(); it++) {
        if (*it >= 65 && *it <= 90)  // ONLY CHANGE 'A'-'Z'
            *it += 32;
    }
    std::cout << "str: " << str << std::endl;

    
    // convert a lower case string into uppercase
    std::cout << std::endl;
    std::cout << "#2b: convert a string to uppercase" << std::endl;

    str = "WeLcOmE5";
    std::cout << "str: " << str << std::endl;

    std::cout << "*converting to uppercase...*" << std::endl;
    // for (int i = 0; str[i] != '\0'; i++)
        // str[i] -= 32;  // *if in between 97 and 122 inclusive
    for (it = str.begin(); it != str.end(); it++) {
        if (*it >= 97 && *it <= 122)  // ONLY CHANGE 'a'-'z'
            *it -= 32;
    }
    std::cout << "str: " << str << std::endl;


    // counnt how many vowels, consonants, and words are in a string
    // assume that the string is not empty
    std::cout << std::endl;
    std::cout << "#3: count vowels, consonants, and words" << std::endl;

    str = "how Many wOrds";
    std::cout << "str: " << str << std::endl;

    std::string vowels = "AEIOUaeiou";
    int vowelCount = 0;
    int consonantCount = 0;
    int wordCount = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        // first, check if the character is an upper/lowercase letter
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            if (vowels.find(str[i]) >= 0 &&
                vowels.find(str[i]) < vowels.length()) {
                vowelCount++;
            }
            else
                consonantCount++;
        }
        // then, if there is a space(s) after the character, the word has ended
        // and a new word will start after the space(s)
        if (str[i] != ' ' && i < str.length() - 1 && str[i+1] == ' ') {
            wordCount++;
        }
    }

    // if the string has an extra space(s) at the end, decrement the word count
    // (because you should only count the spaces that are BETWEEN words)
    if (str[str.length() - 1] == ' ')
        wordCount--;
    
    // if the string is empty, there should 0 words
    if (str == "")
        wordCount = 0;

    std::cout << "vowelCount: " << vowelCount << std::endl;
    std::cout << "consonantCount: " << consonantCount << std::endl;
    std::cout << "words: " << wordCount << std::endl;


    // check if a word is a palindrome
    std::cout << std::endl;
    std::cout << "#4: check if a word is a palindrome" << std::endl;

    str = "racecar";
    std::cout << "str: " << str << std::endl;

    bool palindrome = true;
    std::string::reverse_iterator rit = str.rbegin();
    
    // first, convert everything into same case
    // e.g. Madam in reverse is madaM, but it should still be a palindrome
    // so, making the string MADAM will yield the same result when checking
    for (it = str.begin(); it != str.end(); it++) {
        if (*it >= 97 && *it <= 122)  // ONLY CHANGE 'a'-'z'
            *it -= 32;
    }

    // next, make sure that the word read forwards is the same read backwards
    for (it = str.begin(); it != str.end(); it++) {
        if (*it != *rit) {
            palindrome = false;
            break;
        }
        rit++;
    }

    // finally, print wether str is a palindrome or not using the bool
    if (palindrome) {
        std::cout << str << " IS a palindrome" << std::endl;
    }
    else {
        std::cout << str << " IS NOT a palindrome" << std::endl;
    }


    // obtain a username given by an email address (e.g., name@gmail.com: name)
    std::cout << std::endl;
    std::cout << "#5: getting a username from an email address" << std::endl;

    std::string email = "jO#hn_12.3@gmail.com";
    std::cout << "email: " << email << std::endl;

    int atsignIndex = email.find('@');
    std::string user = email.substr(0, atsignIndex);

    std::cout << "user: " << user << std::endl;


    // check if a user is valid: only letters, numbers, _ or .
    std::string numberChars = "0123456789";
    bool validUser = true;

    for (it = user.begin(); it != user.end(); it++) {
        char c = *it;
        // not uppercase/lowercase letter, not a number char, and not _ or .
        if (!(c >= 65 && c <= 90) && !(c>=97 && c<=122) &&
            !(numberChars.find(c) >= 0 &&
              numberChars.find(c) < numberChars.length()) &&
            c != '_' && c != '.') {
                validUser = false;
        }
    }

    if (validUser) {
        std::cout << user << " IS a valid username" << std::endl;
    }
    else {
        std::cout << user << " IS NOT a valid username" << std::endl;
    }

    return 0;
}