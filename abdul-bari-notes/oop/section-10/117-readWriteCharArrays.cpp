#include <iostream>

int main() {
    // char s1[20];
    // std::cout << "Enter a name (cin): ";
    // std::cin >> s1;
    // std::cout << "Welcome s1, " << s1 << std::endl;
    // // problem 1: cin >> only takes one word
    // // e.g., "John Doe" will just be read as "John"


    // char s2[50];  // max 50 char, including \0
    // std::cout << "Enter another name (cin.get): ";
    // std::cin.get(s2, 50);  // read up to 50 char, save in s2

    // // problem 2: enter key (\n) is NOT read by get(), it leaves the \n
    // // so, when you try to get an input with get() again, it ends early bc of \n
    // std::cout << "Enter the name again quickly!- ";
    // std::cin.get(s2, 50);  // end early because of \n given from last get() call
    // std::cout << "Ah.. darn get(). Sorry " << s2 << std::endl;


    // to prevent this problem, use cin.ignore(); after cin.get(s,n);
    // ignore() will ignore extra characters remaining after the first string
        // i.e., it will clear off the \n, so that you can read a fresh string
    char s3[50];
    std::cout << "Enter a name (cin.get and cin.ignore): ";
    std::cin.get(s3, 50);
    std::cin.ignore();  // ignore the \n and other keyboard buffers
    std::cout << "Welcome, " << s3 << std::endl;

    std::cout << "Enter a name (get() and ignore() pt. 2): ";
    std::cin.get(s3, 50);
    std::cin.ignore();
    std::cout << "Welcome, " << s3 << std::endl;


    // getline() allows you to get multiple "sentences", more than once!
    char s4[50];
    std::cout << "Enter a name (cin.getline): ";
    std::cin.getline(s4, 50);  // can use "John Doe" + handles keyboard buffers
    std::cout << "Welcome s4, " << s4 << std::endl;

    std::cout << "Enter a name (cin.getline pt. 2): ";
    std::cin.getline(s4, 50);  // don't need .ignore() since buffers handled
    std::cout << "Welcome new s4, " << s4 << std::endl;

    // TL;DR to read an input with multiple words/lines, use two methods
        // 1) std::cin.get(string, numLimit);
        //    std::cin.ignore();
        //
        // 2) std::cin.getline(string, numLimit);

    return 0;
}