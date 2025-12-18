// Laboratory work #2: UML-based class implementation


#include <iostream>
#include "Client.hpp"
#include "Order.hpp"

int main() {
    std::cout << "=== Demonstration of object creation and usage in C++ ===\n\n";

    // 1. Статическое создание объекта класса
    std::cout << "1. Static object creation:\n";
    std::cout << "----------------------------\n";
    Client client1("Ivan Petrov", "+7-999-123-45-67");
    client1.addVisit();
    client1.updateTotalSpent(1500.0);
    client1.showInfo();
    std::cout << std::endl;

    // 2. Динамическое создание объекта с new и delete
    std::cout << "2. Dynamic object creation with new and delete:\n";
    std::cout << "------------------------------------------------\n";
    Order* order1 = new Order(101, "2024-01-15 14:30:00");
    order1->addItem(250.0);
    order1->addItem(180.0);
    order1->showInfo();
    delete order1; // Освобождение памяти
    std::cout << std::endl;

    // 3. Работа с объектом по ссылке
    std::cout << "3. Working with object by reference:\n";
    std::cout << "-------------------------------------\n";
    Client client2("Maria Sidorova", "+7-999-234-56-78");
    Client& clientRef = client2; // Создание ссылки на объект
    clientRef.addVisit();
    clientRef.updateTotalSpent(3200.0);
    clientRef.showInfo();
    std::cout << "Note: client2 and clientRef refer to the same object.\n";
    std::cout << std::endl;

    // 4. Работа с объектом по указателю
    std::cout << "4. Working with object by pointer:\n";
    std::cout << "-----------------------------------\n";
    Order order2(102, "2024-01-15 15:00:00");
    Order* orderPtr = &order2; // Указатель на статический объект
    orderPtr->addItem(500.0);
    orderPtr->addItem(300.0);
    orderPtr->showInfo();
    std::cout << std::endl;

    // 5. Динамический массив объектов класса
    std::cout << "5. Dynamic array of objects:\n";
    std::cout << "-----------------------------\n";
    const int clientCount = 3;
    Client* clients = new Client[clientCount] {
        Client("Anna Ivanova", "+7-999-345-67-89"),
        Client("Petr Kozlov", "+7-999-456-78-90"),
        Client("Olga Volkova", "+7-999-567-89-01")
    };

    for (int i = 0; i < clientCount; ++i) {
        clients[i].addVisit();
        clients[i].updateTotalSpent((i + 1) * 1000.0);
        clients[i].showInfo();
        std::cout << std::endl;
    }
    delete[] clients; // Освобождение памяти массива
    std::cout << std::endl;

    // 6. Массив указателей на динамические объекты класса
    std::cout << "6. Array of pointers to dynamic objects:\n";
    std::cout << "-----------------------------------------\n";
    const int orderCount = 3;
    Order** orders = new Order*[orderCount]; // Массив указателей на Order

    // Создание динамических объектов
    orders[0] = new Order(201, "2024-01-15 16:00:00");
    orders[1] = new Order(202, "2024-01-15 16:30:00");
    orders[2] = new Order(203, "2024-01-15 17:00:00");

    // Работа с объектами через указатели
    orders[0]->addItem(100.0);
    orders[0]->addItem(50.0);
    
    orders[1]->addItem(200.0);
    orders[1]->addItem(150.0);
    
    orders[2]->addItem(300.0);

    // Вывод информации
    for (int i = 0; i < orderCount; ++i) {
        orders[i]->showInfo();
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < orderCount; ++i) {
        delete orders[i]; // Удаление каждого объекта
    }
    delete[] orders; // Удаление массива указателей
    std::cout << std::endl;

    std::cout << "=== Demonstration completed ===\n";
    return 0;
}

