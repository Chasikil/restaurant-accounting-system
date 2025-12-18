#include "Reservation.hpp"
#include <iostream>

Reservation::Reservation(int id, const std::string& dateTime)
    : reservationId(id), dateTime(dateTime), status("Pending")
{
}

void Reservation::createReservation() {
    status = "Active";
}

void Reservation::cancelReservation() {
    status = "Cancelled";
}

void Reservation::changeDateTime(const std::string& newDateTime) {
    dateTime = newDateTime;
}

void Reservation::showInfo() const {
    std::cout << "Reservation Info:" << std::endl;
    std::cout << "  ID: " << reservationId << std::endl;
    std::cout << "  DateTime: " << dateTime << std::endl;
    std::cout << "  Status: " << status << std::endl;
}


