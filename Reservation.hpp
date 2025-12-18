#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <string>

class Reservation {
private:
    int reservationId;
    std::string dateTime;
    std::string status;

public:
    Reservation(int id, const std::string& dateTime);

    void createReservation();
    void cancelReservation();
    void changeDateTime(const std::string& newDateTime);
    void showInfo() const;
};

#endif // RESERVATION_HPP


