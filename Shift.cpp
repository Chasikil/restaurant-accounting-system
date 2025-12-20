#include "Shift.hpp"
#include <iostream>
#include <sstream>

// Конструктор
Shift::Shift(int id, const std::string& startTime)
    : shiftId(id), startTime(startTime), endTime(""), status("Closed")
{
    try {
        if (id <= 0) {
            throw std::invalid_argument("Shift ID must be positive");
        }
        if (startTime.empty()) {
            throw std::invalid_argument("Start time cannot be empty");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in Shift constructor: " << e.what() << std::endl;
    }
}

// Конструктор копирования
Shift::Shift(const Shift& other)
    : shiftId(other.shiftId), startTime(other.startTime), 
      endTime(other.endTime), status(other.status)
{
}

void Shift::openShift() {
    try {
        if (this->status == "Open") {
            throw std::runtime_error("Shift is already open");
        }
        this->status = "Open";
    } catch (const std::exception& e) {
        std::cerr << "Error in openShift: " << e.what() << std::endl;
    }
}

void Shift::closeShift() {
    this->status = "Closed";
}

void Shift::showInfo() const {
    std::cout << "Shift Info:" << std::endl;
    std::cout << "  ID: " << this->shiftId << std::endl;
    std::cout << "  Start Time: " << this->startTime << std::endl;
    std::cout << "  End Time: " << (this->endTime.empty() ? "Not set" : this->endTime) << std::endl;
    std::cout << "  Status: " << this->status << std::endl;
}

// Работа со строками: конкатенация
std::string Shift::getShiftPeriod() const {
    std::stringstream ss;
    ss << "Shift #" << this->shiftId << ": " << this->startTime;
    if (!this->endTime.empty()) {
        ss << " - " << this->endTime;
    }
    ss << " (" << this->status << ")";
    return ss.str();
}

// Работа со строками: поиск
bool Shift::isTimeInShift(const std::string& time) const {
    return this->startTime.find(time) != std::string::npos || 
           this->endTime.find(time) != std::string::npos;
}

// Оператор присваивания
Shift& Shift::operator=(const Shift& other) {
    if (this != &other) {
        this->shiftId = other.shiftId;
        this->startTime = other.startTime;
        this->endTime = other.endTime;
        this->status = other.status;
    }
    return *this;
}

// Оператор сравнения
bool Shift::operator==(const Shift& other) const {
    return this->shiftId == other.shiftId;
}

// Дружественная функция для вывода
std::ostream& operator<<(std::ostream& os, const Shift& shift) {
    os << "Shift[ID: " << shift.shiftId << ", Start: " << shift.startTime;
    if (!shift.endTime.empty()) {
        os << ", End: " << shift.endTime;
    }
    os << ", Status: " << shift.status << "]";
    return os;
}


