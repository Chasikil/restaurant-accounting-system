public class Main {
    public static void main(String[] args) {
        System.out.println("=== Лабораторная работа №3: Демонстрация работы классов ===\n");

        // Создание и работа с объектом Client
        System.out.println("--- Работа с классом Client ---");
        Client client1 = new Client("Иван Петров", "+7-999-123-45-67");
        client1.showInfo();
        client1.addVisit();
        client1.updateTotalSpent(3500.0);
        client1.addVisit();
        client1.updateTotalSpent(2500.0);
        System.out.println("После обновления:");
        client1.showInfo();
        System.out.println();

        // Создание и работа с объектом Reservation
        System.out.println("--- Работа с классом Reservation ---");
        Reservation reservation1 = new Reservation("RES-001", "Иван Петров", 5, "19:00", 4);
        reservation1.showInfo();
        reservation1.changeTime("20:00");
        reservation1.changeGuestCount(5);
        System.out.println("Обновленная информация:");
        reservation1.showInfo();
        System.out.println();

        // Создание и работа с объектом Table
        System.out.println("--- Работа с классом Table ---");
        Table table1 = new Table(5, 4);
        table1.showInfo();
        table1.occupyTable();
        System.out.println("Статус занятости: " + table1.isOccupied());
        table1.freeTable();
        table1.showInfo();
        System.out.println();

        // Создание и работа с объектом Order
        System.out.println("--- Работа с классом Order ---");
        Order order1 = new Order("ORD-001", "19:30", "Анна Смирнова");
        order1.showInfo();
        order1.addAmount(1500.0);
        order1.addAmount(800.0);
        order1.addAmount(200.0);
        System.out.println("Итоговая сумма заказа: " + order1.getTotalAmount());
        order1.showInfo();
        System.out.println();

        // Создание и работа с объектом Employee
        System.out.println("--- Работа с классом Employee ---");
        Employee employee1 = new Employee("Анна Смирнова", "Официант", 500.0);
        employee1.showInfo();
        employee1.addHours(4.5);
        employee1.addHours(3.5);
        double salary = employee1.calculateSalary();
        employee1.showInfo();
        System.out.println();

        // Создание и работа с объектом Shift
        System.out.println("--- Работа с классом Shift ---");
        Shift shift1 = new Shift("SHIFT-001", "Анна Смирнова", "10:00", "18:00");
        shift1.showInfo();
        int duration = shift1.getShiftDuration();
        System.out.println("Продолжительность смены: " + duration + " часов");
        System.out.println();

        // Создание и работа с объектом Report
        System.out.println("--- Работа с классом Report ---");
        Report report1 = new Report("Отчет за день", "2024-01-15", 12500.0);
        report1.showInfo();
        report1.generateReport();
        System.out.println();

        System.out.println("=== Демонстрация завершена ===");
    }
}

