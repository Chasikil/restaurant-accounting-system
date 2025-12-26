// Laboratory work #2: UML-based class implementation
// Extended with smart pointers, operators, inheritance, exceptions, etc.

#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <array>
#include <span>
#include <variant>
#include <memory>
#include <vector>
#include "Client.hpp"
#include "Order.hpp"
#include "Employee.hpp"
#include "Waiter.hpp"
#include "VIPClient.hpp"
#include "utils.hpp"
#include "ReportStorage.hpp"
#include "SalesReport.hpp"
#include "ReportRepository.hpp"

int main() {
    std::cout << "=== Demonstration of advanced C++ features ===\n\n";
    void demoCopyTransform() {
        std::vector<int> src = {1, 2, 3};
        std::vector<int> dst(3);
    
        std::copy(src.begin(), src.end(), dst.begin());
    
        std::transform(dst.begin(), dst.end(), dst.begin(),
                       [](int x) { return x * 2; });
    
        for (int x : dst)
            std::cout << x << " ";
        std::cout << "\n";
    }
    void demoTemplateClass() {
        ReportStorage<SalesReport> storage;
        storage.add(std::make_shared<SalesReport>());
        std::cout << "Reports count: " << storage.count() << "\n";
    }
    void demoTemplateFunction() {
        int prices[] = {100, 200, 300};
        std::cout << "Sum: " << sumValues(prices, 3) << "\n";
    }    
    void demoVectorEmployees() {
        std::vector<std::shared_ptr<Employee>> staff;
    
        staff.push_back(std::make_shared<Employee>("Ivan", 30000));
        staff.push_back(std::make_shared<Waiter>("Anna", 25000, 10));
        staff.push_back(std::make_shared<Waiter>("Oleg", 27000, 15));
    
        std::cout << "=== Employees list ===\n";
        for (const auto& e : staff) {
            e->showInfo(); // виртуальный вызов
        }
    }
    void demoSortEmployees() {
        std::vector<std::shared_ptr<Employee>> staff;
    
        staff.push_back(std::make_shared<Employee>("Ivan", 30000));
        staff.push_back(std::make_shared<Employee>("Petr", 28000));
        staff.push_back(std::make_shared<Employee>("Alex", 35000));
    
        std::sort(staff.begin(), staff.end(),
            [](const auto& a, const auto& b) {
                return a->getSalary() < b->getSalary();
            });
    
        auto minEmp = std::min_element(staff.begin(), staff.end(),
            [](const auto& a, const auto& b) {
                return a->getSalary() < b->getSalary();
            });
    
        auto maxEmp = std::max_element(staff.begin(), staff.end(),
            [](const auto& a, const auto& b) {
                return a->getSalary() < b->getSalary();
            });
    
        std::cout << "Min salary:\n";
        (*minEmp)->showInfo();
    
        std::cout << "Max salary:\n";
        (*maxEmp)->showInfo();
    }
    void demoFind() {
        std::vector<std::shared_ptr<Employee>> staff;
    
        staff.push_back(std::make_shared<Employee>("Ivan", 30000));
        staff.push_back(std::make_shared<Employee>("Alex", 50000));
    
        auto it = std::find_if(staff.begin(), staff.end(),
            [](const auto& e) {
                return e->getSalary() > 40000;
            });
    
        if (it != staff.end()) {
            std::cout << "Found high salary employee:\n";
            (*it)->showInfo();
        }
    
        bool hasLowSalary = std::any_of(staff.begin(), staff.end(),
            [](const auto& e) {
                return e->getSalary() < 20000;
            });
    
        std::cout << "Has low salary employee: " << hasLowSalary << "\n";
    }
    void demoList() {
        std::list<int> orders = {100, 200, 50, 400};
    
        orders.remove_if([](int price) {
            return price < 100;
        });
    
        std::cout << "Orders after remove:\n";
        for (int p : orders) {
            std::cout << p << " ";
        }
        std::cout << "\n";
    }
    void demoMap() {
        std::map<int, std::string> tables;
    
        tables[1] = "Free";
        tables[2] = "Occupied";
        tables[3] = "Reserved";
    
        for (const auto& [id, status] : tables) {
            std::cout << "Table " << id << ": " << status << "\n";
        }
    }
    void printPrices(std::span<int> prices) {
        for (int p : prices) {
            std::cout << p << " ";
        }
        std::cout << "\n";
    }
    
    void demoArraySpan() {
        std::array<int, 4> prices = {100, 200, 300, 400};
        printPrices(prices);
    }
    void demoVariant() {
        std::variant<int, std::string> data;
    
        data = 10;
        std::cout << std::get<int>(data) << "\n";
    
        data = "Order paid";
        std::cout << std::get<std::string>(data) << "\n";
    }
    demoVectorEmployees();
    demoSortEmployees();
    demoFind();
    demoList();
    demoMap();
    demoArraySpan();
    demoVariant();
    ReportRepository<SalesReport> salesRepo;

    salesRepo.add(std::make_shared<SalesReport>());
    salesRepo.add(std::make_shared<SalesReport>());

    std::cout << "Sales reports count: " << salesRepo.size() << std::endl;
    salesRepo.printAll();
    }
    // 1. Статическое создание объекта класса
    std::cout << "1. Static object creation:\n";
    std::cout << "----------------------------\n";
    Client client1("Ivan Petrov", "+7-999-123-45-67");
    client1.addVisit();
    client1.updateTotalSpent(1500.0);
    client1.showInfo();
    std::cout << std::endl;

    // 2. Умные указатели: std::unique_ptr
    std::cout << "2. Smart pointers (std::unique_ptr):\n";
    std::cout << "------------------------------------\n";
    {
        std::unique_ptr<Order> order1 = std::make_unique<Order>(101, "2024-01-15 14:30:00");
        order1->addItem(250.0);
        order1->addItem(180.0);
        order1->showInfo();
        // Автоматическое освобождение памяти при выходе из блока
    }
    std::cout << std::endl;

    // 3. Умные указатели: std::shared_ptr
    std::cout << "3. Smart pointers (std::shared_ptr):\n";
    std::cout << "------------------------------------\n";
    {
        std::shared_ptr<Order> order2 = std::make_shared<Order>(102, "2024-01-15 15:00:00");
        order2->addItem(500.0);
        {
            std::shared_ptr<Order> order2Copy = order2; // Разделяемое владение
            order2Copy->addItem(300.0);
            std::cout << "Reference count: " << order2Copy.use_count() << std::endl;
        }
        order2->showInfo();
        std::cout << "Reference count: " << order2.use_count() << std::endl;
    }
    std::cout << std::endl;

    // 4. Конструктор копирования
    std::cout << "4. Copy constructor:\n";
    std::cout << "---------------------\n";
    Client client2("Maria Sidorova", "+7-999-234-56-78");
    client2.addVisit();
    Client client3(client2); // Использование конструктора копирования
    std::cout << "Original client:\n";
    client2.showInfo();
    std::cout << "\nCopied client:\n";
    client3.showInfo();
    std::cout << "Total clients: " << Client::getTotalClients() << std::endl;
    std::cout << std::endl;

    // 5. Перегрузка операторов
    std::cout << "5. Operator overloading:\n";
    std::cout << "-------------------------\n";
    Client client4("Anna Ivanova", "+7-999-345-67-89");
    client4 += 1500.0; // Оператор +=
    Client client5 = client4 + 500.0; // Оператор +
    std::cout << "Client4 after += 1500: " << client4 << std::endl;
    std::cout << "Client5 (Client4 + 500): " << client5 << std::endl;
    std::cout << "client4 == client5: " << (client4 == client5 ? "true" : "false") << std::endl;
    
    Order order3(201, "2024-01-15 16:00:00");
    Order order4(202, "2024-01-15 16:30:00");
    order3 += 100.0;
    order4 += 200.0;
    std::cout << "Order3: " << order3 << std::endl;
    std::cout << "Order4: " << order4 << std::endl;
    std::cout << "order3 < order4: " << (order3 < order4 ? "true" : "false") << std::endl;
    std::cout << std::endl;

    // 6. Работа со строками (конкатенация, поиск)
    std::cout << "6. String operations (concatenation, search):\n";
    std::cout << "----------------------------------------------\n";
    Client client6("Petr Kozlov", "+7-999-456-78-90");
    client6.updateTotalSpent(3000.0);
    std::string fullInfo = client6.getFullInfo();
    std::cout << "Full info (concatenated): " << fullInfo << std::endl;
    std::cout << "Search 'Petr' in name: " << (client6.findInName("Petr") ? "found" : "not found") << std::endl;
    std::cout << "Search 'Koz' in name: " << (client6.findInName("Koz") ? "found" : "not found") << std::endl;
    
    // Дружественная функция для конкатенации
    std::string combined = concatenateClientInfo(client1, client6);
    std::cout << "Combined info: " << combined << std::endl;
    std::cout << std::endl;

    // 7. Статические поля и методы
    std::cout << "7. Static fields and methods:\n";
    std::cout << "------------------------------\n";
    std::cout << "Total clients: " << Client::getTotalClients() << std::endl;
    
    Employee emp1(1, "John Doe", "Waiter", 15.0);
    Employee emp2(2, "Jane Smith", "Chef", 25.0);
    emp1.addHours(40.0);
    emp2.addHours(35.0);
    std::cout << "Total employees: " << Employee::getTotalEmployees() << std::endl;
    std::cout << "Total hours worked: " << Employee::getTotalHoursWorked() << std::endl;
    std::cout << "Average hours: " << Employee::getAverageHours() << std::endl;
    std::cout << std::endl;

    // 8. Наследование (вызов конструктора базового класса)
    std::cout << "8. Inheritance (base class constructor call):\n";
    std::cout << "----------------------------------------------\n";
    VIPClient vip1("VIP User", "+7-999-999-99-99", "Platinum", 20.0);
    vip1.addVisit();
    vip1.updateTotalSpent(5000.0);
    vip1.showInfo();
    std::cout << std::endl;

    // 9. Обработка исключений (try-catch-throw)
    std::cout << "9. Exception handling (try-catch-throw):\n";
    std::cout << "-----------------------------------------\n";
    try {
        Client client7("Test", "+7-999-000-00-00");
        client7.updateTotalSpent(-100.0); // Попытка передать отрицательное значение
        Order order5(-1, "2024-01-15 17:00:00"); // Попытка создать заказ с отрицательным ID
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        Order order6(301, "2024-01-15 18:00:00");
        order6.addItem(100.0);
        order6.removeItem(150.0); // Попытка удалить больше, чем есть
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // 10. Массив умных указателей
    std::cout << "10. Array of smart pointers:\n";
    std::cout << "------------------------------\n";
    std::vector<std::unique_ptr<Order>> orders;
    orders.push_back(std::make_unique<Order>(401, "2024-01-15 19:00:00"));
    orders.push_back(std::make_unique<Order>(402, "2024-01-15 19:30:00"));
    orders.push_back(std::make_unique<Order>(403, "2024-01-15 20:00:00"));
    
    orders[0]->addItem(100.0);
    orders[1]->addItem(200.0);
    orders[2]->addItem(300.0);
    
    for (const auto& order : orders) {
        order->showInfo();
        std::cout << std::endl;
    }
    // Автоматическое освобождение памяти
    std::cout << std::endl;

    // 11. Работа с объектом по ссылке и указателю
    std::cout << "11. Working with references and pointers:\n";
    std::cout << "------------------------------------------\n";
    Client client8("Reference Test", "+7-999-111-11-11");
    Client& clientRef = client8;
    clientRef.addVisit();
    std::cout << "Using reference: " << clientRef << std::endl;
    
    Order order7(501, "2024-01-15 21:00:00");
    Order* orderPtr = &order7;
    orderPtr->addItem(150.0);
    std::cout << "Using pointer: " << *orderPtr << std::endl;
    std::cout << std::endl;

    // 12. Делегирование поведения официанта (стратегия расчёта бонусов)
    std::cout << "12. Waiter serving policy (dynamic configuration):\n";
    std::cout << "--------------------------------------------------\n";
    // Значение можно задать переменной среды WAITER_POLICY=event
    Waiter defaultWaiter(10, "Policy Default", 20.0, 5);
    defaultWaiter.addHours(40);
    defaultWaiter.addTips(200.0);
    defaultWaiter.showInfo();
    std::cout << std::endl;

    // Статическая конфигурация через явную стратегию
    auto eventPolicy = std::make_shared<EventServingPolicy>();
    Waiter eventWaiter(11, "Policy Event", 20.0, eventPolicy, 5);
    eventWaiter.addHours(40);
    eventWaiter.addTips(200.0);
    eventWaiter.showInfo();
    std::cout << std::endl;
    std::cout << "=== Demonstration completed ===\n";
    return 0;
}

