#include <iostream>

// returning by address is useful for functions that deal with heap memory
// this function dynamically allocates an int array and returns its address
// to the pointer declared in main
int *fun() {
    int *p = new int[5];  // create an array with the values 1 2 3 4 5
    for (int i = 0; i < 5; i++)
        p[i] = i + 1;
    return p;
}
// note: the p pointer variable disappears, but the memory (and data) that was
// allocated by fun() in the heap does not! furthermore, the address
// of the int array (stored in p) is returned to main, which means
// main gains access to the same array dynamically allocated by fun()!
    // int *q will point to the same memory given by int *p

// lastly, you shouldn't delete []p if it is going to be used!
// instead, let main() decide when to delete the dynamically allocated array


// returning by reference will return a reference to an outside variable
// note: variables created within a function's scope will be deleted once
// the function ends. HOWEVER, if a variable was created outside of its scope,
// it may still persist after the function ends!
int & ref(int &a) {
    // int x = 10;
    // return x;  // cannot do this because x will delete after ref() ends

    return a;  // a is a reference to an outside variable, so it will persist!
}
// a is already a reference, so ref(a) will just return a reference to a itself!
// i.e., calling ref(x) in main returns a reference to x itself
// (ref(x) is the same "variable" as x!.. trippy)

int main () {
    // fun dynamically allocates an array and gives its address to q
    int *q = fun();
    
    for (int i = 0; i < 5; i++)
        std::cout << q[i] << std::endl;  // 1 2 3 4 5
    
    delete []q;


    // ref returns a reference to the same variable it is given
    int x = 10;
    std::cout << "x: " << x << std::endl;  // 10
    std::cout << "ref(x): " << ref(x) << std::endl;  // also 10
    // ref(x) will end up referencing x itself, so ref(x) will be
    // another alias for x

    std::cout << "*ref(x) += 10...*" << std::endl;
    ref(x) += 10;  // equivalent to x += 10;
    std::cout << "x: " << x << std::endl;  // 20
    std::cout << "ref(x): " << ref(x) << std::endl;  // 20

    return 0;
}