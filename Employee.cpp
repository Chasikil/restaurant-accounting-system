#include "Employee.hpp"
#include <iostream>

Employee::Employee(int id, const std::string& name, const std::string& position, double rate)
    : employeeId(id), name(name), position(position), hoursWorked(0.0), hourlyRate(rate)
{
}

double Employee::calculateSalary() const {
    return hoursWorked * hourlyRate;
}

void Employee::addHours(double hours) {
    if (hours > 0.0) {
        hoursWorked += hours;
    }
}

void Employee::resetHours() {
    hoursWorked = 0.0;
}

void Employee::showInfo() const {
    std::cout << "Employee Info:" << std::endl;
    std::cout << "  ID: " << employeeId << std::endl;
    std::cout << "  Name: " << name << std::endl;
    std::cout << "  Position: " << position << std::endl;
    std::cout << "  Hours Worked: " << hoursWorked << std::endl;
    std::cout << "  Hourly Rate: " << hourlyRate << std::endl;
    std::cout << "  Salary: " << calculateSalary() << std::endl;
}


