#include <iostream>
#include <string>

// this class represents an Innova car. They all share the same price, so price
// is saved as a static variable to make it shared among all Innova objects.
// it is also globally accessible through the static function getPrice.
class Innova {
public:
    static int price;
    static int getPrice() {
        return price;
    }
};
int Innova::price = 20;

// this class represents students who are admitted into some class. each student
// has a roll no, which they are assigned based on the order that they are
// admitted in (i.e., the total number of students at the time they join).
class Student {
public:
    int rollNo;
    std::string name;
    static int addNo;
    // admission number: total number of students admitted. it is also used to
    // assign students their roll no based on the order in which
    // they are admitted. for example, the first student will be assigned
    // roll no 1 because the total number of students admitted at the time
    // will be 1.

    Student(std::string n) {
        addNo++;
        rollNo = addNo;
        name = n;
    }
    void display() {
        std::cout << "Name: " << name << ", ";
        std::cout << "Roll no.: " << rollNo << std::endl;
    }
};
int Student::addNo = 0;

int main() {
    // all Innova objects share the same price, and all of these
    // print statements will print the same price (20)
    Innova i1, i2, i3;
    std::cout << i1.price << std::endl;
    std::cout << i2.price << std::endl;
    std::cout << i3.getPrice() << std::endl;
    std::cout << Innova::price << std::endl;
    std::cout << Innova::getPrice() << std::endl;

    // Everytime a student is created, the admission count goes up, and the
    // student is assigned that total as their roll number
    // For example, the first student will be assigned roll no. 1,
    // because the total number of admitted students becomes 1.
    // The second student will be assigned roll no. 2, and so on.
    Student s1("John");  // addNo becomes 1 -> s1 is assigned rollNo 1
    Student s2("Ravi");  // addNo becomes 2 -> s2 is assigned rollNo 2
    Student s3("Khan");
    Student s4("Jane");
    Student s5("Sean");
    Student s6("Mike");

    s1.display();  // Name: John, Roll no.: 1
    s3.display();  // Name: Khan, Roll no.: 3
    std::cout << "Number of admissions: " << Student::addNo << std::endl;  // 6

    return 0;
}