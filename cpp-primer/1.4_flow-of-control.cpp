#include <iostream>
int main() {
  // Write a program that uses a while to sum the numbers from 50 to 100
  int sum = 0, val = 50;
  while (val <= 100) {
    sum += val;
    ++val;
  }
  std::cout << "The sum of the numbers from 50 to 100 is " << sum << std::endl;

  // Write a program that uses a while to print the numbers
  // from ten down to zero
  val = 10;
  while (val >= 0) {
    std::cout << val << std::endl;
    --val;
  }

  // Write a program that prints each number in the range of two input integers
  int a = 0, b = 0;
  std::cout << "Give two integers, and I will print the numbers "
            << "within their range (inclusive). Smaller one first!"
            << std::endl;
  std::cin >> a >> b;

  while (a <= b) {
    std::cout << a << std::endl;
    ++a;
  }
}