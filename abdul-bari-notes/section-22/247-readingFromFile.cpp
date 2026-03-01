#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile;
    infile.open("My.txt");  // std::ifstream infile("My.txt");
    
    if (!infile.is_open()) {  // if file is NOT open
        std::cout << "Error: file could not be open." << std::endl;
        return 0;  // exit main
    }

    std::string name;
    int roll;
    std::string branch;

    // read contents of My.txt, save into name, roll, and branch
    infile >> name >> roll >> branch;

    // if end of file reached
    if (infile.eof())
        std::cout << "End of file reached" << std::endl;

    std::cout << "Name: " << name << std::endl;
    std::cout << "Roll: " << roll << std::endl;
    std::cout << "Branch: " << branch << std::endl;

    infile.close();  // close the ifstream

    return 0;
}