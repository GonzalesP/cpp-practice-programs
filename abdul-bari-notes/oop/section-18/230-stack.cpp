#include <iostream>

class StackOverflow : std::exception {};
class StackUnderflow : std::exception {};

class Stack {
private:
    int* stk;  // array acts like stack
    int top = -1;  // keeps track of index of topmost element
    int size;
public:
    Stack(int sz = 1) {
        if (sz < 1)
            throw std::string("Error: stack size cannot be less than one");
        size = sz;
        stk = new int[size];
    }
    void push(int x) {  // add new int to top of stack
        std::cout << "pushing " << x << "..." << std::endl;
        if (top == size - 1)  // if no more room, throw stack overflow
            throw StackOverflow();
        top++;    
        stk[top] = x;
    }
    int pop() {  // get topmost int from stack
        std::cout << "popping..." << std::endl;
        if (top == -1)  // if empty stack, cannot pop anymore -> underflow
            throw StackUnderflow();
        int x = stk[top];
        top--;
        return x;
    }
    ~Stack() {
        std::cout << "Deleting stack..." << std::endl;
        delete[] stk;
    }
};

int main() {
    std::cout << "Stack s1(0)" << std::endl;
    try {
        Stack s1(0);
    }
    catch (std::string e) {
        std::cout << e << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Stack s2(5)" << std::endl;
    Stack s2(5);

    try {
        s2.push(5);
        s2.push(4);
        s2.push(3);
        s2.push(2);
        s2.push(1);
        s2.push(0);  // error: stack overflow (max size is 5)
    }
    catch (StackOverflow e) {
        std::cout << "Error: stack overflow (max size exceeded)" << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << s2.pop() << std::endl;
        std::cout << s2.pop() << std::endl;
        std::cout << s2.pop() << std::endl;
        std::cout << s2.pop() << std::endl;
        std::cout << s2.pop() << std::endl;
        std::cout << s2.pop() << std::endl;  // error: stack underflow
    }
    catch (StackUnderflow e) {
        std::cout << "Error: stack underflow (popping empty stack)"
                  << std::endl;
    }

    std::cout << std::endl;
    return 0;
}