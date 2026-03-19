#include <iostream>

// templates can be used to generalize the logic of a program
// (i.e., work with any compatible types)

// TEMPLATE FUNCTIONS

template <class T>
T maximum(T x, T y) {
    return x > y ? x : y;
}
// T can be substituted with comparable data types
// (e.g., int, double, char, etc.)
// custom classes can also be used if they have overloaded functions
// for comparison operators in this case (operator>)

// NOTE: THE EFFECT OF TEMPLATE ENDS WHEN A FUNCTION/CLASS ENDS!
// To define another template function, you need to write another
// template declaration (e.g., template <class T>)

// templates can use multiple types if needed
template <class T, class R>
void add (T x, R y) {
    std::cout << x + y << std::endl;
}
// e.g., add(10, 12.9)  - T: int, R: double



// TEMPLATE CLASSES

// template classes can be used to make classes applicable to more data types
// for instance, the Stack class below can be used to create a stack of
// different data types (e.g., a stack of integers, a stack of strings, etc.)

template <class T>
class Stack {
private:
    T* stk;  // ptr for array storing T type elements
    int top;  // top ptr (index) - topmost element in stack
    int size;  // size of stack
public:
    Stack(int sz = 1) {
        if (sz > 0)
            size = sz;
        else
            size = 1;
        top = -1;
        stk = new T[size];  // create an array of T's of size sz
    }
    ~Stack() {
        delete[] stk;
    }

    void push(T x);
    T pop();
};

// when implementing a function of a template class, you MUST include a template
// parameter in the scope operator
// for instance, since Stack uses a template T in its members, you must use
// the scope operator Stack<T>::  - Stack:: will not work!
template <class T>
void Stack<T>::push(T x) {
    if (top == size - 1)
        std::cout << "Stack is full" << std::endl;
    else {
        top++;
        stk[top] = x;
    }
}

template <class T>
T Stack<T>::pop() {
    T x;
    if (top == -1)
        std::cout << "Stack is empty" << std::endl;
    else {
        x = stk[top];
        top--;
        return x;
    }
}

int main() {
    // when creating an object using a template class, you MUST give a data type
    // for the template parameter (i.e., Stack<T> must be given a data type
    // in place of the template class T)
    Stack<int> s1(10);  // stack of ints size 10
    s1.push(10);
    s1.push(23);
    s1.push(33);

    Stack<double> s2(5);  // stack of doubles size 5
    s2.push(10.1);
    s2.push(23.2);
    s2.push(33.3);

    return 0;
}