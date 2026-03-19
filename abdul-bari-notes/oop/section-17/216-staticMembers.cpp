#include <iostream>

// static members belong to a class a whole, not to an object alone.
// if they are public, they become globally accessible, but they must be
// accessed through the class's scope (e.g., Test::) or through an object
// instance of said class (e.g., Test t1;  t1.staticMember ...)

class Test {
public:
    int a;
    static int count;  // common data member shared by all Test objects
    // essentially belongs to the class, not a single object alone
        // count keeps track of how many Test objects have been constructed

    Test() {
        a = 10;
        count++;  // everytime a Test obj is constructed, increase counter
    }
    static int getCount() {
        // a++;  - error: static functions cannot use non-static members
        return count;
    }
};
int Test::count = 0;  // static data must be initialized outside of the class
// they act like global variables, but within the local scope of the class


int main() {
    // checking on the total number of Test objects created
    std::cout << "Test::count: " << Test::count << std::endl;  // 0
    std::cout << "*creating Test t1 and Test t2*" << std::endl;
    Test t1, t2;
    std::cout << "Test::count: " << Test::count << std::endl;  // 2
    std::cout << "t1.count: " << t1.count << std::endl;  // 2
    std::cout << "t2.count: " << t2.count << std::endl;  // 2
        // all Test objects share the same instance of count (bc it is static)

    // since count is public (and static), it is globally accessible
    std::cout << "*t1.count = 25*" << std::endl;
    t1.count = 25;
    std::cout << "t2.getCount(): " << t2.getCount() << std::endl;  // 25
    std::cout << "Test::getCount(): " << Test::getCount() << std::endl;  // 25

    return 0;
}