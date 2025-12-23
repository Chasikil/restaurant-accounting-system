#include "Waiter.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

namespace {
std::shared_ptr<ServingPolicy> createPolicyFromEnv() {
    const char* mode = std::getenv("WAITER_POLICY");
    std::string value = (mode != nullptr) ? std::string(mode) : "";
    if (value == "event") {
        return std::make_shared<EventServingPolicy>();
    }
    return std::make_shared<StandardServingPolicy>();
}
} // namespace

Waiter::Waiter(int id, const std::string& name, double rate, int tablesServed)
    : Employee(id, name, "Waiter", rate),
      tablesServed(tablesServed),
      tips(0.0),
      servingPolicy(createPolicyFromEnv())
{
    // Вызов конструктора базового класса Employee в списке инициализации
}

Waiter::Waiter(int id,
               const std::string& name,
               double rate,
               std::shared_ptr<ServingPolicy> policy,
               int tablesServed)
    : Employee(id, name, "Waiter", rate),
      tablesServed(tablesServed),
      tips(0.0),
      servingPolicy(policy ? policy : createPolicyFromEnv()) {}

Waiter::Waiter(const Waiter& other)
    : Employee(other),
      tablesServed(other.tablesServed),
      tips(other.tips),
      servingPolicy(other.servingPolicy)
{
    // Вызов конструктора копирования базового класса
}

void Waiter::showInfo() const {
    // Переопределение метода с вызовом базового метода
    Employee::showInfo(); // Вызов метода базового класса
    std::cout << "  Tables Served: " << this->tablesServed << std::endl;
    std::cout << "  Tips: " << this->tips << std::endl;
    std::cout << "  Serving policy: " << this->getServingPolicyName() << std::endl;
    std::cout << "  Total Earnings: " << (this->calculateSalary() + this->tips) << std::endl;
}

double Waiter::calculateSalary() const {
    // Переопределение без вызова базового метода
    // Официанты получают базовую зарплату плюс бонус за обслуженные столы
    double baseSalary = this->hoursWorked * this->hourlyRate;
    double bonus = servingPolicy ? servingPolicy->computeBonus(this->hoursWorked,
                                                               this->hourlyRate,
                                                               this->tablesServed,
                                                               this->tips)
                                 : this->tablesServed * 50.0;
    return baseSalary + bonus;
}

void Waiter::serveTable(int tableNumber) {
    this->tablesServed++;
}

void Waiter::addTips(double amount) {
    if (amount > 0.0) {
        this->tips += amount;
    }
}

Waiter& Waiter::operator=(const Waiter& other) {
    if (this != &other) {
        Employee::operator=(other); // Вызов оператора базового класса
        this->tablesServed = other.tablesServed;
        this->tips = other.tips;
        this->servingPolicy = other.servingPolicy;
    }
    return *this;
}

Waiter& Waiter::operator=(const Employee& other) {
    Employee::operator=(other); // Присваивание только базовой части
    // Поля, специфичные для Waiter, остаются неизменными
    return *this;
}

