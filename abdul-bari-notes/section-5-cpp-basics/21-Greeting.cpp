#include <iostream>
#include <string>

int main() {
  std::string name;  // string is a data type for words
  std::cout << "May I know your name?" << std::endl;
  // std::cin >> name;
  std::getline(std::cin, name);  // read all words until ENTER is pressed

  std::cout << "Welcome Mr. / Ms. " << name << std::endl;
  return 0;
}

// Problem: if you give multiple words for cin, only the first name
// will be taken as input (e.g., Ravi Kumar -> Ravi)

// Solution: use std::getline() instead, which is from 'string.h'