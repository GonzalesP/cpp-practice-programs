#include <iostream>
int main() {
  int a, b, c;  // data type: int (integer)
  std::cout << "Enter two numbers." << std::endl;
  std::cin >> a >> b;
  // note: in C++, you cannot use variables before declaring them!

  c = a + b;  // assign the value a + b to variable c
  std::cout << "The sum is " << c << std::endl;
  return 0;
}