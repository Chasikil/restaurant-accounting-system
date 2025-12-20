#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Order {
private:
    int orderId;
    double totalAmount;
    std::string status;
    std::string time;

public:
    // Конструкторы
    Order(int id, const std::string& time);
    Order(const Order& other); // Конструктор копирования
    
    // Методы
    void addItem(double price);
    void removeItem(double price);
    void calculateTotal();
    void showInfo() const;
    
    // Геттеры с использованием this
    int getId() const { return this->orderId; }
    double getTotalAmount() const { return this->totalAmount; }
    std::string getStatus() const { return this->status; }
    
    // Работа со строками
    std::string formatTime() const; // Форматирование времени
    bool containsTime(const std::string& searchTime) const; // Поиск во времени
    
    // Перегрузка операторов
    Order& operator=(const Order& other); // Оператор присваивания
    bool operator==(const Order& other) const; // Оператор сравнения
    Order& operator+=(double price); // Оператор += для добавления суммы
    bool operator<(const Order& other) const; // Оператор < для сравнения сумм
    friend std::istream& operator>>(std::istream& is, Order& order); // Дружественная функция для ввода
    friend std::ostream& operator<<(std::ostream& os, const Order& order); // Дружественная функция для вывода
};

#endif // ORDER_HPP


