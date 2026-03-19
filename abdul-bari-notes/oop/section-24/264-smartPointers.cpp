#include <iostream>
#include <memory>  // smart pointers (e.g., std::unique_ptr)

// smart pointers will automatically deallocate the objects that they create
// when they exit the program's scope. so, if a programmer forgets to delete
// an object, the smart pointer will handle deallocation.

// the three main types of smart pointers are
// 1. unique_ptr
// 2. shared_ptr
// 3. weak_ptr (need to study this one more oops)

class Rectangle {
private:
    int length;
    int breadth;
public:
    Rectangle (int l, int b) {
        length = l;
        breadth = b;
    }
    int area() {
        return length * breadth;
    }
};


// unique pointers can create and point to an object in the heap
// AND they will automatically delete the object once they exit scope
void unique() {
    std::unique_ptr<Rectangle> ptr(new Rectangle(10, 5));
    std::cout << "ptr->area(): " << ptr->area() << std::endl;  // 50

    // a unique pointer can ONLY HAVE ONE POINTER at a time.

    // std::unique_ptr<Rectangle> ptr2 = ptr;  or ptr2(ptr);
        // error: this unique_ptr already has ptr! cannot use ptr2 on same obj!
        // "calls implicitly-deleted copy constructor of unique_ptr<Rectangle>"
        // fix: use the move() function

    std::unique_ptr<Rectangle> ptr2 = move(ptr);  // ptr removed, ptr2 replaces
    std::cout << "ptr2->area(): " << ptr2->area() << std::endl;  // 50
        // you cannot use ptr->area() anymore because ptr was deleted (null obj)
}
// ptr and ptr2 are deleted by the end of unique()


// shared pointers allow an object to have multiple pointers. they have a shared
// reference counter, which can be obtained via .use_count()
void shared() {
    std::shared_ptr<Rectangle> ptr(new Rectangle(10, 2));
    std::cout << "ptr->area(): " << ptr->area() << std::endl;

    decltype(ptr) ptr2;
    ptr2 = ptr;  // both ptr AND ptr2 will point to the same Rectangle in heap

    std::cout << "ptr2->area(): " << ptr2->area() << std::endl;
    std::cout << "ptr.use_count(): " << ptr.use_count() << std::endl;  // 2
}
// ptr and ptr2 will be deleted by the end of shared()


int main() {
    std::cout << std::endl;
    std::cout << "unique()" << std::endl;
    unique();  // prints 50 50

    std::cout << std::endl;
    std::cout << "shared()" << std::endl;
    shared();  // prints 20 20

    std::cout << std::endl;
    return 0;
}