#include <iostream>
#include <stdarg.h>  // va_list, va_start, va_arg

// need one named argument (can be used to pass # of variables)
int sum(int n, ...) {
    va_list list;
    va_start(list, n);  // put all variable arguments inside list

    int x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        x = va_arg(list, int);  // get an argument of defined type
        sum += x;
    }
    return sum;
}

int main() {
    std::cout << "sum(3, 10, 20, 30): "
              << sum(3, 10, 20, 30) << std::endl;  // 60
    std::cout << "sum(5, 1, 2, 3, 4, 5): "
              << sum(5, 1, 2, 3, 4, 5) << std::endl;  // 15
    return 0;
}