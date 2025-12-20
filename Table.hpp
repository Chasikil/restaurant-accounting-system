#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Table {
private:
    int tableNumber;
    int seats;
    std::string status;
    int currentOrder;

public:
    // Конструкторы
    Table(int number, int seats);
    Table(const Table& other); // Конструктор копирования

    // Методы
    void assignOrder(int orderId);
    void freeTable();
    bool isAvailable() const;
    void showInfo() const;
    
    // Геттеры с использованием this
    int getTableNumber() const { return this->tableNumber; }
    int getSeats() const { return this->seats; }
    std::string getStatus() const { return this->status; }
    
    // Работа со строками
    std::string getTableDescription() const; // Конкатенация строк
    
    // Перегрузка операторов
    Table& operator=(const Table& other);
    bool operator==(const Table& other) const;
    bool operator<(const Table& other) const; // Сравнение по номеру стола
    friend std::ostream& operator<<(std::ostream& os, const Table& table);
};

#endif // TABLE_HPP


