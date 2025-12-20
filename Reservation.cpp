#include "Reservation.hpp"
#include <iostream>
#include <sstream>

// Конструктор
Reservation::Reservation(int id, const std::string& dateTime)
    : reservationId(id), dateTime(dateTime), status("Pending")
{
    try {
        if (id <= 0) {
            throw std::invalid_argument("Reservation ID must be positive");
        }
        if (dateTime.empty()) {
            throw std::invalid_argument("DateTime cannot be empty");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in Reservation constructor: " << e.what() << std::endl;
    }
}

// Конструктор копирования
Reservation::Reservation(const Reservation& other)
    : reservationId(other.reservationId), dateTime(other.dateTime), status(other.status)
{
}

void Reservation::createReservation() {
    try {
        if (this->status == "Cancelled") {
            throw std::runtime_error("Cannot create a cancelled reservation");
        }
        this->status = "Active";
    } catch (const std::exception& e) {
        std::cerr << "Error in createReservation: " << e.what() << std::endl;
    }
}

void Reservation::cancelReservation() {
    this->status = "Cancelled";
}

void Reservation::changeDateTime(const std::string& newDateTime) {
    try {
        if (newDateTime.empty()) {
            throw std::invalid_argument("New dateTime cannot be empty");
        }
        this->dateTime = newDateTime;
    } catch (const std::exception& e) {
        std::cerr << "Error in changeDateTime: " << e.what() << std::endl;
    }
}

void Reservation::showInfo() const {
    std::cout << "Reservation Info:" << std::endl;
    std::cout << "  ID: " << this->reservationId << std::endl;
    std::cout << "  DateTime: " << this->dateTime << std::endl;
    std::cout << "  Status: " << this->status << std::endl;
}

// Работа со строками: конкатенация
std::string Reservation::getFormattedInfo() const {
    std::stringstream ss;
    ss << "Reservation #" << this->reservationId << " (" << this->status 
       << ") - " << this->dateTime;
    return ss.str();
}

// Работа со строками: поиск
bool Reservation::containsDate(const std::string& date) const {
    return this->dateTime.find(date) != std::string::npos;
}

// Оператор присваивания
Reservation& Reservation::operator=(const Reservation& other) {
    if (this != &other) {
        this->reservationId = other.reservationId;
        this->dateTime = other.dateTime;
        this->status = other.status;
    }
    return *this;
}

// Оператор сравнения
bool Reservation::operator==(const Reservation& other) const {
    return this->reservationId == other.reservationId;
}

bool Reservation::operator!=(const Reservation& other) const {
    return !(*this == other);
}

// Дружественная функция для вывода
std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
    os << "Reservation[ID: " << reservation.reservationId 
       << ", DateTime: " << reservation.dateTime 
       << ", Status: " << reservation.status << "]";
    return os;
}


