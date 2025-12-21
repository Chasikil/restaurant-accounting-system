#ifndef VIPCLIENT_HPP
#define VIPCLIENT_HPP

#include "Client.hpp"
#include <string>

// Класс VIPClient наследуется от Client для демонстрации наследования
class VIPClient : public Client {
private:
    std::string vipLevel; // Уровень VIP
    double discount; // Скидка в процентах

public:
    // Конструктор с вызовом конструктора базового класса
    VIPClient(const std::string& name, const std::string& phone, 
              const std::string& vipLevel, double discount);
    
    // Конструктор копирования
    VIPClient(const VIPClient& other);
    
    // Методы
    void setVipLevel(const std::string& level);
    double getDiscount() const { return this->discount; }
    std::string getVipLevel() const { return this->vipLevel; }
    
    // Переопределение виртуальных методов базового класса
    virtual void showInfo() const override; // Переопределение с вызовом базового метода
    virtual std::string getType() const override { return "VIPClient"; }
    virtual double calculateValue() const override { return this->totalSpent * (1.0 - discount / 100.0); }
    
    // Перегрузка операторов
    VIPClient& operator=(const VIPClient& other);
    VIPClient& operator=(const Client& other); // Присваивание объектов базового класса
    VIPClient& operator=(const RestaurantEntity& other); // Присваивание объектов базового класса
};

#endif // VIPCLIENT_HPP


