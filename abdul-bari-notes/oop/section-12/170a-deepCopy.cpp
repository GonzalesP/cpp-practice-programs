#include <iostream>

// one thing to look out for is that objects can dynamically allocate memory
// if so, when using a copy constructor, you need to account for
// the dynamic memory! e.g., a copy of a dynamically allocated array should
// be created in the heap for a copied object

class Test
{
    private:
        int size;
        int *p;
    public:
        // non-parameterized/parameterized constructor
        Test(int s = 1)
        {
            setSize(s);
            p = new int[size];
            for (int i = 0; i < size; i++) {
                p[i] = i + 1;  // p[]: 1 2 3 4 5...
            }
        }

        // deep copy constructor
        Test(Test& t)
        {
            size = t.size;
            // p = t.p;  // NO! will point to same array as t
            // if you want t_copy to have its own array, need new memory!

            p = new int[t.size];  // give copy its own array
            for (int i = 0; i < t.size; i++) {
                p[i] = t.p[i];
            }
        }


        // mutator
        void setSize(int val) {
            if (val >= 1)
                size = val;
            else
                size = 1;
        }


        // accessor
        int getSize() {
            return size;
        }


        // Test functions
        void printP() {
            for (int i = 0; i < size; i++) {
                std::cout << p[i] << " ";
            }
            std::cout << std::endl;
        }
        void deleteP() {
            delete []p;
        }
};

int main() {
    Test t1(3);  // will have an array 1 2 3
    Test t2(t1);  // will be same as t1: array 1 2 3

    std::cout << "t1 array: ";
    t1.printP();
    std::cout << "t2 array: ";
    t2.printP();

    t1.deleteP();
    t2.deleteP();

    return 0;
}