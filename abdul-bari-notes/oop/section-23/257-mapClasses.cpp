#include <iostream>
#include <map>
#include <string>

typedef int rollNo;
typedef std::string studentName;

int main() {
    std::map<rollNo, studentName> m;  // stores <key, value> pairs
    m.insert(std::pair<rollNo, studentName>(1, "john"));
    m.insert(std::pair<rollNo, studentName>(2, "ravi"));
    m.insert(std::pair<rollNo, studentName>(3, "khan"));

    // print all contents of m
    std::map<rollNo, studentName>::iterator itr1;
    for (itr1 = m.begin(); itr1 != m.end(); itr1++)
        std::cout << "roll no.: " << itr1->first << ", " << "name: "
                  << itr1->second << std::endl;

    // map.find() returns an iterator position
    std::map<rollNo, studentName>::iterator itr2;
    itr2 = m.find(2);  // will point to <2, "ravi">
    std::cout << "m.find(2):" << std::endl;
    std::cout << itr2->first << " " << itr2->second << std::endl;

    return 0;
}