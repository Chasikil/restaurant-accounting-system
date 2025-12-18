#include "Shift.hpp"
#include <iostream>

Shift::Shift(int id, const std::string& startTime)
    : shiftId(id), startTime(startTime), endTime(""), status("Closed")
{
}

void Shift::openShift() {
    status = "Open";
}

void Shift::closeShift() {
    status = "Closed";
}

void Shift::showInfo() const {
    std::cout << "Shift Info:" << std::endl;
    std::cout << "  ID: " << shiftId << std::endl;
    std::cout << "  Start Time: " << startTime << std::endl;
    std::cout << "  End Time: " << (endTime.empty() ? "Not set" : endTime) << std::endl;
    std::cout << "  Status: " << status << std::endl;
}


