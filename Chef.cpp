#include "Chef.hpp"
#include <iostream>

Chef::Chef(int id, const std::string& name, double rate, const std::string& specialty, int dishesPrepared)
    : Employee(id, name, "Chef", rate), dishesPrepared(dishesPrepared), specialty(specialty)
{
    // Вызов конструктора базового класса Employee в списке инициализации
}

Chef::Chef(const Chef& other)
    : Employee(other), dishesPrepared(other.dishesPrepared), specialty(other.specialty)
{
    // Вызов конструктора копирования базового класса
}

void Chef::showInfo() const {
    // Переопределение метода с вызовом базового метода
    Employee::showInfo(); // Вызов метода базового класса
    std::cout << "  Specialty: " << this->specialty << std::endl;
    std::cout << "  Dishes Prepared: " << this->dishesPrepared << std::endl;
}

double Chef::calculateSalary() const {
    // Переопределение без вызова базового метода
    // Повара получают базовую зарплату плюс бонус за блюда
    double baseSalary = this->hoursWorked * this->hourlyRate;
    double bonus = this->dishesPrepared * 10.0; // Бонус 10 за блюдо
    return baseSalary + bonus;
}

void Chef::prepareDish(const std::string& dishName) {
    this->dishesPrepared++;
}

Chef& Chef::operator=(const Chef& other) {
    if (this != &other) {
        Employee::operator=(other); // Вызов оператора базового класса
        this->dishesPrepared = other.dishesPrepared;
        this->specialty = other.specialty;
    }
    return *this;
}

Chef& Chef::operator=(const Employee& other) {
    Employee::operator=(other); // Присваивание только базовой части
    // Поля, специфичные для Chef, остаются неизменными
    return *this;
}

