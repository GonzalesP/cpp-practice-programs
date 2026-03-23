#include <iostream>

// arrays are ALWAYS passed by address (never by value)
// the formal parameter acts like a pointer (to the base address of the array)
void fun1(int A[], int n) {
    // std::cout << sizeof(A) / sizeof(int) << std::endl;
        // sizeof(A) returns size of int *, not the actual array size!
        // so, fun() does not know how many elements are in main's A[]
    
    // for (int a : A)
        // cout << a << endl;
        // does not work - A is a pointer to an array, not an actual array!
        // cannot use for each loop to access individual int elements

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// alternatively, you can use an int* for the parameter
// pointers can point to both arrays AND individual variables
// however, [] can ONLY point to arrays
void fun2(int* A, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";  // translates to *(A+0)
        std::cout << *(A+i) << " " << std::endl;
    }
    std::cout << std::endl;

    // A[0] = 15;  // will affect actual parameters (A[] in main)
}

// functions can also create and return arrays
// some compilers give an error when returning type int[], so use int *
int* fun3(int size) {
    int* p;
    p = new int[size];

    // for (int x : p)
    // not allowed, p is a pointer to array, not an actual array (no .begin())

    for (int i = 0; i < size; i++)
        p[i] = i + 1;  // 1 2 3 4 ...
    
    return p;
}

int main() {
    int A[] = {2,4,6,8,10};
    int n = 5;    

    std::cout << "main A[]:" << std::endl;
    for (int x : A)
        std::cout << x << " ";
    std::cout << std::endl << "size of main A[]: ";
    std::cout << sizeof(A) / sizeof(int) << std::endl;  // 5

    std::cout << "fun1(A, 5)" << std::endl;
    fun1(A, 5);

    std::cout << "fun2(A, 5)" << std::endl;
    fun2(A, 5);

    int *ptr, sz = 5;

    std::cout << "fun3(5)" << std::endl;
    ptr = fun3(sz);

    for (int i = 0; i < sz; i++)
        std::cout << ptr[i] << " ";
    std::cout << std::endl;

    delete[] ptr;
    
    return 0;
}