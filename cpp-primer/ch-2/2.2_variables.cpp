#include <iostream>



int main() {
  //2.2.1 - Variable Definitions
  // Initialization
  int a = 0, b, c = 0;

  // initialization occurs from left to right
  double price = 109.99, discount = price * 0.16;  // ALLOWED
  // double salary = wage = 9999.99;  // NOT ALLOWED - wage undefined!

   // in order to use std::string, you need to include a library that uses it!
   // for example, it could be <string> or <iostream>
  std::string hi("hello");
  
  // NOTE: initialization IS NOT the same operation as ASSIGNMENT!!
  // Initialization - happens when a variable is given a value when created
  // it so happens that initialization in C++ can be pretty complicated:

  int i1 = 0;
  int i2 = {0};  // list initialization uses curly braces
  int i3{0};
  int i4(0);

  // NARROWING CONVERSION:
  // list-initialization is not allowed for variables of BUILT-IN type if
  // the initializer might lead to the loss of information. for example:

  long double pi = 3.1415926536;
  // not allowed (or warning): int a{pi}, b = {pi};
  // allowed: int c(pi), d = pi;


  // Default Initialization
  // If variables are defined without an initializer, it is default initialized.
  
  // Objects of built-in type can either be: a) zero when defined OUTSIDE of
  // any function body or b) UNINITIALIZED, meaning their value is UNDEFINED.
  // Errors occur when accessing the value of a variable that is undefined.

  // Objects of CLASS type that are not explicitly initialized will have a value
  // that is DEFINED by the class (which iirc is the constructor() function)

  return 0;
}