// Производный класс Waiter наследуется от Employee и реализует множественное наследование
// (от абстрактного класса Employee и интерфейсов Payable, Displayable)
public class Waiter extends Employee {
    private int tablesServed;
    private double tips;
    private ServingStrategy servingStrategy;

    public Waiter(String name, double hourlyRate, int tablesServed) {
        this(name, hourlyRate, tablesServed, resolveStrategy());
    }

    public Waiter(String name, double hourlyRate, int tablesServed, ServingStrategy strategy) {
        super(name, "Waiter", hourlyRate); // Вызов конструктора базового класса
        this.tablesServed = tablesServed;
        this.tips = 0.0;
        this.servingStrategy = strategy != null ? strategy : resolveStrategy();
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
        System.out.println("  Serving strategy: " + (servingStrategy != null ? servingStrategy.getName() : "none"));
        System.out.println("  Total Earnings: " + (calculateSalary() + tips));
    }

    // Переопределение метода без вызова базового метода
    @Override
    public double calculateSalary() {
        // Официанты получают базовую зарплату плюс бонус за обслуженные столы
        double baseSalary = hoursWorked * hourlyRate;
        double bonus = servingStrategy != null
                ? servingStrategy.computeBonus(hoursWorked, hourlyRate, tablesServed, tips)
                : tablesServed * 50.0; // Бонус 50 за стол
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

    public void setServingStrategy(ServingStrategy servingStrategy) {
        this.servingStrategy = servingStrategy;
    }

    public String getServingStrategyName() {
        return servingStrategy != null ? servingStrategy.getName() : "none";
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

    private static ServingStrategy resolveStrategy() {
        String mode = System.getProperty("waiter.mode");
        if (mode == null || mode.isEmpty()) {
            mode = System.getenv("WAITER_MODE");
        }
        if ("event".equalsIgnoreCase(mode)) {
            return new EventServingStrategy();
        }
        return new StandardServingStrategy();
    }
}

