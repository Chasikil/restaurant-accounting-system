#include "Table.hpp"
#include <iostream>
#include <sstream>

// Конструктор
Table::Table(int number, int seats)
    : tableNumber(number), seats(seats), status("Available"), currentOrder(0)
{
    try {
        if (number <= 0) {
            throw std::invalid_argument("Table number must be positive");
        }
        if (seats <= 0) {
            throw std::invalid_argument("Number of seats must be positive");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in Table constructor: " << e.what() << std::endl;
    }
}

// Конструктор копирования
Table::Table(const Table& other)
    : tableNumber(other.tableNumber), seats(other.seats), 
      status(other.status), currentOrder(other.currentOrder)
{
}

void Table::assignOrder(int orderId) {
    try {
        if (orderId <= 0) {
            throw std::invalid_argument("Order ID must be positive");
        }
        if (!this->isAvailable()) {
            throw std::runtime_error("Table is already occupied");
        }
        this->currentOrder = orderId;
        this->status = "Occupied";
    } catch (const std::exception& e) {
        std::cerr << "Error in assignOrder: " << e.what() << std::endl;
    }
}

void Table::freeTable() {
    this->currentOrder = 0;
    this->status = "Available";
}

bool Table::isAvailable() const {
    return this->status == "Available";
}

void Table::showInfo() const {
    std::cout << "Table Info:" << std::endl;
    std::cout << "  Number: " << this->tableNumber << std::endl;
    std::cout << "  Seats: " << this->seats << std::endl;
    std::cout << "  Status: " << this->status << std::endl;
    std::cout << "  Current Order: " << (this->currentOrder > 0 ? std::to_string(this->currentOrder) : "None") << std::endl;
}

// Работа со строками: конкатенация
std::string Table::getTableDescription() const {
    std::stringstream ss;
    ss << "Table #" << this->tableNumber << " (" << this->seats 
       << " seats) - " << this->status;
    return ss.str();
}

// Оператор присваивания
Table& Table::operator=(const Table& other) {
    if (this != &other) {
        this->tableNumber = other.tableNumber;
        this->seats = other.seats;
        this->status = other.status;
        this->currentOrder = other.currentOrder;
    }
    return *this;
}

// Оператор сравнения
bool Table::operator==(const Table& other) const {
    return this->tableNumber == other.tableNumber;
}

// Оператор < (сравнение по номеру стола)
bool Table::operator<(const Table& other) const {
    return this->tableNumber < other.tableNumber;
}

// Дружественная функция для вывода
std::ostream& operator<<(std::ostream& os, const Table& table) {
    os << "Table[#: " << table.tableNumber << ", Seats: " << table.seats 
       << ", Status: " << table.status << "]";
    return os;
}


