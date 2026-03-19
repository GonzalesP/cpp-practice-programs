#include <iostream>
#include <string>

int main() {
    // strings are objects that are provided by the string class
    // they are available in the std namespace
    std::string str = "Hello";
    std::cout << str << std::endl;  // "Hello"

    // getline() is provided by <string> and defined in the std namespace
    // it can be used to receive input for string objects (i.e., strings)
    std::cout << "Enter a new string for str: ";
    std::getline(std::cin, str);
    std::cout << str << std::endl;


    // string class functions

    // .length() - find out how many characters (letters, spaces, etc.) str has
    // another alias (?) is .size()
    std::cout << "str.length(): " << str.length() << std::endl;
    std::cout << "str.size(): " << str.size() << std::endl;

    // .capacity() - find the capacity of str (compilers may vary)
    // capacity = total str array length (including buffer after \0)
    std::cout << "str.capacity: " << str.capacity() << std::endl;

    // .resize() - edit the total capacity of str
    std::cout << "*changing str's capacity using resize()...*" << std::endl;
    str.resize(100);
    std::cout << "new str.capacity(): " << str.capacity() << std::endl;

    // .max_size() - find the maximum possible size a string can have
    // in the given compiler
    std::cout << "max_size(): " << str.max_size() << std::endl;

    // .clear() - clear the contents of str (becomes an empty string - "")
    // another alias is .erase()
    std::cout << "*clearing str using .clear()...*" << std::endl;
    str.clear();  // str.erase(); does the same
    std::cout << "str: " << str << std::endl;  // blank
    std::cout << "str.length(): " << str.length() << std::endl;

    // .empty() - check if str is empty (returns bool)
    std::cout << "str.empty(): " << str.empty() << std::endl;  // 1 (true)


    // .append() - add content to the end of a string
    std::cout << std::endl;
    std::cout << "DEMO: append()" << std::endl;

    str = "Hello";
    std::cout << "str: " << str << std::endl;
    std::cout << "*str.append(\" world\")...*" << std::endl;
    str.append(" world");  // add to end of str
    std::cout << "str: " << str << std::endl;  // "Hello world"
    // capacity changes automatically if needed - new cap. chosen by compiler

    // .insert(index, str) - insert a new string STARTING AT the given index
    std::cout << std::endl;
    std::cout << "DEMO: insert()" << std::endl;

    str = "Hello";
    std::string ins = "Apple";
    std::cout << "str: " << str << std::endl;
    std::cout << "ins: " << ins << std::endl;
    std::cout << "*str.insert(3, ins)...*" << std::endl;
    str.insert(3, ins);
    std::cout << "str: " << str << std::endl;  // HelApplelo

    // when using string literals, you can include a number
    // if you only want the first n char of the string literal
    std::cout << "*str.insert(3, \"Banana\", 3)...*" << std::endl;
    str.insert(3, "Banana", 3);  // first 3 char of "Banana" inserted at index 3
    std::cout << "str: " << str << std::endl;  // HelBanApplelo
    // note: THIS IS WITH A STRING LITERAL ("Banana")!
    // using a string object instead of a literal will yield different results!!


    // .replace(index, eLength, str) - replace a portion of s with str
    std::cout << std::endl;
    std::cout << "DEMO: replace()" << std::endl;

    str = "Programming";
    std::cout << "str: " << str << std::endl;  // Pro|gram|ming (ignore the |)
    std::cout << "*str.replace(3, 4, \"kk\")...*" << std::endl;
    str.replace(3, 4, "kk");  // The four char starting from index 3 become kk
    std::cout << "str: " << str << std::endl;  // Pro|kk|ming (ignore the |)

    // .push_back(char) - append a single character to the end of the string
    std::cout << std::endl;
    std::cout << "DEMO: push_back()" << std::endl;

    str = "Hello";
    std::cout << "str: " << str << std::endl;
    std::cout << "*str.push_back('z')...*" << std::endl;
    str.push_back('z');  // becomes Helloz
    std::cout << "str: " << str << std::endl;

    // .pop_back() - remove a single character from the end of the string
    std::cout << std::endl;
    std::cout << "DEMO: pop_back()" << std::endl;

    std::cout << "str: " << str << std::endl;
    std::cout << "*str.pop_back()...*" << std::endl;
    str.pop_back();  // back to Hello
    std::cout << "str: " << str << std::endl;  // "acts like a backspace key"

    // str1.swap(str2) - str1 and str2 will swap contents (i.e., switch strings)
    std::cout << std::endl;
    std::cout << "DEMO: swap()" << std::endl;

    std::string s1 = "AAA";
    std::string s2 = "BBB";
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "*s1.swap(s2)...*" << std::endl;
    s1.swap(s2);  // s1 switches its contents with s2
    std::cout << "s1: " << s1 << std::endl;  // "BBB"
    std::cout << "s2: " << s2 << std::endl;  // "AAA"


    // s.copy(char str[], sLen) - copy sLen characters from s into str
    std::cout << std::endl;
    std::cout << "DEMO: copy()" << std::endl;

    str = "Welcome";
    char strCopy[10];
    std::cout << "str: " << str << std::endl;
    std::cout << "strCopy (blank): " << strCopy << std::endl;
    std::cout << "*str.copy(strCopy, str.length())...*" << std::endl;
    str.copy(strCopy, str.length());  // copy ALL of str, put INTO strCopy
    std::cout << "strCopy: " << strCopy << std::endl;  // Welcome (same as str)

    // note: if you don't use str.length(), strCopy will not have a \0
    // in the intended place (end of its array)

    // e.g., str.copy(strCopy, 3);  will be Wel<\junk values>
    // to prevent this, add a \0 at the end of the copied substring
    // e.g., str.copy(strCopy, 3);
    // str[3] = '\0';  // becomes "Wel\0", which reads and prints properly

    // .find(str) or .find(char) - find the index where a given string/char is
    // returns the FIRST occurrence from the LEFT hand side
    std::cout << std::endl;
    std::cout << "DEMO: find()" << std::endl;

    str = "How are you";
    std::cout << "str: " << str << std::endl;
    std::cout << "str.find(\"are\"): " << str.find("are") << std::endl;  // 4
    std::cout << "str.find('y'): " << str.find('y') << std::endl;  // 8
    std::cout << "str.find('o'): " << str.find('o') << std::endl;  // 1

    // .rfind(str) or .rfind(char) - same purpose, but reads from the RIGHT
    std::cout << "str.rfind('o'): " << str.rfind('o') << std::endl;  // 9
    std::cout << "str.rfind('k'): " << str.rfind('k') << std::endl;
    // if query not found, find/rfind will return -1 or max_size (compiler)

    // note: to error check for missing strings, you can compare the output
    // to the length of str. if the output is larger (out of bounds),
    // then the query does not exist within str

    // .find_first_of(char) - find first occurrence of char from left
    std::cout << std::endl;
    std::cout << "DEMO: find_first_of() and find_last_of()" << std::endl;

    str = "Hello World";
    std::cout << "str: " << str << std::endl;
    std::cout << "str.find_first_of('l'): "
              << str.find_first_of('l') << std::endl;  // 2
    
    // .find_first_of(char, startIndex) - same, but starting from startIndex
    std::cout << "str.find_first_of('l', 4): "
              << str.find_first_of('l', 4) << std::endl;  // 9
    
    // note: if you use a string, the string itself won't be searched.
    // instead, all characters in string will be independently queried!
    std::cout << "str.find_first_of(\"le\"): "  // first index of 'l' OR 'e'
              << str.find_first_of("le") << std::endl;  // 1 - first 'e'

    // .find_last_of(char) - find first occurrence from the right
    std::cout << "str.find_last_of('l'): "
              << str.find_last_of('l') << std::endl;  // 9
    

    // .substr(index) - gives substring starting from index to end (string obj)
    std::cout << std::endl;
    str = "Programming";
    std::cout << "str: " << str << std::endl;  // Programming
    std::cout << "str.substr(3): " << str.substr(3) << std::endl;  // gramming

    // .substr(index, num) - gives substring with num total characters
    std::cout << "str.substr(3, 4): " << str.substr(3, 4) << std::endl;  // gram

    // s1.compare(s2) - compares s1 and s2. (-) means s1 comes before s2, 0 is =
    std::cout << std::endl;
    std::cout << "DEMO: compare()" << std::endl;

    s1 = "apple";  // a comes before b alphabetically -> s1 < s2
    s2 = "banana";
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s1.compare(s2): " << s1.compare(s2) << std::endl;  // (-)

    // s1.at(index) - get the char at index ; can also use s1[index]
    std::cout << std::endl;
    std::cout << "DEMO: at()" << std::endl;

    str = "Greetings";
    std::cout << "str: " << str << std::endl;
    std::cout << "str.at(4): " << str.at(4) << std::endl;  // t
    std::cout << "str[4]: " << str[4] << std::endl;  // t
    // can also edit strings (e.g., str[4] = 'a'; ... str = "Greeaings")

    // s1.front() - get first char
    std::cout << std::endl;
    std::cout << "DEMO: front()" << std::endl;

    std::cout << "str: " << str << std::endl;
    std::cout << "str.front(): " << str.front() << std::endl;  // G

    // s1.back() - get last char
    std::cout << std::endl;
    std::cout << "DEMO: back()" << std::endl;

    std::cout << "str: " << str << std::endl;
    std::cout << "str.back(): " << str.back() << std::endl;  // s

    // + operator: concatenates two strings (like append())
    std::cout << std::endl;
    std::cout << "DEMO: + operator" << std::endl;
    
    s1 = "Apple";
    s2 = "Cider";
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s1 + s2: " << s1 + s2 << std::endl;  // AppleCider

    // = operator: copies right side string into left hand string
    std::cout << std::endl;
    std::cout << "DEMO: = operator" << std::endl;

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "*s1 = s2...*" << std::endl;
    s1 = s2;  // s1 is assigned the same contents of s2
    std::cout << "s1: " << s1 << std::endl;  // Cider
    std::cout << "s2: " << s2 << std::endl;  // Cider

    return 0;
}