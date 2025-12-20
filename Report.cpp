#include "Report.hpp"
#include <iostream>
#include <sstream>
#include <ctime>

// Конструктор
Report::Report(int id, const std::string& type, const std::string& period)
    : reportId(id), type(type), period(period), generatedAt("")
{
    try {
        if (id <= 0) {
            throw std::invalid_argument("Report ID must be positive");
        }
        if (type.empty() || period.empty()) {
            throw std::invalid_argument("Type and period cannot be empty");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in Report constructor: " << e.what() << std::endl;
    }
}

// Конструктор копирования
Report::Report(const Report& other)
    : reportId(other.reportId), type(other.type), 
      period(other.period), generatedAt(other.generatedAt)
{
}

void Report::generateReport() {
    try {
        if (!this->generatedAt.empty()) {
            throw std::runtime_error("Report already generated");
        }
        // Простая генерация времени
        this->generatedAt = "2024-01-01 12:00:00";
        std::cout << "Report generated successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in generateReport: " << e.what() << std::endl;
    }
}

void Report::exportReport() {
    try {
        if (this->generatedAt.empty()) {
            throw std::runtime_error("Report not generated yet");
        }
        std::cout << "Report exported successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in exportReport: " << e.what() << std::endl;
    }
}

void Report::showInfo() const {
    std::cout << "Report Info:" << std::endl;
    std::cout << "  ID: " << this->reportId << std::endl;
    std::cout << "  Type: " << this->type << std::endl;
    std::cout << "  Period: " << this->period << std::endl;
    std::cout << "  Generated At: " << (this->generatedAt.empty() ? "Not generated" : this->generatedAt) << std::endl;
}

// Работа со строками: конкатенация
std::string Report::getReportHeader() const {
    std::stringstream ss;
    ss << "Report #" << this->reportId << " [" << this->type 
       << "] for period: " << this->period;
    return ss.str();
}

// Работа со строками: поиск
bool Report::containsType(const std::string& searchType) const {
    return this->type.find(searchType) != std::string::npos;
}

// Оператор присваивания
Report& Report::operator=(const Report& other) {
    if (this != &other) {
        this->reportId = other.reportId;
        this->type = other.type;
        this->period = other.period;
        this->generatedAt = other.generatedAt;
    }
    return *this;
}

// Оператор сравнения
bool Report::operator==(const Report& other) const {
    return this->reportId == other.reportId;
}

// Дружественная функция для вывода
std::ostream& operator<<(std::ostream& os, const Report& report) {
    os << "Report[ID: " << report.reportId << ", Type: " << report.type 
       << ", Period: " << report.period;
    if (!report.generatedAt.empty()) {
        os << ", Generated: " << report.generatedAt;
    }
    os << "]";
    return os;
}


