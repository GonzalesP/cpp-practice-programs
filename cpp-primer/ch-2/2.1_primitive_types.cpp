int main() {
  // 2.1.1 - Arithmetic Types
  // "types define the data and operations a variable can hold/perform"

  bool b = true;  // true or false

  char c = 'a';  // 8+ bits, same size as a single machine byte
  wchar_t wc = 'a';  // 16+ bits - wide character, largest extended char set
  char16_t  c16 = 'a';  // 16+ bits - unicode characters (along with char32_t)

  short s = 1;  // 16+ bits
  int i = 0;  // 16+ bits
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

  return 0;
}