#include <iostream>

// single line comment
/* paired comment */

/*
 * multi-line comment
 * hi
 */

// /*
//  * use single line comments for large blocks of code
//  */
// std::cout << "lol" << std::endl;

int main() {
  std::cout << "/*";
  std::cout << "*/";

  // pay close attention to placement of "" !
  std::cout << /* "*/" /* "/*" */;

  // 1.7 & 1.8 - skip
  
  return 0;
}