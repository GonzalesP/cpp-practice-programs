#include <iostream>

int main() {
  // 2.1.1 - Arithmetic Types
  // "types define the data and operations a variable can hold/perform"

  bool b = true;  // true or false

  char c = 'a';  // 8+ bits, same size as a single machine byte
  wchar_t wc = 'a';  // 16+ bits - wide character, largest extended char set
  char16_t  c16 = 'a';  // 16+ bits - unicode characters (along with char32_t)

  short s = 1;  // 16+ bits
  int in = 0;  // 16+ bits
  long lo1 = 32;  // 32+ bits
  long long lo2 = 64;  // 64+ bits

  // hierarchy (byte size): short <= int <= long <= long long

  // most computers deal with memory as chunks of bits (sizes are powers of 2)
  // byte - smallest chunk of addressable memory (typically 8 bits)
  // word - basic unit of storage (typically 4 or 8 bytes)
  //  C++ - a byte has at least as many bits needed to hold a character from the
  //        machine's basic char set
  // most computers associate a memory address (number) with each byte in memory

  float f = 6;  // 6 significant digits (typically one word, 32 bits)
  double d1 = 10;  // 10 sig. dig. (two words, 64 bits)
  long double d2 = 10;  // 10 sig. dig. (three or four words, 96/128 bits)

  // signed: negative or positive numbers (and zero)
  // unsigned: 0 and above
  // int, short, long, and long long are all SIGNED. use 'unsigned' for others

  unsigned long ul = 23;


  // RULES OF THUMB
  // only use unsigned when you know the values cannot be negative
  // int for integer math (short usually too small, long usually same as int)
  // if values LARGER than MINIMUM guaranteed size int (16 bit), use long long

  // don't use char or bool in arithmetic. if you need a tiny int,
  // specifically use signed char or unsigned char (default varies in machines)

  // use DOUBLE for floating-point computations (float usually too small,
  // long double is usually unnecessarily too precise - run-time cost)



  // 2.1.2 - Type Conversions
  // When assigning on arithmetic type to another, what happeneds depends
  // on the range of the values that the types permit

  // bool: 0 is false, any other value is true
  // bool b = 42;  // b is true
  
  // assigning a bool to an int is 0 or 1 depending on false or true
  // int i = b;  // 1

  // float-point values are truncated for integers, and .0 is added for fraction
  // i = 3.14;  // 3
  // double pi = i;  // 3.0

  // NOTE: precision may be lost if the integer has more bits than the
  // floating-point can accomodate


  // Out of range values for UNSIGNED types will use modulo with their range
  // e.g. 8 bit unsigned char = -1 will be -1 % 256 -> 255

  // Out of range values for SIGNED types will be UNDEFINED
  // "program might APPEAR to work, might CRASH, or produce GARBAGE values"

  // Avoid UNDEFINED and IMPLEMENTATION-DEFINED behavior
  // undefined: may seem to work on one compiler but not others
  // implementation: NONPORTABLE (e.g. assuming size of int is fixed - it's not)


  // be careful of code that implicitly uses type conversion for arithmetic
  // e.g. an int may be converted to an unsigned type before adding
  // if the int is negative, it will be = modulo # of bits (aka "WRAP AROUND")

  // REGARDLESS of whether one or both operands are unsigned: "We must make sure
  // that SUBTRACTION will NOT result in negative, otherwise WRAPAROUND occurs

  // e.g. for (int i = 10; i >= 0; --i) VS. for (unsigned u = 10; u >= 0; u--)
  // "using unsigned means that the loop WILL NEVER TERMINATE!!" (wraparound)

  // TL;DR: signed values are automatically converted to unsigned, so avoid
  // mixing them together

  // e.g. a * b, where a = -1 and b = 1.
  // if both are ints, you get -1. if one is unsigned, it is -1 % # of bits

  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl;
  std::cout << u - u2 << std::endl;
  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl;
  std::cout << i - i2 << std::endl;
  std::cout << i - u << std::endl;
  std::cout << u - i << std::endl;



  // 2.1.3 - Literals
  int decimal = 123;
  int octal = 024;
  int hexadecimal = 0x14;  // 0X okay too

  double float1 = 3.14159;  // float literals are indicated with a decimal point
  double float2 = 3.14159E0;  // or scientific notation (E or e)
  double float3 = 0.;
  double float4 = 0e0;
  double float5 = .001;

  std::cout << float1 << float2 << float3 << float4 << float5 << std::endl;

  char charlit = 'a';  // character literal
  std::string strlit = "a";  // string literal (different!)
  // NOTE: a string literal is an ARRAY of CONSTANT chars
  // also, compilers append a null character to every string literal: '\0'
  // 'a' is one single character and "a" is an array of two characters: 'a' '\0'

  // two string literals can be concatenated into a single literal if there is
  // a whitespace between them
  std::cout << "this is the first line, "
               "and this is the second line" << std::endl;

  // escape sequences are characters that have no visible image or have
  // a special meaning in the language (e.g. "")
  // you need to use an escape sequence to use them in a string/char:
  std::cout << "newline \n aaa" << std::endl;
  std::cout << "horizontal tab \t aaa" << std::endl;
  std::cout << "alert (bell) \a aaa" << std::endl;
  std::cout << "vertical tab \v aaa" << std::endl;
  std::cout << "backspace \b aaa" << std::endl;
  std::cout << "double quote \"aaa\"" << std::endl;
  std::cout << "backslash \\ aaa" << std::endl;
  std::cout << "question mark \? aaa" << std::endl;
  std::cout << "single quote \'aaa\'" << std::endl;
  std::cout << "casrriage return \r aaa" << std::endl;
  std::cout << "formfeed \f aaa" << std::endl;

  // generalized escape sequences
  std::cout << "\x4d" << std::endl;  // hexadecimal: \x[1+ hex digits]
  std::cout << "\114" << std::endl;  // octal:  \[1, 2, or 3 octal digits]
  // "excess characters are separate for octal (not included in escape seq)"
  std::cout << "\1234" << std::endl;  // \123 and 4
  
  // specifying the type of a literal

  // boolean and pointer literals
  bool bliteral = true;  // or false
  bool* blptr = nullptr;  // nullptr is a pointer literal
  blptr = &bliteral;

  return 0;
}