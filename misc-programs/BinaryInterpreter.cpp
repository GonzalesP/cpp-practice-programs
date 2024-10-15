#include <iostream>
#include <string>  // string methods (e.g., to_string)
#include <cmath>  // exponents

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

// int countDigits(int num) {
//   int totalDigits = 0;
//   while (num > 0) {
//     num /= 10;
//     ++totalDigits;
//   }
//   return totalDigits;
// }



// 11001
int printBinaryAsDecimal(int binaryNum) {
  int decimalSum = 0;
  int power = 0;  // the exponent each digit represents (e.g. 2^0, 2^1, 2^2)

  while (binaryNum > 0) {
    int digitWeight = pow(2.0, power) * (binaryNum % 10);
    decimalSum += digitWeight;

    binaryNum /= 10;
    ++power;
  }

  return decimalSum;
}

int main() {
  // int decimalNumber = 0;
  // std::cout << "Enter a number in Decimal: ";
  // if (!(std::cin >> decimalNumber)) {
  //   std::cout << "Invalid input. Exiting." << std::endl;
  //   return -1;
  // }

  // std::cout << decimalNumber << " in Binary is: "
  //           << printDecimalAsBinary(decimalNumber) << std::endl;

  int binaryNumber = 0;
  std::cout << "Enter a number in Binary: ";
  if (!(std::cin >> binaryNumber)) {
    std::cout << "Invalid input. Exiting." << std::endl;
    return -1;
  }

  std::cout << binaryNumber << " in Decimal is: "
            << printBinaryAsDecimal(binaryNumber) << std::endl;

  return 0;
}