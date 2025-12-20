#include "Order.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

// Конструктор
Order::Order(int id, const std::string& time)
    : orderId(id), totalAmount(0.0), status("Pending"), time(time)
{
    try {
        if (id <= 0) {
            throw std::invalid_argument("Order ID must be positive");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in Order constructor: " << e.what() << std::endl;
    }
}

// Конструктор копирования
Order::Order(const Order& other)
    : orderId(other.orderId), totalAmount(other.totalAmount), 
      status(other.status), time(other.time)
{
}

void Order::addItem(double price) {
    try {
        if (price < 0.0) {
            throw std::invalid_argument("Price cannot be negative");
        }
        this->totalAmount += price;
        this->calculateTotal();
    } catch (const std::exception& e) {
        std::cerr << "Error in addItem: " << e.what() << std::endl;
    }
}

void Order::removeItem(double price) {
    try {
        if (price < 0.0) {
            throw std::invalid_argument("Price cannot be negative");
        }
        if (this->totalAmount < price) {
            throw std::runtime_error("Insufficient amount to remove");
        }
        this->totalAmount -= price;
        this->calculateTotal();
    } catch (const std::exception& e) {
        std::cerr << "Error in removeItem: " << e.what() << std::endl;
    }
}

void Order::calculateTotal() {
    if (this->totalAmount > 0.0) {
        this->status = "Active";
    } else {
        this->status = "Empty";
    }
}

void Order::showInfo() const {
    std::cout << "Order Info:" << std::endl;
    std::cout << "  ID: " << this->orderId << std::endl;
    std::cout << "  Total Amount: " << this->totalAmount << std::endl;
    std::cout << "  Status: " << this->status << std::endl;
    std::cout << "  Time: " << this->time << std::endl;
}

// Работа со строками: форматирование
std::string Order::formatTime() const {
    std::string formatted = "Time: " + this->time;
    return formatted;
}

// Работа со строками: поиск
bool Order::containsTime(const std::string& searchTime) const {
    return this->time.find(searchTime) != std::string::npos;
}

// Оператор присваивания
Order& Order::operator=(const Order& other) {
    if (this != &other) {
        this->orderId = other.orderId;
        this->totalAmount = other.totalAmount;
        this->status = other.status;
        this->time = other.time;
    }
    return *this;
}

// Оператор сравнения
bool Order::operator==(const Order& other) const {
    return this->orderId == other.orderId;
}

// Оператор +=
Order& Order::operator+=(double price) {
    this->addItem(price);
    return *this;
}

// Оператор < (сравнение по сумме)
bool Order::operator<(const Order& other) const {
    return this->totalAmount < other.totalAmount;
}

// Дружественная функция для ввода (упрощенная версия)
std::istream& operator>>(std::istream& is, Order& order) {
    std::cout << "Enter order ID: ";
    is >> order.orderId;
    std::cout << "Enter total amount: ";
    is >> order.totalAmount;
    std::cout << "Enter time: ";
    is >> order.time;
    order.calculateTotal();
    return is;
}

// Дружественная функция для вывода
std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << "Order[ID: " << order.orderId << ", Amount: " << order.totalAmount 
       << ", Status: " << order.status << ", Time: " << order.time << "]";
    return os;
}


