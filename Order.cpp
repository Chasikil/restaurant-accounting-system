#include "Order.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

// Конструктор
Order::Order(int id, const std::string& time, const std::string& notes)
    : orderId(id), totalAmount(0.0), status("Pending"), time(time)
{
    try {
        if (id <= 0) {
            throw std::invalid_argument("Order ID must be positive");
        }
        if (notes.empty()) {
            this->notes = nullptr;
        } else {
            this->notes = new std::string(notes); // Динамическое выделение памяти
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in Order constructor: " << e.what() << std::endl;
        this->notes = nullptr;
    }
}

// Конструктор копирования (глубокое копирование)
Order::Order(const Order& other)
    : orderId(other.orderId), totalAmount(other.totalAmount), 
      status(other.status), time(other.time)
{
    // Глубокое копирование указателя
    if (other.notes != nullptr) {
        this->notes = new std::string(*(other.notes));
    } else {
        this->notes = nullptr;
    }
}

// Деструктор
Order::~Order() {
    delete notes; // Освобождение памяти
    notes = nullptr;
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
    if (this->notes != nullptr) {
        std::cout << "  Notes: " << *(this->notes) << std::endl;
    }
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

// Оператор присваивания (глубокое копирование)
Order& Order::operator=(const Order& other) {
    if (this != &other) {
        this->orderId = other.orderId;
        this->totalAmount = other.totalAmount;
        this->status = other.status;
        this->time = other.time;
        
        // Глубокое копирование указателя
        if (this->notes != nullptr) {
            delete this->notes;
        }
        if (other.notes != nullptr) {
            this->notes = new std::string(*(other.notes));
        } else {
            this->notes = nullptr;
        }
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

// Методы клонирования
Cloneable* Order::clone() const {
    // Глубокое клонирование - создаем новый объект с копированием всех данных
    Order* newOrder = new Order(*this);
    return newOrder;
}

Cloneable* Order::shallowClone() const {
    // Поверхностное клонирование - создаем новый объект, но указатель notes указывает на те же данные
    Order* newOrder = new Order(this->orderId, this->time);
    newOrder->totalAmount = this->totalAmount;
    newOrder->status = this->status;
    newOrder->notes = this->notes; // Указатель копируется, не данные!
    return newOrder;
}

Order* Order::cloneOrder() const {
    return dynamic_cast<Order*>(clone());
}

void Order::setNotes(const std::string& newNotes) {
    if (notes != nullptr) {
        delete notes;
    }
    if (newNotes.empty()) {
        notes = nullptr;
    } else {
        notes = new std::string(newNotes);
    }
}

// Дружественная функция для вывода
std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << "Order[ID: " << order.orderId << ", Amount: " << order.totalAmount 
       << ", Status: " << order.status << ", Time: " << order.time;
    if (order.notes != nullptr) {
        os << ", Notes: " << *(order.notes);
    }
    os << "]";
    return os;
}


