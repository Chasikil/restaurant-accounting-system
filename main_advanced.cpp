// Advanced C++ Features Demonstration
// Inheritance, Virtual Functions, Cloning, Abstract Classes

#include <iostream>
#include <memory>
#include <vector>
#include "Client.hpp"
#include "VIPClient.hpp"
#include "Order.hpp"
#include "Employee.hpp"
#include "Waiter.hpp"
#include "Chef.hpp"
#include "RestaurantEntity.hpp"

int main() {
    std::cout << "=== Advanced C++ Features Demonstration ===\n\n";

    // 1. Демонстрация абстрактного класса и наследования
    std::cout << "1. Abstract class and inheritance:\n";
    std::cout << "------------------------------------\n";
    Client client1("John Doe", "+7-999-111-22-33");
    client1.updateTotalSpent(5000.0);
    std::cout << "Type: " << client1.getType() << std::endl;
    client1.showInfo();
    std::cout << "Value: " << client1.calculateValue() << std::endl;
    std::cout << std::endl;

    // 2. Демонстрация производных классов (Waiter и Chef)
    std::cout << "2. Derived classes (Waiter and Chef):\n";
    std::cout << "--------------------------------------\n";
    Waiter waiter1(1, "Alice", 20.0);
    waiter1.addHours(40.0);
    waiter1.serveTable(5);
    waiter1.addTips(150.0);
    waiter1.showInfo(); // Переопределение с вызовом базового метода
    std::cout << "Employee Type: " << waiter1.getEmployeeType() << std::endl;
    std::cout << std::endl;

    Chef chef1(2, "Bob", 30.0, "Italian");
    chef1.addHours(40.0);
    chef1.prepareDish("Pasta");
    chef1.prepareDish("Pizza");
    chef1.showInfo(); // Переопределение с вызовом базового метода
    std::cout << "Employee Type: " << chef1.getEmployeeType() << std::endl;
    std::cout << std::endl;

    // 3. Демонстрация protected модификатора
    std::cout << "3. Protected modifier demonstration:\n";
    std::cout << "-------------------------------------\n";
    VIPClient vip1("VIP User", "+7-999-999-99-99", "Platinum", 15.0);
    vip1.updateTotalSpent(10000.0);
    // VIPClient имеет доступ к protected полям базового класса Client через наследование
    std::cout << "VIP Client uses protected fields from base class" << std::endl;
    vip1.showInfo(); // Переопределение метода
    std::cout << std::endl;

    // 4. Демонстрация виртуальных функций
    std::cout << "4. Virtual functions demonstration:\n";
    std::cout << "------------------------------------\n";
    
    // Вызов виртуальной функции через невиртуальную функцию базового класса
    std::cout << "Calling virtual function via non-virtual function:\n";
    RestaurantEntity* entity1 = &client1;
    entity1->displayInfo(); // displayInfo вызывает виртуальную showInfo()
    std::cout << std::endl;

    // Вызов через указатели базового и производного классов
    std::cout << "Calling via base class pointer (polymorphism):\n";
    RestaurantEntity* entities[] = {&client1, &vip1};
    for (int i = 0; i < 2; i++) {
        std::cout << "Entity type: " << entities[i]->getType() << std::endl;
        entities[i]->showInfo(); // Виртуальный вызов
        std::cout << std::endl;
    }

    // Демонстрация с Employee и его производными
    std::cout << "Employee polymorphism:\n";
    Employee* employees[] = {&waiter1, &chef1};
    for (int i = 0; i < 2; i++) {
        std::cout << "Employee type: " << employees[i]->getEmployeeType() << std::endl;
        employees[i]->showInfo(); // Виртуальный вызов
        std::cout << std::endl;
    }

    // 5. Демонстрация динамических объектов с виртуальными функциями
    std::cout << "5. Dynamic objects with virtual functions:\n";
    std::cout << "-------------------------------------------\n";
    std::unique_ptr<RestaurantEntity> dynamicClient = std::make_unique<Client>("Dynamic Client", "+7-999-000-00-00");
    std::unique_ptr<RestaurantEntity> dynamicVIP = std::make_unique<VIPClient>("Dynamic VIP", "+7-999-000-00-01", "Gold", 10.0);
    
    dynamicClient->displayInfo();
    dynamicVIP->displayInfo();
    
    // Присваивание указателя базового класса объекту производного класса
    Client* clientPtr = dynamic_cast<Client*>(dynamicClient.get());
    VIPClient* vipPtr = dynamic_cast<VIPClient*>(dynamicVIP.get());
    RestaurantEntity* basePtr = vipPtr; // Присваивание указателя производного класса указателю базового
    basePtr->showInfo(); // Виртуальный вызов
    std::cout << std::endl;

    // 6. Демонстрация клонирования (поверхностное и глубокое)
    std::cout << "6. Cloning demonstration (shallow and deep):\n";
    std::cout << "---------------------------------------------\n";
    Order original(101, "2024-01-15 12:00:00", "Original order notes");
    original.addItem(100.0);
    original.addItem(50.0);
    std::cout << "Original order:\n";
    original.showInfo();
    std::cout << "Original notes: " << original.getNotes() << std::endl;
    std::cout << std::endl;

    // Глубокое клонирование
    Order* deepCopy = original.cloneOrder();
    deepCopy->setNotes("Deep copy notes");
    std::cout << "Deep copy (after modifying notes):\n";
    deepCopy->showInfo();
    std::cout << "Original notes (unchanged): " << original.getNotes() << std::endl;
    std::cout << "Deep copy notes: " << deepCopy->getNotes() << std::endl;
    std::cout << std::endl;

    // Поверхностное клонирование
    Order* shallowCopy = dynamic_cast<Order*>(original.shallowClone());
    if (shallowCopy) {
        shallowCopy->setNotes("Shallow copy notes");
        std::cout << "Shallow copy (after modifying notes):\n";
        shallowCopy->showInfo();
        std::cout << "WARNING: In shallow copy, notes pointer is shared!" << std::endl;
    }
    delete deepCopy;
    delete shallowCopy;
    std::cout << std::endl;

    // 7. Демонстрация вызова конструктора базового класса из производного
    std::cout << "7. Base class constructor call from derived class:\n";
    std::cout << "---------------------------------------------------\n";
    Waiter waiter2(3, "Charlie", 22.0); // Конструктор Waiter вызывает конструктор Employee
    Chef chef2(4, "David", 35.0, "French"); // Конструктор Chef вызывает конструктор Employee
    VIPClient vip2("Another VIP", "+7-999-888-77-66", "Diamond", 20.0); // Конструктор VIPClient вызывает конструктор Client
    std::cout << "All constructors called base class constructors in initialization list\n";
    std::cout << std::endl;

    // 8. Демонстрация оператора присваивания для производных классов
    std::cout << "8. Assignment operator for derived classes:\n";
    std::cout << "--------------------------------------------\n";
    Waiter waiter3(5, "Eve", 25.0);
    Employee baseEmp(6, "Base Employee", "Manager", 40.0);
    waiter3 = baseEmp; // Присваивание объекта базового класса объекту производного класса
    std::cout << "After assigning base Employee to Waiter:\n";
    waiter3.showInfo();
    std::cout << std::endl;

    Client client2("Regular Client", "+7-999-111-11-11");
    VIPClient vip3("VIP Client", "+7-999-222-22-22", "Silver", 5.0);
    vip3 = client2; // Присваивание объекта базового класса объекту производного класса
    std::cout << "After assigning Client to VIPClient:\n";
    vip3.showInfo();
    std::cout << std::endl;

    // 9. Демонстрация запрета конструктора копирования (=delete)
    std::cout << "9. Copy constructor prohibition (=delete):\n";
    std::cout << "-------------------------------------------\n";
    Table table1(1, 4);
    std::cout << "Table created successfully\n";
    // Table table2(table1); // Это вызовет ошибку компиляции - конструктор копирования удален
    std::cout << "Copy constructor is deleted (commented out to allow compilation)\n";
    std::cout << std::endl;

    // 10. Демонстрация виртуального деструктора
    std::cout << "10. Virtual destructor demonstration:\n";
    std::cout << "--------------------------------------\n";
    {
        std::unique_ptr<Employee> empPtr = std::make_unique<Waiter>(7, "Frank", 20.0);
        empPtr->addHours(10.0);
        // При уничтожении будет вызван правильный деструктор благодаря виртуальному деструктору
    }
    std::cout << "Virtual destructor ensures correct cleanup\n";
    std::cout << std::endl;

    // 11. Демонстрация разницы между виртуальной и невиртуальной функцией
    std::cout << "11. Virtual vs non-virtual function:\n";
    std::cout << "-------------------------------------\n";
    Employee* emp1 = new Waiter(8, "Grace", 20.0);
    Employee* emp2 = new Chef(9, "Henry", 30.0, "Asian");
    
    std::cout << "Calling virtual getEmployeeType():\n";
    std::cout << "Employee 1 type: " << emp1->getEmployeeType() << std::endl; // Виртуальный вызов
    std::cout << "Employee 2 type: " << emp2->getEmployeeType() << std::endl; // Виртуальный вызов
    
    delete emp1;
    delete emp2;
    std::cout << std::endl;

    std::cout << "=== Demonstration completed ===\n";
    return 0;
}

