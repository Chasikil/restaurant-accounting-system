#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client {
private:
    std::string name;
    std::string phone;
    int visitsCount;
    double totalSpent;
    std::string status;

public:
    Client(const std::string& name, const std::string& phone);

    void addVisit();
    void updateTotalSpent(double amount);
    void determineStatus();
    void showInfo() const;
};

#endif // CLIENT_HPP


