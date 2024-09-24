#include <iostream>
int main() {
  // 1.9 - Write a program that uses a while to sum the numbers from 50 to 100
  // int sum = 0, val = 50;
  // while (val <= 100) {
  //   sum += val;
  //   ++val;
  // }
  // std::cout << "The sum of the numbers from 50 to 100 is " << sum << std::endl;

  // 1.10 - Write a program that uses a while to print the numbers
  // from ten down to zero
  // int val = 10;
  // while (val >= 0) {
  //   std::cout << val << std::endl;
  //   --val;
  // }

  // 1.11 - Write a program that prints each number in the range of
  // two input integers
  // int a = 0, b = 0;
  // std::cout << "Give two integers, and I will print the numbers "
  //           << "within their range (inclusive). Smaller one first!"
  //           << std::endl;
  // std::cin >> a >> b;

  // while (a <= b) {
  //   std::cout << a << std::endl;
  //   ++a;
  // }

  // 1.12 - skip
  // 1.13 - Rewrite 1.9 - 1.11 using for loops
  // int sum = 0;
  // for (int val = 50; val <= 100; ++val) {
  //   sum += val;
  // }
  // std::cout << "The sum of the numbers from 50 to 100 is " << sum << std::endl;


  // for (int val = 10; val >= 0; --val) {  // don't use ++! be careful!
  //   std::cout << val << std::endl;
  // }


  // int c = 0, d = 0;
  // std::cout << "Give two integers, and I will print the numbers "
  //           << "within their range (inclusive). Smaller one first!"
  //           << std::endl;
  // std::cin >> c >> d;

  // for (int val = c; c <= d; ++c) {
  //   std::cout << c << std::endl;
  // }

  // 1.14 1.15 - skip



  // summing a set of numbers with an unknown set size
  int sum = 0, value = 0;

  // the condition depends on std::cin, which returns true as long as
  // the end-of-file or invalid input is not read
  // EOF is usually CTRL+Z on windows and CTRL+D on Mac/UNIX
  while (std::cin >> value)
    sum += value;
  
  std::cout << "Sum is: " << sum << std::endl;
  return 0;
}