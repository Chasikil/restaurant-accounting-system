#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee {
private:
    int employeeId;
    std::string name;
    std::string position;
    double hoursWorked;
    double hourlyRate;

public:
    Employee(int id, const std::string& name, const std::string& position, double rate);

    double calculateSalary() const;
    void addHours(double hours);
    void resetHours();
    void showInfo() const;
};

#endif // EMPLOYEE_HPP


