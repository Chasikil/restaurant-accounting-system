#ifndef REPORT_HPP
#define REPORT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Report {
private:
    int reportId;
    std::string type;
    std::string period;
    std::string generatedAt;

public:
    // Конструкторы
    Report(int id, const std::string& type, const std::string& period);
    Report(const Report& other); // Конструктор копирования

    // Методы
    void generateReport();
    void exportReport();
    void showInfo() const;
    
    // Геттеры с использованием this
    int getId() const { return this->reportId; }
    std::string getType() const { return this->type; }
    std::string getPeriod() const { return this->period; }
    
    // Работа со строками
    std::string getReportHeader() const; // Конкатенация строк
    bool containsType(const std::string& searchType) const; // Поиск в строке
    
    // Перегрузка операторов
    Report& operator=(const Report& other);
    bool operator==(const Report& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Report& report);
};

#endif // REPORT_HPP


