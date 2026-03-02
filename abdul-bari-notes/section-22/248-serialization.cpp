#include <iostream>
#include <fstream>
#include <string>

class Student {
public:
    std::string name;
    int roll;
    std::string branch;

    // to simplify storage/retrieval of objects, you should overload fstream
    // operators via friend functions (makes main's code simpler)
    friend std::ofstream& operator<<(std::ofstream& ofs, Student& s);
    friend std::ifstream& operator>>(std::ifstream& ifs, Student& s);
};

// storing a Student object's info in file (writing)
std::ofstream& operator<<(std::ofstream& ofs, Student& s) {
    ofs << s.name << std::endl;
    ofs << s.roll << std::endl;
    ofs << s.branch << std::endl;
    return ofs;
}
// retrieving info about a Student from a file (reading)
std::ifstream& operator>>(std::ifstream& ifs, Student& s) {
    ifs >> s.name >> s.roll >> s.branch;  // save info in s
    return ifs;
}

int main() {
    // Create new student and save their info in a new file called Student.txt
    Student s1;
    s1.name = "John"; s1.roll = 10; s1.branch = "CS";

    std::ofstream ofs("Student.txt", std::ios::trunc);
    ofs << s1;  // look how simplified this statement looks in main! :D
    ofs.close();


    
    // Retrieve info about a student (technically the same one as above)
    // and print the info onto the screen. Use the same file.
    Student s2;

    std::ifstream ifs("Student.txt");
    ifs >> s2;

    // can technically overload an ostream operator<< for printing Student too
    // (needs a different function from OFstream)
    std::cout << "Name: " << s2.name << std::endl;
    std::cout << "Roll: " << s2.roll << std::endl;
    std::cout << "Branch: " << s2.branch << std::endl;
    ifs.close();

    return 0;
}