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
    
    // Переопределенный метод базового класса
    void showInfo() const;
    
    // Перегрузка операторов
    VIPClient& operator=(const VIPClient& other);
};

#endif // VIPCLIENT_HPP

