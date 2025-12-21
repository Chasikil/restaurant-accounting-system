// Производный класс Chef наследуется от Employee и реализует множественное наследование
// (от абстрактного класса Employee и интерфейсов Payable, Displayable)
public class Chef extends Employee {
    private int dishesPrepared;
    private String specialty;

    public Chef(String name, double hourlyRate, String specialty, int dishesPrepared) {
        super(name, "Chef", hourlyRate); // Вызов конструктора базового класса
        this.dishesPrepared = dishesPrepared;
        this.specialty = specialty;
    }

    public Chef(String name, double hourlyRate, String specialty) {
        this(name, hourlyRate, specialty, 0);
    }

    // Переопределение метода базового класса с вызовом базового метода
    @Override
    public void showInfo() {
        super.showInfo(); // Вызов метода базового класса
        System.out.println("  Specialty: " + specialty);
        System.out.println("  Dishes Prepared: " + dishesPrepared);
    }

    // Переопределение метода без вызова базового метода
    @Override
    public double calculateSalary() {
        // Повара получают базовую зарплату плюс бонус за блюда
        double baseSalary = hoursWorked * hourlyRate;
        double bonus = dishesPrepared * 10.0; // Бонус 10 за блюдо
        return baseSalary + bonus;
    }

    @Override
    public String getEmployeeType() {
        return "Chef";
    }

    // Новые методы
    public void prepareDish(String dishName) {
        dishesPrepared++;
    }

    public int getDishesPrepared() {
        return dishesPrepared;
    }

    public String getSpecialty() {
        return specialty;
    }

    // Переопределение метода интерфейса Payable
    @Override
    public String getPaymentInfo() {
        return "Chef " + name + " salary: " + calculateSalary() + " (specialty: " + specialty + ")";
    }
}

