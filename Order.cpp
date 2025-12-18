#include "Order.hpp"
#include <iostream>

Order::Order(int id, const std::string& time)
    : orderId(id), totalAmount(0.0), status("Pending"), time(time)
{
}

void Order::addItem(double price) {
    totalAmount += price;
    calculateTotal();
}

void Order::removeItem(double price) {
    if (totalAmount >= price) {
        totalAmount -= price;
    }
    calculateTotal();
}

void Order::calculateTotal() {
    if (totalAmount > 0.0) {
        status = "Active";
    } else {
        status = "Empty";
    }
}

void Order::showInfo() const {
    std::cout << "Order Info:" << std::endl;
    std::cout << "  ID: " << orderId << std::endl;
    std::cout << "  Total Amount: " << totalAmount << std::endl;
    std::cout << "  Status: " << status << std::endl;
    std::cout << "  Time: " << time << std::endl;
}


