#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Reservation {
private:
    int reservationId;
    std::string dateTime;
    std::string status;

public:
    // Конструкторы
    Reservation(int id, const std::string& dateTime);
    Reservation(const Reservation& other); // Конструктор копирования

    // Методы
    void createReservation();
    void cancelReservation();
    void changeDateTime(const std::string& newDateTime);
    void showInfo() const;
    
    // Геттеры с использованием this
    int getId() const { return this->reservationId; }
    std::string getStatus() const { return this->status; }
    std::string getDateTime() const { return this->dateTime; }
    
    // Работа со строками
    std::string getFormattedInfo() const; // Конкатенация строк
    bool containsDate(const std::string& date) const; // Поиск в строке
    
    // Перегрузка операторов
    Reservation& operator=(const Reservation& other);
    bool operator==(const Reservation& other) const;
    bool operator!=(const Reservation& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
};

#endif // RESERVATION_HPP


