#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include <stdexcept>

class Employee {
private:
    int employeeId;
    std::string name;
    std::string position;
    double hoursWorked;
    double hourlyRate;
    
    static int totalEmployees; // Статическое поле - количество сотрудников
    static double totalHoursWorked; // Статическое поле - общее количество отработанных часов

public:
    // Конструкторы
    Employee(int id, const std::string& name, const std::string& position, double rate);
    Employee(const Employee& other); // Конструктор копирования
    
    // Деструктор
    ~Employee();

    // Методы
    double calculateSalary() const;
    void addHours(double hours);
    void resetHours();
    void showInfo() const;
    
    // Геттеры с использованием this
    std::string getName() const { return this->name; }
    double getHoursWorked() const { return this->hoursWorked; }
    double getHourlyRate() const { return this->hourlyRate; }
    
    // Статические методы
    static int getTotalEmployees() { return totalEmployees; }
    static double getTotalHoursWorked() { return totalHoursWorked; }
    static double getAverageHours() { 
        return totalEmployees > 0 ? totalHoursWorked / totalEmployees : 0.0; 
    }
    
    // Перегрузка операторов
    Employee& operator=(const Employee& other);
    bool operator==(const Employee& other) const;
    bool operator<(const Employee& other) const; // Сравнение по зарплате
};

#endif // EMPLOYEE_HPP


