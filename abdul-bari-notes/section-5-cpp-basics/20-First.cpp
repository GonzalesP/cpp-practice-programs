#include <iostream>
// sometimes, compilers will require you to add .h to header files

// using namespace std;  // built-in things of library are grouped under std
// doing this means you won't have to use std::, however it is better practice
// to avoid using namespace, especially if you're only using one thing (cout)

// int: return type
int main() {
  std::cout << "Hello, world" << std::endl;
  return 0;
}

// << - insertion operator
// :: - scope operator