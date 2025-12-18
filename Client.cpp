#include "Client.hpp"
#include <iostream>

Client::Client(const std::string& name, const std::string& phone)
    : name(name), phone(phone), visitsCount(0), totalSpent(0.0), status("Bronze")
{
}

void Client::addVisit() {
    visitsCount++;
    determineStatus();
}

void Client::updateTotalSpent(double amount) {
    totalSpent += amount;
    determineStatus();
}

void Client::determineStatus() {
    if (totalSpent >= 10000.0 || visitsCount >= 50) {
        status = "Gold";
    } else if (totalSpent >= 5000.0 || visitsCount >= 20) {
        status = "Silver";
    } else {
        status = "Bronze";
    }
}

void Client::showInfo() const {
    std::cout << "Client Info:" << std::endl;
    std::cout << "  Name: " << name << std::endl;
    std::cout << "  Phone: " << phone << std::endl;
    std::cout << "  Visits: " << visitsCount << std::endl;
    std::cout << "  Total Spent: " << totalSpent << std::endl;
    std::cout << "  Status: " << status << std::endl;
}


