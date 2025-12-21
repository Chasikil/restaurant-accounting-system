#ifndef CHEF_HPP
#define CHEF_HPP

#include "Employee.hpp"
#include <string>

// Производный класс Chef (Повар) от Employee
class Chef : public Employee {
private:
    int dishesPrepared; // Количество приготовленных блюд
    std::string specialty; // Специализация (например, "Italian", "French")

public:
    // Конструктор с вызовом конструктора базового класса
    Chef(int id, const std::string& name, double rate, const std::string& specialty, int dishesPrepared = 0);
    
    // Конструктор копирования
    Chef(const Chef& other);
    
    // Переопределение виртуальных методов
    virtual void showInfo() const override; // Переопределение с вызовом базового метода
    virtual double calculateSalary() const override; // Переопределение без вызова базового метода
    virtual std::string getEmployeeType() const override { return "Chef"; }
    
    // Новые методы
    void prepareDish(const std::string& dishName);
    int getDishesPrepared() const { return this->dishesPrepared; }
    std::string getSpecialty() const { return this->specialty; }
    
    // Оператор присваивания
    Chef& operator=(const Chef& other);
    Chef& operator=(const Employee& other); // Присваивание объектов базового класса
};

#endif // CHEF_HPP

