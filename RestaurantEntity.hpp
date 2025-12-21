#ifndef RESTAURANT_ENTITY_HPP
#define RESTAURANT_ENTITY_HPP

#include <string>
#include <iostream>

// Абстрактный базовый класс для всех сущностей ресторана
class RestaurantEntity {
protected:
    int entityId;
    std::string name;

public:
    // Конструктор с параметрами
    RestaurantEntity(int id, const std::string& name);
    
    // Виртуальный деструктор (обязателен для полиморфизма)
    virtual ~RestaurantEntity() = default;
    
    // Виртуальные функции
    virtual void showInfo() const = 0; // Чисто виртуальная функция - делает класс абстрактным
    virtual std::string getType() const = 0; // Чисто виртуальная функция
    virtual double calculateValue() const { return 0.0; } // Виртуальная функция с реализацией по умолчанию
    
    // Не виртуальная функция, которая вызывает виртуальную
    void displayInfo() const;
    
    // Геттеры
    int getId() const { return entityId; }
    std::string getName() const { return name; }
    
    // Оператор присваивания
    RestaurantEntity& operator=(const RestaurantEntity& other);
    
    // Запрещаем конструктор копирования по умолчанию (для демонстрации)
    RestaurantEntity(const RestaurantEntity& other) = default; // Оставляем по умолчанию, но можно переопределить в производных
};

#endif // RESTAURANT_ENTITY_HPP

