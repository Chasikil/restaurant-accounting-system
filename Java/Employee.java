// Абстрактный класс Employee с protected полями для наследования
public abstract class Employee implements Payable, Displayable {
    protected String name;
    protected String position;
    protected double hoursWorked;
    protected double hourlyRate;
    protected static int totalEmployees = 0;
    protected static double totalHoursWorked = 0.0;

    public Employee(String name, String position, double hourlyRate) {
        this.name = name;
        this.position = position;
        this.hoursWorked = 0.0;
        this.hourlyRate = hourlyRate;
        totalEmployees++;
    }

    // Виртуальный метод (может быть переопределен в производных классах)
    public double calculateSalary() {
        return hoursWorked * hourlyRate;
    }

    // Абстрактный метод (должен быть реализован в производных классах)
    public abstract String getEmployeeType();

    public void addHours(double hours) {
        this.hoursWorked += hours;
        System.out.println("Added " + hours + " hours. Total hours worked: " + hoursWorked);
    }

    // Виртуальный метод (может быть переопределен в производных классах)
    public void showInfo() {
        System.out.println("Employee Info:");
        System.out.println("  Name: " + name);
        System.out.println("  Position: " + position);
        System.out.println("  Hours Worked: " + hoursWorked);
        System.out.println("  Hourly Rate: " + hourlyRate);
        System.out.println("  Salary: " + calculateSalary());
    }

    // Реализация интерфейса Payable
    @Override
    public double getAmount() {
        return calculateSalary();
    }

    @Override
    public void processPayment() {
        System.out.println("Processing salary payment for employee: " + name);
    }

    @Override
    public String getPaymentInfo() {
        return "Employee " + name + " salary: " + calculateSalary();
    }

    // Реализация интерфейса Displayable
    @Override
    public void display() {
        showInfo();
    }

    @Override
    public String getDisplayString() {
        return "Employee: " + name + " - " + position;
    }

    // Статические методы
    public static int getTotalEmployees() {
        return totalEmployees;
    }

    public static double getTotalHoursWorked() {
        return totalHoursWorked;
    }

    public static double getAverageHours() {
        return totalEmployees > 0 ? totalHoursWorked / totalEmployees : 0.0;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public double getHoursWorked() {
        return hoursWorked;
    }

    public void setHoursWorked(double hoursWorked) {
        this.hoursWorked = hoursWorked;
    }

    public double getHourlyRate() {
        return hourlyRate;
    }

    public void setHourlyRate(double hourlyRate) {
        this.hourlyRate = hourlyRate;
    }
}


