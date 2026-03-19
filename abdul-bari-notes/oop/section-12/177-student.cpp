#include <iostream>
#include <string>

class Student {
    private:
        int rollNo;
        std::string name;
        int mark1;
        int mark2;
        int mark3;
    
    public:
        // Constructor
        Student(int rollNo, std::string name, int mark1, int mark2, int mark3);

        // Accessors
        int getRollNo();
        std::string getName();
        int getMark1();
        int getMark2();
        int getMark3();

        // Mutators
        void setRollNo(int rollNo);
        void setName(std::string name);
        void setMark1(int mark1);
        void setMark2(int mark2);
        void setMark3(int mark3);

        // Facilitators
        int totalMarks();  // calculate total marks
        char grade();  // generate grade based on avg percentages
        // C: <40, B: 40-<60, A: 60+

        // Destructor
        ~Student();
};

int main() {
    int roll;
    std::string name;
    int m1, m2, m3;  // 3 classes

    std::cout << "Enter student's roll number: ";
    std::cin >> roll;
    std::cin.ignore();

    std::cout << "Enter student's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter the marks for their 3 subjects: ";
    std::cin >> m1 >> m2 >> m3;

    Student s(roll, name, m1, m2, m3);
    std::cout << s.getName() << "'s total marks: " << s.totalMarks() << std::endl;
    std::cout << s.getName() << "'s grade: " << s.grade() << std::endl;
    
    return 0;
}

// Constructor
Student::Student(int rollNo = 0, std::string name = "John Doe",
                 int mark1 = 0, int mark2 = 0, int mark3 = 0) {
    this->setRollNo(rollNo);
    this->setName(name);
    this->setMark1(mark1);
    this->setMark2(mark2);
    this->setMark3(mark3);
}

// Accessors
int Student::getRollNo() {
    return rollNo;
}
std::string Student::getName() {
    return name;
}
int Student::getMark1() {
    return mark1;
}
int Student::getMark2() {
    return mark2;
}
int Student::getMark3() {
    return mark3;
}

// Mutators
void Student::setRollNo(int rollNo) {
    if (rollNo >= 0)
        this->rollNo = rollNo;
    else
        this->rollNo = 0;
}
void Student::setName(std::string name) {
    this->name = name;
}
void Student::setMark1(int mark1) {
    if (mark1 >= 0)
        this->mark1 = mark1;
    else
        this->mark1 = 0;
}
void Student::setMark2(int mark2) {
    if (mark1 >= 0)
        this->mark2 = mark2;
    else
        this->mark2 = 0;
}
void Student::setMark3(int mark3) {
    if (mark1 >= 0)
        this->mark3 = mark3;
    else
        this->mark3 = 0;
}

// Facilitators
int Student::totalMarks() {
    return mark1 + mark2 + mark3;
}
char Student::grade() {
    float avg = (float) this->totalMarks() / 3.0f;

    // grade>=60: A
    // 40<=grade<60: B
    // grade<40: C
    if (avg >= 60)
        return 'A';
    else if (avg >= 40 && avg < 60)
        return 'B';
    else
        return 'C';
}

// Destructor
Student::~Student() {
    std::cout << "Deleting Student" << std::endl;
}