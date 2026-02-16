#include <iostream>
#include <string>

int main() {
    std::string str = "today";
    std::string::iterator it;

    // iterators are like pointers that can traverse a string's characters
    std::cout << "DEMO: print string using iterator" << std::endl;
    std::cout << "str: ";
    for (it = str.begin(); it != str.end(); it++)
        std::cout << *it;  // acts like a pointer -> need to dereference
    std::cout << std::endl;
    
    // not only can they read string characters, they can edit them too
    std::cout << std::endl;
    std::cout << "DEMO: capitalize a lowercase string w/ iterator" << std::endl;
    std::cout << "str: " << str << std::endl;
    std::cout << "*capitalizing...*" << std::endl;
    for (it = str.begin(); it != str.end(); it++) {
        *it -= 32;  // ASCII: all lower char are 32 ahead of upper variant
    }
    std::cout << "str: " << str << std::endl;

    // the String class also has a built in reverse iterator
    // these are used to traverse a string's characters from right to left
    str = "today";
    std::string::reverse_iterator rit;

    std::cout << std::endl;
    std::cout << "DEMO: printing backwards using rev. iterator" << std::endl;
    std::cout << "str: " << str << std::endl;
    std::cout << "str in reverse: ";
    // rbegin() points to rightmost char of string
    // rit++ will shift the reverse iterator towards the left
    for (rit = str.rbegin(); rit != str.rend(); rit++)
        std::cout << *rit;
    std::cout << std::endl;

    std::cout << std::endl;

    return 0;
}