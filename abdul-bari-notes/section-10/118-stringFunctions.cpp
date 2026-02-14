#include <iostream>
#include <cstring>

int main() {
    std::cout << std::endl;

    // std::strlen(str)  - prints the length of str
    std::cout << "DEMO: strlen" << std::endl;

    char str1[50] = "Hello";
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str1 length: " << std::strlen(str1) << std::endl;  // 5

    char str2[50] = "Hello World";
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str2 length: " << std::strlen(str2) << std::endl;  // 11


    // std::strcat(destination, source)  - appends source to end of dest
    std::cout << std::endl;
    std::cout << "DEMO: strcat" << std::endl;

    char str3[20] = "Good";
    char str4[10] = "Morning";
    std::cout << "str3: " << str3 << std::endl;
    std::cout << "str4: " << str4 << std::endl;

    std::strcat(str3, str4);  // add str4 to the end of str3
    std::cout << "*strcat(str3, str4)*" << std::endl;
    std::cout << "new str3: " << str3 << std::endl;  // GoodMorning

    // std::strncat(destination, source, length)  - append n characters
    std::cout << std::endl;
    std::cout << "DEMO: strncat" << std::endl;

    char str5[20] = "Good";
    char str6[10] = "Afternoon";
    std::cout << "str5: " << str5 << std::endl;
    std::cout << "str6: " << str6 << std::endl;

    std::strncat(str5, str6, 5);  // add "After" from str6 to str5
    std::cout << "*strcat(str5, str6, 5)*" << std::endl;
    std::cout << "new str5: " << str5 << std::endl;  // GoodAfter


    // std::strcpy(destination, source)  - contents of source are copied into d
    std::cout << std::endl;
    std::cout << "DEMO: strcpy" << std::endl;

    char str7[20] = "Good";
    char str8[10] = "a";
    std::cout << "str7: " << str7 << std::endl;
    std::cout << "str8: " << str8 << std::endl;

    std::strcpy(str8, str7);  // data of str8 becomes the same as str7 ("Good")
    std::cout << "*strcpy(str8, str7)*" << std::endl;
    std::cout << "new str8: " << str8 << std::endl;

    // std::strncpy(destination, source, length)  - copy n chars from source
    std::cout << std::endl;
    std::cout << "DEMO: strncpy" << std::endl;

    char str9[20] = "Good";
    char str10[10] = "a";
    std::cout << "str9: " << str9 << std::endl;
    std::cout << "str10: " << str10 << std::endl;

    std::strncpy(str10, str9, 2);  // data of str10 becomes str7 first two char
    std::cout << "*strncpy(str10, str9, 2)*" << std::endl;
    std::cout << "new str10: " << str10 << std::endl;  // "Go"


    // std::strstr(main, sub);  // if "sub" found, return rest of string
    std::cout << std::endl;
    std::cout << "DEMO: strstr" << std::endl;

    char str11[20] = "Programming";
    char str12[10] = "gram";
    char str13[10] = "m";
    std::cout << "str11: " << str11 << std::endl;
    std::cout << "str12: " << str12 << std::endl;
    std::cout << "str13: " << str13 << std::endl;

    std::cout << "strstr(str11, str12): "
              << std::strstr(str11, str12) << std::endl;  // gramming
    std::cout << "strstr(str11, str13): "
              << std::strstr(str11, str13) << std::endl;  // mming
    
    char str14[10] = "k";  // if sub not in main, strstr returns NULL
    std::cout << "str14: " << str14 << std::endl;
    if (std::strstr(str11, str14) != NULL) {
        std::cout << "This will not be printed." << std::endl;
    }
    else {
        std::cout << "str14 was not found in str11" << std::endl;
    }


    // std::strchr(main, char) - gives substring starting from left hand side
    std::cout << std::endl;
    std::cout << "DEMO: strchr" << std::endl;

    char str15[20] = "Programming";
    std::cout << "str15: " << str15 << std::endl;
    std::cout << "strchr(str15, 'g'): "
              << std::strchr(str15, 'g') << std::endl;  // gramming
    std::cout << "strchr(str15, 'r'): "
              << std::strchr(str15, 'r') << std::endl;  // rogramming
    // returns NULL if char not found
    // std::strchr(str15, 'p')  - NULL because there is no 'p', only 'P'


    // std::strrchr(main, char) - gives substring starting from right hand side
    std::cout << std::endl;
    std::cout << "DEMO: strrchr" << std::endl;

    std::cout << "strrchr(str15, 'g'): "
              << std::strrchr(str15, 'g') << std::endl;  // g
    std::cout << "strrchr(str15, 'r'): "
              << std::strrchr(str15, 'r') << std::endl;  // ramming
    
    
    // strcmp(str1, str2) - compare two strings
    // if str1 comes BEFORE str 2 alphabetically, a (-) value is returned
        // e.g., apple < banana, strcmp("a", "b") is negative
    // if str1 comes AFTER str 2 alphabetically, a (+) value is returned
    // if str1 == str2, 0 is returned
    std::cout << std::endl;
    std::cout << "DEMO: strcmp" << std::endl;

    char str16[20] = "Hello";
    char str17[20] = "Hello";
    std::cout << "str16: " << str16 << std::endl;
    std::cout << "str17: " << str17 << std::endl;
    std::cout << "strcmp(str16, str17): "
              << std::strcmp(str16, str17) << std::endl;  // 0

    char str18[20] = "apple";
    char str19[20] = "banana";
    std::cout << "str18: " << str18 << std::endl;
    std::cout << "str19: " << str19 << std::endl;
    std::cout << "strcmp(str18, str19): "
              << std::strcmp(str18, str19) << std::endl;
    // apple comes first alphabetically -> result is negative

    char str20[20] = "lower";  // all uppercase come before lowercase
    char str21[20] = "UPPER";  // e.g., 'A' < 'a' => 65 < 97
    std::cout << "str20: " << str20 << std::endl;
    std::cout << "str21: " << str21 << std::endl;
    std::cout << "strcmp(str20, str21): "
              << std::strcmp(str20, str21) << std::endl;
    // lower comes second alphabetically -> result is positive


    // strtol(str1, NULL, 10)  - convert a string into a long int
        // string, ending char, base 10
    std::cout << std::endl;
    std::cout << "DEMO: strtol" << std::endl;

    char strLong[10] = "237";  // cannot be used for int arithmetic
    std::cout << "strLong: " << strLong << std::endl;  // "237"

    long int x = strtol(strLong, NULL, 10);  // 237
    std::cout << "x: " << x << std::endl;
    std::cout << "x + 10: " << x + 10 << std::endl; // 247
    // now you can do int arithmetic (e.g., 237 + 10)


    // strtof(str1, NULL)  - convert a string into a float
    std::cout << std::endl;
    std::cout << "DEMO: strtof" << std::endl;

    char strFloat[10] = "53.76";
    std::cout << "strFloat: " << strFloat << std::endl;  // "53.76"

    float y = strtof(strFloat, NULL);  // 53.76
    std::cout << "y: " << y << std::endl;
    std::cout << "y + 5: " << y + 5 << std::endl;  // 58.76


    // strtok(str1, "<delimiters>")  - tokenize a string using delimiters
    std::cout << std::endl;
    std::cout << "DEMO: strtok" << std::endl;

    char strTokens1[20] = "x=10;y=20;z=35";
    std::cout << "strTokens1: \"" << strTokens1 << "\"" << std::endl;
    std::cout << "strtok(strTokens1, \";\"): "
              << strtok(strTokens1, ";") << std::endl;  // only gives one token
    // will print "x=10" (first token before first ;)
    // stops at ";" because it is a delimiter: strtok(strTokens, ";")
    // to repeat tokenizing, you need a while loop

    std::cout << std::endl;

    char strTokens2[20] = "x=10;y=20;z=35";
    std::cout << "strTokens2: \"" << strTokens2 << "\"" << std::endl;

    char *token = strtok(strTokens2, ";");
    std::cout << "printing all tokens using a loop: " << std::endl;
    while (token != NULL) {  // when token is NULL, you reach the end of str \0
        std::cout << token << std::endl;
        token = strtok(NULL, ";");
        // NULL - continue using the same string, move to the next token
    }
    // prints: x=10  \n  y=20  \n z=35

    
    std::cout << std::endl;
    
    return 0;
}