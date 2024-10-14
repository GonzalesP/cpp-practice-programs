#include <iostream>
#include <string>

// Recursively divide a decimal number by 2 and use the remainders
// to calculate its binary form
std::string printDecimalAsBinary(int decNum) {
  if (decNum == 0) {
    return "";
  }
  // Keep dividing by 2 until you reach 0,
  // then print the REMAINDERS in REVERSE order
  return printDecimalAsBinary(decNum / 2) + std::to_string(decNum % 2);
}

int main() {
  int decimalNumber = 0;
  std::cout << "Enter a number in Decimal: ";
  if (!(std::cin >> decimalNumber)) {
    std::cout << "Invalid input. Exiting." << std::endl;
    return -1;
  }

  std::cout << decimalNumber << " in Binary is: "
            << printDecimalAsBinary(decimalNumber) << std::endl;
  return 0;
}