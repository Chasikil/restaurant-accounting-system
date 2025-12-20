#ifndef SHIFT_HPP
#define SHIFT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Shift {
private:
    int shiftId;
    std::string startTime;
    std::string endTime;
    std::string status;

public:
    // Конструкторы
    Shift(int id, const std::string& startTime);
    Shift(const Shift& other); // Конструктор копирования

    // Методы
    void openShift();
    void closeShift();
    void showInfo() const;
    
    // Геттеры с использованием this
    int getId() const { return this->shiftId; }
    std::string getStatus() const { return this->status; }
    std::string getStartTime() const { return this->startTime; }
    
    // Работа со строками
    std::string getShiftPeriod() const; // Конкатенация строк
    bool isTimeInShift(const std::string& time) const; // Поиск в строке
    
    // Перегрузка операторов
    Shift& operator=(const Shift& other);
    bool operator==(const Shift& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Shift& shift);
};

#endif // SHIFT_HPP


