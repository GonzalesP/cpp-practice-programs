#include <iostream>
int main() {
  // 1.3 - print "Hello, World" on the standard input
  std::cout << "Hello, World!" << std::endl;

  // 1.4 - get two numbers and print their sum and product
  int v1 = 0, v2 = 0;
  std::cout << "Enter two numbers:" << std::endl;
  std::cin >> v1 >> v2;

  std::cout << "The sum of " << v1 << " and " << v2 << " is "
            << v1 + v2 << std::endl;
  std::cout << "The product of " << v1 << " and " << v2 << " is "
            << v1 * v2 << std::endl;

  // 1.5 & 1.6 - skip

  return 0;
}