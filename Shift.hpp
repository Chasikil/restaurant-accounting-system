#ifndef SHIFT_HPP
#define SHIFT_HPP

#include <string>

class Shift {
private:
    int shiftId;
    std::string startTime;
    std::string endTime;
    std::string status;

public:
    Shift(int id, const std::string& startTime);

    void openShift();
    void closeShift();
    void showInfo() const;
};

#endif // SHIFT_HPP


