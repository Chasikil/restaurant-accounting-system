#include "Employee.hpp"
#include <iostream>

// Инициализация статических полей
int Employee::totalEmployees = 0;
double Employee::totalHoursWorked = 0.0;

Employee::Employee(int id, const std::string& name, const std::string& position, double rate)
    : employeeId(id), name(name), position(position), hoursWorked(0.0), hourlyRate(rate)
{
    try {
        if (id <= 0) {
            throw std::invalid_argument("Employee ID must be positive");
        }
        if (rate < 0.0) {
            throw std::invalid_argument("Hourly rate cannot be negative");
        }
        totalEmployees++;
    } catch (const std::exception& e) {
        std::cerr << "Error in Employee constructor: " << e.what() << std::endl;
    }
}

// Конструктор копирования
Employee::Employee(const Employee& other)
    : employeeId(other.employeeId), name(other.name), position(other.position),
      hoursWorked(other.hoursWorked), hourlyRate(other.hourlyRate)
{
    totalEmployees++;
    totalHoursWorked += other.hoursWorked;
}

Employee::~Employee() {
    // При удалении сотрудника вычитаем его часы из общего количества
    totalHoursWorked -= this->hoursWorked;
    totalEmployees--;
}

double Employee::calculateSalary() const {
    return this->hoursWorked * this->hourlyRate;
}

void Employee::addHours(double hours) {
    try {
        if (hours < 0.0) {
            throw std::invalid_argument("Hours cannot be negative");
        }
        double oldHours = this->hoursWorked;
        this->hoursWorked += hours;
        totalHoursWorked += (this->hoursWorked - oldHours);
    } catch (const std::exception& e) {
        std::cerr << "Error in addHours: " << e.what() << std::endl;
    }
}

void Employee::resetHours() {
    totalHoursWorked -= this->hoursWorked;
    this->hoursWorked = 0.0;
}

void Employee::showInfo() const {
    std::cout << "Employee Info:" << std::endl;
    std::cout << "  ID: " << this->employeeId << std::endl;
    std::cout << "  Name: " << this->name << std::endl;
    std::cout << "  Position: " << this->position << std::endl;
    std::cout << "  Hours Worked: " << this->hoursWorked << std::endl;
    std::cout << "  Hourly Rate: " << this->hourlyRate << std::endl;
    std::cout << "  Salary: " << this->calculateSalary() << std::endl;
}

// Оператор присваивания
Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        totalHoursWorked -= this->hoursWorked; // Убираем старые часы
        this->employeeId = other.employeeId;
        this->name = other.name;
        this->position = other.position;
        this->hoursWorked = other.hoursWorked;
        this->hourlyRate = other.hourlyRate;
        totalHoursWorked += this->hoursWorked; // Добавляем новые часы
    }
    return *this;
}

// Оператор сравнения
bool Employee::operator==(const Employee& other) const {
    return this->employeeId == other.employeeId;
}

// Оператор < (сравнение по зарплате)
bool Employee::operator<(const Employee& other) const {
    return this->calculateSalary() < other.calculateSalary();
}


