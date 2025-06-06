#include <iostream>

enum day {sun, mon, tue, wed, thu, fri, sat};  // default: sun = 0, mon = 1, ...
enum dept {cs = 1, it = 2, ece = 5, eng};

typedef int marks;  // giving the "int" data type a specific name
typedef int rollno;  // "user defined" variables

int main() {
    day day1 = sun;

    if (day1 == 0) {
        std::cout << "It's sunday!" << std::endl;
    }

    if (day1 == sun) {
        std::cout << "It's sunday still!" << std::endl;
    }

    std::cout << day1 << std::endl;  // prints 0

    
    dept dep1 = eng;  // dep1 = 6 (default behavior is +1 each subsequent enum)

    std::cout << dep1 << std::endl;
    std::cout << cs << " " << it << " " << ece << " " << eng;


    marks m1 = 90, m2 = 85, m3 = 87;
    rollno r1 = 111, r2 = 132, r3 = 143;

    ++m1;
    --r1;

    return 0;
}