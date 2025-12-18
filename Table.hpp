#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>

class Table {
private:
    int tableNumber;
    int seats;
    std::string status;
    int currentOrder;

public:
    Table(int number, int seats);

    void assignOrder(int orderId);
    void freeTable();
    bool isAvailable() const;
    void showInfo() const;
};

#endif // TABLE_HPP


