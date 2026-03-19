#include <iostream>
#include <string>

class Employee {
private:
    int employeeID;
    std::string name;

public:
    Employee(int id, std::string name) {
        setEmployeeID(id);
        setName(name);
    }
    void setEmployeeID(int id) {
        if (id > 0)
            employeeID = id;
        else
            employeeID = 1;
    }
    void setName(std::string n) {
        name = n;
    }
    int getEmployeeID() { return employeeID; }
    std::string getName() { return name; }
};

class fullTimeEmployee : public Employee {
private:
    int salary;

public:
    fullTimeEmployee(int id, std::string name, int s) : Employee(id, name) {
        setSalary(s);
    }
    void setSalary(int s) {
        if (s >= 0)
            salary = s;
        else
            salary = 0;
    }
    int getSalary() { return salary; }
};

class partTimeEmployee : public Employee {
private:
    int dailyWage;

public:
    partTimeEmployee(int id, std::string name, int d) : Employee(id, name) {
        setDailyWage(d);
    }
    void setDailyWage(int d) {
        if (d >= 0)
            dailyWage = d;
        else
            dailyWage = 0;
    }
    int getDailyWage() { return dailyWage; }
};

int main() {
    partTimeEmployee p1(123, "John Doe", 300);
    fullTimeEmployee p2(456, "Jane Doe", 5000);

    std::cout << "Daily wage of " << p1.getName() << " is " << p1.getDailyWage()
              << std::endl;
    std::cout << "Salary of " << p2.getName() << " is " << p2.getSalary()
              << std::endl;
              
    return 0;
}