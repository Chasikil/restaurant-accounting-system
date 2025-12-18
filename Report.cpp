#include "Report.hpp"
#include <iostream>

Report::Report(int id, const std::string& type, const std::string& period)
    : reportId(id), type(type), period(period), generatedAt("")
{
}

void Report::generateReport() {
    generatedAt = "2024-01-01 12:00:00";
    std::cout << "Report generated successfully." << std::endl;
}

void Report::exportReport() {
    if (!generatedAt.empty()) {
        std::cout << "Report exported successfully." << std::endl;
    } else {
        std::cout << "Error: Report not generated yet." << std::endl;
    }
}

void Report::showInfo() const {
    std::cout << "Report Info:" << std::endl;
    std::cout << "  ID: " << reportId << std::endl;
    std::cout << "  Type: " << type << std::endl;
    std::cout << "  Period: " << period << std::endl;
    std::cout << "  Generated At: " << (generatedAt.empty() ? "Not generated" : generatedAt) << std::endl;
}


