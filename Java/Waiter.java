// Производный класс Waiter наследуется от Employee и реализует множественное наследование
// (от абстрактного класса Employee и интерфейсов Payable, Displayable)
public class Waiter extends Employee {
    private int tablesServed;
    private double tips;

    public Waiter(String name, double hourlyRate, int tablesServed) {
        super(name, "Waiter", hourlyRate); // Вызов конструктора базового класса
        this.tablesServed = tablesServed;
        this.tips = 0.0;
    }

    public Waiter(String name, double hourlyRate) {
        this(name, hourlyRate, 0);
    }

    // Переопределение метода базового класса с вызовом базового метода
    @Override
    public void showInfo() {
        super.showInfo(); // Вызов метода базового класса
        System.out.println("  Tables Served: " + tablesServed);
        System.out.println("  Tips: " + tips);
        System.out.println("  Total Earnings: " + (calculateSalary() + tips));
    }

    // Переопределение метода без вызова базового метода
    @Override
    public double calculateSalary() {
        // Официанты получают базовую зарплату плюс бонус за обслуженные столы
        double baseSalary = hoursWorked * hourlyRate;
        double bonus = tablesServed * 50.0; // Бонус 50 за стол
        return baseSalary + bonus;
    }

    @Override
    public String getEmployeeType() {
        return "Waiter";
    }

    // Новые методы
    public void serveTable(int tableNumber) {
        tablesServed++;
    }

    public void addTips(double amount) {
        if (amount > 0.0) {
            tips += amount;
        }
    }

    public int getTablesServed() {
        return tablesServed;
    }

    public double getTips() {
        return tips;
    }

    // Переопределение метода интерфейса Payable
    @Override
    public double getAmount() {
        return calculateSalary() + tips;
    }

    @Override
    public String getPaymentInfo() {
        return "Waiter " + name + " total earnings: " + getAmount() + " (salary: " + 
               calculateSalary() + ", tips: " + tips + ")";
    }
}

