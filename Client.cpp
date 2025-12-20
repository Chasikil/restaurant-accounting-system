#include "Client.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

// Инициализация статического поля
int Client::totalClients = 0;

Client::Client(const std::string& name, const std::string& phone)
    : name(name), phone(phone), visitsCount(0), totalSpent(0.0), status("Bronze")
{
    totalClients++; // Увеличиваем счетчик клиентов
}

// Конструктор копирования
Client::Client(const Client& other)
    : name(other.name), phone(other.phone), visitsCount(other.visitsCount),
      totalSpent(other.totalSpent), status(other.status)
{
    totalClients++; // Увеличиваем счетчик при копировании
}

Client::~Client() {
    // Деструктор можно оставить пустым, но можно уменьшить счетчик
    // totalClients--; // Раскомментируйте, если нужно уменьшать при удалении
}

void Client::addVisit() {
    this->visitsCount++; // Использование this
    this->determineStatus();
}

void Client::updateTotalSpent(double amount) {
    try {
        if (amount < 0.0) {
            throw std::invalid_argument("Amount cannot be negative");
        }
        this->totalSpent += amount;
        this->determineStatus();
    } catch (const std::exception& e) {
        std::cerr << "Error in updateTotalSpent: " << e.what() << std::endl;
    }
}

void Client::determineStatus() {
    if (this->totalSpent >= 10000.0 || this->visitsCount >= 50) {
        this->status = "Gold";
    } else if (this->totalSpent >= 5000.0 || this->visitsCount >= 20) {
        this->status = "Silver";
    } else {
        this->status = "Bronze";
    }
}

void Client::showInfo() const {
    std::cout << "Client Info:" << std::endl;
    std::cout << "  Name: " << this->name << std::endl;
    std::cout << "  Phone: " << this->phone << std::endl;
    std::cout << "  Visits: " << this->visitsCount << std::endl;
    std::cout << "  Total Spent: " << this->totalSpent << std::endl;
    std::cout << "  Status: " << this->status << std::endl;
}

// Работа со строками: конкатенация
std::string Client::getFullInfo() const {
    std::stringstream ss;
    ss << this->name << " (" << this->phone << ") - " << this->status 
       << " - Total: " << this->totalSpent;
    return ss.str();
}

// Работа со строками: поиск
bool Client::findInName(const std::string& searchTerm) const {
    std::string lowerName = this->name;
    std::string lowerSearch = searchTerm;
    
    // Преобразование в нижний регистр для поиска без учета регистра
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    std::transform(lowerSearch.begin(), lowerSearch.end(), lowerSearch.begin(), ::tolower);
    
    return lowerName.find(lowerSearch) != std::string::npos;
}

// Оператор присваивания
Client& Client::operator=(const Client& other) {
    if (this != &other) { // Проверка на самоприсваивание
        this->name = other.name;
        this->phone = other.phone;
        this->visitsCount = other.visitsCount;
        this->totalSpent = other.totalSpent;
        this->status = other.status;
    }
    return *this;
}

// Оператор сравнения
bool Client::operator==(const Client& other) const {
    return this->name == other.name && this->phone == other.phone;
}

bool Client::operator!=(const Client& other) const {
    return !(*this == other);
}

// Оператор +=
Client& Client::operator+=(double amount) {
    this->updateTotalSpent(amount);
    return *this;
}

// Оператор +
Client Client::operator+(double amount) const {
    Client result = *this;
    result += amount;
    return result;
}

// Дружественная функция для вывода
std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << "Client[" << client.name << ", " << client.phone 
       << ", Status: " << client.status << ", Spent: " << client.totalSpent << "]";
    return os;
}

// Дружественная функция для конкатенации информации
std::string concatenateClientInfo(const Client& c1, const Client& c2) {
    return c1.getFullInfo() + " | " + c2.getFullInfo();
}


