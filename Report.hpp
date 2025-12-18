#ifndef REPORT_HPP
#define REPORT_HPP

#include <string>

class Report {
private:
    int reportId;
    std::string type;
    std::string period;
    std::string generatedAt;

public:
    Report(int id, const std::string& type, const std::string& period);

    void generateReport();
    void exportReport();
    void showInfo() const;
};

#endif // REPORT_HPP


