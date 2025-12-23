#ifndef SERVING_POLICY_HPP
#define SERVING_POLICY_HPP

#include <string>

// Интерфейс стратегии расчёта бонусов официанта
class ServingPolicy {
public:
    virtual ~ServingPolicy() = default;
    virtual double computeBonus(double hoursWorked,
                                double hourlyRate,
                                int tablesServed,
                                double tips) const = 0;
    virtual std::string name() const = 0;
};

// Базовая стратегия: фиксированный бонус за стол
class StandardServingPolicy : public ServingPolicy {
public:
    double computeBonus(double /*hoursWorked*/,
                        double /*hourlyRate*/,
                        int tablesServed,
                        double /*tips*/) const override {
        return tablesServed * 50.0;
    }

    std::string name() const override { return "standard"; }
};

// Стратегия для событий / высокой нагрузки
class EventServingPolicy : public ServingPolicy {
public:
    double computeBonus(double /*hoursWorked*/,
                        double /*hourlyRate*/,
                        int tablesServed,
                        double tips) const override {
        // Увеличенный бонус + доля чаевых
        return tablesServed * 80.0 + tips * 0.05;
    }

    std::string name() const override { return "event"; }
};

#endif // SERVING_POLICY_HPP


