#ifndef WAITER_HPP
#define WAITER_HPP

#include "Employee.hpp"
#include "ServingPolicy.hpp"
#include <memory>
#include <string>

// Производный класс Waiter (Официант) от Employee
class Waiter : public Employee {
private:
    int tablesServed; // Количество обслуженных столов
    double tips; // Чаевые
    std::shared_ptr<ServingPolicy> servingPolicy; // Делегирование поведения расчёта бонуса

public:
    // Конструктор с вызовом конструктора базового класса
    Waiter(int id, const std::string& name, double rate, int tablesServed = 0);
    Waiter(int id,
        const std::string& name,
        double rate,
        std::shared_ptr<ServingPolicy> policy,
        int tablesServed = 0);
    // Конструктор копирования
    Waiter(const Waiter& other);
    
    // Переопределение виртуальных методов
    virtual void showInfo() const override; // Переопределение с вызовом базового метода
    virtual double calculateSalary() const override; // Переопределение без вызова базового метода
    virtual std::string getEmployeeType() const override { return "Waiter"; }
    
    // Новые методы
    void serveTable(int tableNumber);
    void addTips(double amount);
    int getTablesServed() const { return this->tablesServed; }
    double getTips() const { return this->tips; }
    void setServingPolicy(std::shared_ptr<ServingPolicy> policy) { this->servingPolicy = policy; }
    std::string getServingPolicyName() const { return servingPolicy ? servingPolicy->name() : "none"; }
    
    
    // Оператор присваивания
    Waiter& operator=(const Waiter& other);
    Waiter& operator=(const Employee& other); // Присваивание объектов базового класса
};

#endif // WAITER_HPP

