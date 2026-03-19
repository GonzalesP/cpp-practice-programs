#include <utility>
#include <iostream>

#define rank(r) (8 - r)
#define col(c) (c - 97)
typedef std::pair<int, int> square;  // row, col

int main() {
    square s (col('d'), rank(7));  // d5
    std::cout << s.second << std::endl;  // row = 1
    std::cout << s.first << std::endl;  // col = 3
    return 0;
}