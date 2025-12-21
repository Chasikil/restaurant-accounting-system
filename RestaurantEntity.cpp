#include "RestaurantEntity.hpp"

RestaurantEntity::RestaurantEntity(int id, const std::string& name)
    : entityId(id), name(name)
{
}

// Не виртуальная функция, которая вызывает виртуальную
void RestaurantEntity::displayInfo() const {
    std::cout << "Displaying info via non-virtual function:" << std::endl;
    showInfo(); // Вызов виртуальной функции из невиртуальной
}

RestaurantEntity& RestaurantEntity::operator=(const RestaurantEntity& other) {
    if (this != &other) {
        this->entityId = other.entityId;
        this->name = other.name;
    }
    return *this;
}

