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
    std::cout << "*clearing str using .clear()...*" << std::endl;
    str.clear();
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

    return 0;
}