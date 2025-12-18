#include "Table.hpp"
#include <iostream>

Table::Table(int number, int seats)
    : tableNumber(number), seats(seats), status("Available"), currentOrder(0)
{
}

void Table::assignOrder(int orderId) {
    currentOrder = orderId;
    status = "Occupied";
}

void Table::freeTable() {
    currentOrder = 0;
    status = "Available";
}

bool Table::isAvailable() const {
    return status == "Available";
}

void Table::showInfo() const {
    std::cout << "Table Info:" << std::endl;
    std::cout << "  Number: " << tableNumber << std::endl;
    std::cout << "  Seats: " << seats << std::endl;
    std::cout << "  Status: " << status << std::endl;
    std::cout << "  Current Order: " << (currentOrder > 0 ? std::to_string(currentOrder) : "None") << std::endl;
}


