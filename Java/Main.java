// Advanced Java Features Demonstration
// Inheritance, Abstract Classes, Interfaces, Multiple Inheritance, Cloning

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Advanced Java Features Demonstration ===\n");

        // 1. Демонстрация абстрактного класса и наследования
        System.out.println("1. Abstract class and inheritance:\n");
        System.out.println("------------------------------------");
        Client client1 = new Client("John Doe", "+7-999-111-22-33");
        client1.updateTotalSpent(5000.0);
        System.out.println("Type: " + client1.getType());
        client1.showInfo();
        System.out.println("Value: " + client1.calculateValue());
        System.out.println();

        // 2. Демонстрация производных классов (Waiter и Chef)
        System.out.println("2. Derived classes (Waiter and Chef):\n");
        System.out.println("--------------------------------------");
        Waiter waiter1 = new Waiter("Alice", 20.0);
        waiter1.addHours(40.0);
        waiter1.serveTable(5);
        waiter1.addTips(150.0);
        waiter1.showInfo(); // Переопределение с вызовом базового метода
        System.out.println("Employee Type: " + waiter1.getEmployeeType());
        System.out.println();

        Chef chef1 = new Chef("Bob", 30.0, "Italian");
        chef1.addHours(40.0);
        chef1.prepareDish("Pasta");
        chef1.prepareDish("Pizza");
        chef1.showInfo(); // Переопределение с вызовом базового метода
        System.out.println("Employee Type: " + chef1.getEmployeeType());
        System.out.println();

        // 3. Демонстрация protected модификатора
        System.out.println("3. Protected modifier demonstration:\n");
        System.out.println("------------------------------------");
        VIPClient vip1 = new VIPClient("VIP User", "+7-999-999-99-99", "Platinum", 15.0);
        vip1.updateTotalSpent(10000.0);
        // VIPClient имеет доступ к protected полям базового класса Client через наследование
        System.out.println("VIP Client uses protected fields from base class");
        vip1.showInfo(); // Переопределение метода
        System.out.println();

        // 4. Демонстрация виртуальных методов (в Java все методы виртуальные по умолчанию)
        System.out.println("4. Virtual methods demonstration (all methods are virtual in Java):\n");
        System.out.println("------------------------------------");
        
        // Вызов через невиртуальную функцию базового класса
        System.out.println("Calling virtual method via non-virtual function:");
        RestaurantEntity entity1 = client1;
        entity1.displayInfo(); // displayInfo вызывает виртуальный showInfo()
        System.out.println();

        // Вызов через ссылки базового и производного классов (полиморфизм)
        System.out.println("Calling via base class reference (polymorphism):");
        RestaurantEntity[] entities = {client1, vip1};
        for (RestaurantEntity entity : entities) {
            System.out.println("Entity type: " + entity.getType());
            entity.showInfo(); // Виртуальный вызов
            System.out.println();
        }

        // Демонстрация с Employee и его производными
        System.out.println("Employee polymorphism:");
        Employee[] employees = {waiter1, chef1};
        for (Employee emp : employees) {
            System.out.println("Employee type: " + emp.getEmployeeType());
            emp.showInfo(); // Виртуальный вызов
            System.out.println();
        }

        // 5. Демонстрация клонирования (поверхностное и глубокое)
        System.out.println("5. Cloning demonstration (shallow and deep):\n");
        System.out.println("--------------------------------------------");
        Order original = new Order("ORD-001", "2024-01-15 12:00:00", "Alice", "Original order notes");
        original.addAmount(100.0);
        original.addAmount(50.0);
        System.out.println("Original order:");
        original.showInfo();
        System.out.println("Original notes: " + original.getNotes());
        System.out.println();

        // Глубокое клонирование
        Order deepCopy = (Order) original.clone();
        deepCopy.setNotes("Deep copy notes");
        System.out.println("Deep copy (after modifying notes):");
        deepCopy.showInfo();
        System.out.println("Original notes (unchanged): " + original.getNotes());
        System.out.println("Deep copy notes: " + deepCopy.getNotes());
        System.out.println();

        // Поверхностное клонирование
        Order shallowCopy = (Order) original.shallowClone();
        System.out.println("Shallow copy:");
        shallowCopy.showInfo();
        System.out.println();

        // 6. Демонстрация вызова конструктора базового класса из производного
        System.out.println("6. Base class constructor call from derived class:\n");
        System.out.println("---------------------------------------------------");
        Waiter waiter2 = new Waiter("Charlie", 22.0); // Конструктор Waiter вызывает конструктор Employee
        Chef chef2 = new Chef("David", 35.0, "French"); // Конструктор Chef вызывает конструктор Employee
        VIPClient vip2 = new VIPClient("Another VIP", "+7-999-888-77-66", "Diamond", 20.0); // Конструктор VIPClient вызывает конструктор Client
        System.out.println("All constructors called base class constructors via super()");
        System.out.println();

        // 7. Демонстрация интерфейсов
        System.out.println("7. Interfaces demonstration:\n");
        System.out.println("--------------------------------------------");
        System.out.println("Client implements Payable and Displayable:");
        System.out.println("Payment info: " + client1.getPaymentInfo());
        System.out.println("Display string: " + client1.getDisplayString());
        client1.processPayment();
        System.out.println();

        System.out.println("Waiter implements Payable and Displayable:");
        System.out.println("Payment info: " + waiter1.getPaymentInfo());
        System.out.println("Display string: " + waiter1.getDisplayString());
        waiter1.processPayment();
        System.out.println();

        System.out.println("Order implements Cloneable, Payable and Displayable:");
        System.out.println("Payment info: " + original.getPaymentInfo());
        System.out.println("Display string: " + original.getDisplayString());
        original.processPayment();
        System.out.println();

        // 8. Демонстрация множественного наследования (класс + интерфейсы)
        System.out.println("8. Multiple inheritance demonstration (class + interfaces):\n");
        System.out.println("-------------------------------------------------------------");
        System.out.println("Waiter extends Employee (abstract class) and implements Payable, Displayable:");
        System.out.println("  - Inherits from Employee");
        System.out.println("  - Implements Payable interface");
        System.out.println("  - Implements Displayable interface");
        System.out.println("Employee type: " + waiter1.getEmployeeType());
        System.out.println("Amount: " + waiter1.getAmount());
        waiter1.display();
        System.out.println();

        System.out.println("VIPClient extends Client (which extends RestaurantEntity) and implements Payable, Displayable:");
        System.out.println("  - Inherits from Client -> RestaurantEntity");
        System.out.println("  - Implements Payable interface");
        System.out.println("  - Implements Displayable interface");
        System.out.println("Type: " + vip1.getType());
        System.out.println("Amount: " + vip1.getAmount());
        vip1.display();
        System.out.println();

        // 9. Демонстрация работы с массивами полиморфных объектов
        System.out.println("9. Working with polymorphic arrays:\n");
        System.out.println("------------------------------------");
        Payable[] payables = {client1, waiter1, chef1, original};
        System.out.println("Processing payments for all payable objects:");
        for (Payable payable : payables) {
            System.out.println("  " + payable.getPaymentInfo());
            payable.processPayment();
        }
        System.out.println();

        Displayable[] displayables = {client1, waiter1, chef1, original, vip1};
        System.out.println("Displaying all displayable objects:");
        for (Displayable displayable : displayables) {
            System.out.println("  " + displayable.getDisplayString());
        }
        System.out.println();

        System.out.println("=== Demonstration completed ===");
    }
}
