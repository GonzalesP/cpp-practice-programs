#include <iostream>

int main() {
    // 80 - Print a number in reverse
    int n1, r1;
    std::cout << "Enter a number > 0 to print it in reverse: ";
    std::cin >> n1;

    while (n1 > 0) {
        r1 = n1 % 10;
        n1 /= 10;
        std::cout << r1;
    }
    std::cout << std::endl;


    // 81 - Armstrong number
    // the sum of a number's cubed digits should equal itself
    int n2, r2, sum = 0;
    std::cout << "Determine if a number is an Armstrong Number: ";
    std::cin >> n2;

    int n2copy = n2;  // save original value of n2 for comparison later
    while (n2 > 0) {
        r2 = n2 % 10;
        n2 /= 10;
        sum += r2 * r2 * r2;
    }

    if (n2copy == sum)
        std::cout << n2copy << " IS an Armstrong number." << std::endl;
    else
        std::cout << n2copy << " IS NOT an Armstrong number." << std::endl;


    // 82 - Reverse a number as an int
    int n3, r3, rev1 = 0;
    std::cout << "Enter a number to reverse it: ";
    std::cin >> n3;

    while (n3 > 0) {
        r3 = n3 % 10;
        n3 /= 10;
        rev1 = rev1 * 10 + r3;
    }
    std::cout << "reverse: " << rev1 << std::endl;

    // check if a number is a palindrome
    int n4, r4, rev2 = 0;
    std::cout << "Check if a number is a palindrome: ";
    std::cin >> n4;

    int n4copy = n4;  // compare to original later
    while (n4 > 0) {
        r4 = n4 % 10;
        n4 /= 10;
        rev2 = rev2 * 10 + r4;
    }
    if (n4copy == rev2)
        std::cout << n4copy << " IS a palindrome." << std::endl;
    else
        std::cout << n4copy << " IS NOT a palindrome." << std::endl;

    // print a number's digits as words (forwards)
    // (e.g., 145 prints "one four five")
    int n5, r5, rev3 = 0;
    std::cout << "Enter a number to print its digits in words: ";
    std::cin >> n5;

    while (n5 > 0) {
        r5 = n5 % 10;
        n5 /= 10;
        rev3 = rev3 * 10 + r5;
    }

    // with a number reversed, you can traverse it backwards and print digits.
    // doing so will print the original (non-reversed) number's digits in order
    int rr;
    while (rev3 > 0) {
        rr = rev3 % 10;
        rev3 /= 10;
        switch (rr) {
            case 0: std::cout << "zero ";
                    break;
            case 1: std::cout << "one ";
                    break;
            case 2: std::cout << "two ";
                    break;
            case 3: std::cout << "three ";
                    break;
            case 4: std::cout << "four ";
                    break;
            case 5: std::cout << "five ";
                    break;
            case 6: std::cout << "six ";
                    break;
            case 7: std::cout << "seven ";
                    break;
            case 8: std::cout << "eight ";
                    break;
            case 9: std::cout << "nine ";
                    break;
        }
    }
    std::cout << std::endl;

    return 0;



    // note: I think some programs do not yield the right answer when they have
    // a number ending in zero... oops - namely the digits to words code
}