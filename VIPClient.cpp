#include "VIPClient.hpp"
#include <iostream>
#include <stdexcept>

// Конструктор с вызовом конструктора базового класса
VIPClient::VIPClient(const std::string& name, const std::string& phone, 
                     const std::string& vipLevel, double discount)
    : Client(name, phone), vipLevel(vipLevel), discount(discount)
{
    // Вызов конструктора базового класса Client через список инициализации
    try {
        if (discount < 0.0 || discount > 100.0) {
            throw std::invalid_argument("Discount must be between 0 and 100");
        }
        // VIP клиенты сразу получают статус Gold
        this->status = "Gold";
    } catch (const std::exception& e) {
        std::cerr << "Error in VIPClient constructor: " << e.what() << std::endl;
    }
}

// Конструктор копирования
VIPClient::VIPClient(const VIPClient& other)
    : Client(other), vipLevel(other.vipLevel), discount(other.discount)
{
    // Вызов конструктора копирования базового класса
}

void VIPClient::setVipLevel(const std::string& level) {
    this->vipLevel = level;
}

// Переопределение метода базового класса с вызовом базового метода
void VIPClient::showInfo() const {
    Client::showInfo(); // Вызов метода базового класса Client
    std::cout << "  VIP Level: " << this->vipLevel << std::endl;
    std::cout << "  Discount: " << this->discount << "%" << std::endl;
    std::cout << "  Discounted Total: " << this->calculateValue() << std::endl;
}

// Оператор присваивания
VIPClient& VIPClient::operator=(const VIPClient& other) {
    if (this != &other) {
        // Вызов оператора присваивания базового класса
        Client::operator=(other);
        this->vipLevel = other.vipLevel;
        this->discount = other.discount;
    }
    return *this;
}

VIPClient& VIPClient::operator=(const Client& other) {
    Client::operator=(other); // Присваивание только базовой части
    // Поля, специфичные для VIPClient, остаются неизменными
    return *this;
}

VIPClient& VIPClient::operator=(const RestaurantEntity& other) {
    RestaurantEntity::operator=(other); // Присваивание только базовой части
    // Поля, специфичные для VIPClient, остаются неизменными
    return *this;
}


