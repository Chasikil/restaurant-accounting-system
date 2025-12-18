#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>

class Order {
private:
    int orderId;
    double totalAmount;
    std::string status;
    std::string time;

public:
    Order(int id, const std::string& time);

    void addItem(double price);
    void removeItem(double price);
    void calculateTotal();
    void showInfo() const;
};

#endif // ORDER_HPP


