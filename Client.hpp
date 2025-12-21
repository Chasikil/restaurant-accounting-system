#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "RestaurantEntity.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

// Client наследуется от абстрактного класса RestaurantEntity
class Client : public RestaurantEntity {
protected: // Использование protected для доступа из производных классов
    std::string phone;
    int visitsCount;
    double totalSpent;
    std::string status;
    
    static int totalClients; // Статическое поле - общее количество клиентов

public:
    // Конструкторы
    Client(const std::string& name, const std::string& phone);
    Client(const Client& other); // Конструктор копирования
    
    // Виртуальный деструктор (переопределение виртуального из базового класса)
    virtual ~Client();

    // Переопределение виртуальных функций из базового класса
    virtual void showInfo() const override;
    virtual std::string getType() const override { return "Client"; }
    virtual double calculateValue() const override { return this->totalSpent; }

    // Методы
    void addVisit();
    void updateTotalSpent(double amount);
    void determineStatus();
    
    // Геттеры с использованием this
    std::string getPhone() const { return this->phone; }
    double getTotalSpent() const { return this->totalSpent; }
    
    // Оператор присваивания для присваивания объектов базового класса
    Client& operator=(const RestaurantEntity& other);
    
    // Работа со строками
    std::string getFullInfo() const; // Конкатенация строк
    bool findInName(const std::string& searchTerm) const; // Поиск в строке
    
    // Статический метод
    static int getTotalClients() { return totalClients; }
    
    // Перегрузка операторов
    Client& operator=(const Client& other); // Оператор присваивания
    bool operator==(const Client& other) const; // Оператор сравнения
    bool operator!=(const Client& other) const;
    Client& operator+=(double amount); // Оператор += для добавления суммы
    Client operator+(double amount) const; // Оператор + для добавления суммы
    friend std::ostream& operator<<(std::ostream& os, const Client& client); // Дружественная функция для вывода
};

// Дружественная функция для конкатенации информации о клиенте
std::string concatenateClientInfo(const Client& c1, const Client& c2);

#endif // CLIENT_HPP


