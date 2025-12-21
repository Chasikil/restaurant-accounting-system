#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <iostream>
#include <stdexcept>

// Интерфейс для клонирования
class Cloneable {
public:
    virtual ~Cloneable() = default;
    virtual Cloneable* clone() const = 0; // Глубокое клонирование
    virtual Cloneable* shallowClone() const = 0; // Поверхностное клонирование
};

class Order : public Cloneable {
private:
    int orderId;
    double totalAmount;
    std::string status;
    std::string time;
    std::string* notes; // Указатель для демонстрации глубокого клонирования

public:
    // Конструкторы
    Order(int id, const std::string& time, const std::string& notes = "");
    Order(const Order& other); // Конструктор копирования (глубокое копирование)
    
    // Деструктор
    ~Order();
    
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
    
    // Методы клонирования
    virtual Cloneable* clone() const override; // Глубокое клонирование
    virtual Cloneable* shallowClone() const override; // Поверхностное клонирование
    Order* cloneOrder() const; // Удобный метод для клонирования Order
    
    // Геттер для notes
    std::string getNotes() const { return notes ? *notes : ""; }
    void setNotes(const std::string& newNotes);
    
    // Перегрузка операторов
    Order& operator=(const Order& other); // Оператор присваивания
    bool operator==(const Order& other) const; // Оператор сравнения
    Order& operator+=(double price); // Оператор += для добавления суммы
    bool operator<(const Order& other) const; // Оператор < для сравнения сумм
    friend std::istream& operator>>(std::istream& is, Order& order); // Дружественная функция для ввода
    friend std::ostream& operator<<(std::ostream& os, const Order& order); // Дружественная функция для вывода
};

#endif // ORDER_HPP


