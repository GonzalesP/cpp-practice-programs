#include <iostream>

#include <vector>  // an array that automatically resizes itself
#include <list>  // doublely linked list
#include <forward_list>  // singlely linked list
#include <set>

int main() {
    std::vector<int> v = {2, 4, 6, 8, 10};
    v.push_back(20);
    v.push_back(30);  // 2 4 6 8 10 20 30

    v.pop_back();  // 2 4 6 8 10 20

    std::cout << "printing v using for each loop" << std::endl;
    for (int x : v)
        std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "printing v using iterator" << std::endl;
    std::vector<int>::iterator itrVec;
    for (itrVec = v.begin(); itrVec != v.end(); itrVec++)
        std::cout << *itrVec << " ";
    std::cout << std::endl;


    std::list<int> li = {2, 4, 6, 8, 10};
    li.push_back(20);
    li.push_back(30);  // 2 4 6 8 10 20 30

    li.pop_back();  // 2 4 6 8 10 20

    std::cout << "printing li using for each loop" << std::endl;
    for (int x : li)
        std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "printing li using iterator" << std::endl;
    std::list<int>::iterator itrLi;
    for (itrLi = li.begin(); itrLi != li.end(); itrLi++)
        std::cout << *itrLi << " ";
    std::cout << std::endl;


    std::forward_list<int> fli = {2, 4, 6, 8, 10};
    fli.push_front(20);  // forward_list doesn't have push_back()
    fli.push_front(30);  // 30 20 2 4 6 8 10

    fli.pop_front();  // 20 2 4 6 8 10

    std::cout << "printing fli using for each loop" << std::endl;
    for (int x : fli)
        std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "printing fli using iterator" << std::endl;
    std::forward_list<int>::iterator itrFli;
    for (itrFli = fli.begin(); itrFli != fli.end(); itrFli++)
        std::cout << *itrFli << " ";
    std::cout << std::endl;


    std::set<int> s = {2, 4, 6, 8, 10, 10, 10};  // 2 4 6 8 10
    s.insert(20);  // no push_back or push_front
    s.insert(30);  // you also cannot modify set elements (e.g., no ++)

    // sets only save unique elements (no duplicates)

    std::cout << "printing s using for each loop" << std::endl;
    for (int x : s)
        std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "printing s using iterator" << std::endl;
    std::set<int>::iterator itrSet;
    for (itrSet = s.begin(); itrSet != s.end(); itrSet++)
        std::cout << *itrSet << " ";
    std::cout << std::endl;

    return 0;
}