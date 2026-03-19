#include <iostream>

int main() {
    int a = 10, b = 5;

    // AND compound condition terminates at first FALSE term
    int i1 = 5;
    if (a < b && ++i1 >= 5) {
        // AND condition returns false
        std::cout << "This line IS NOT executed." << std::endl;
    }
    // a < b is false, so second term never executes, i1 will be 5
    std::cout << "i1: " << i1 << std::endl;

    // OR compound condition terminates at first TRUE term
    int i2 = 5;
    if (a > b || ++i2 >=5) {
        // OR condition returns true
        std::cout << "This line IS executed, but not ++i2." << std::endl;
    }
    // a > b is true, so i2 will not increment, i2 will be 5
    std::cout << "i2: " << i2 << std::endl;

    // pre-increment will still work, regardless of resulting boolean
    int i3 = 5;
    if (a > b && ++i3 <= b) {
        // AND condition returns false
        std::cout << "i3 = 6 (!<= b), so this never prints" << std::endl;
    }
    std::cout << "i3: " << i3 << std::endl;

    int i4 = 5;
    if (a > b && i4++ <= b) {
        // AND condition returns true (i4 == 5 == b)
        // THEN, i4 increments to 6 before moving on from the if () statement!
        std::cout << "i4: " << i4 << ", b: " << b << std::endl;  // i4 = 6
        std::cout << "hi (:" << std::endl;
    }

    return 0;
}