public class Employee {
    private String name;
    private String position;
    private double hoursWorked;
    private double hourlyRate;

    public Employee(String name, String position, double hourlyRate) {
        this.name = name;
        this.position = position;
        this.hoursWorked = 0.0;
        this.hourlyRate = hourlyRate;
    }

    public double calculateSalary() {
        double salary = hoursWorked * hourlyRate;
        System.out.println("Calculated salary for " + name + ": " + salary);
        return salary;
    }

    public void addHours(double hours) {
        this.hoursWorked += hours;
        System.out.println("Added " + hours + " hours. Total hours worked: " + hoursWorked);
    }

    public void showInfo() {
        System.out.println("Employee Info:");
        System.out.println("  Name: " + name);
        System.out.println("  Position: " + position);
        System.out.println("  Hours Worked: " + hoursWorked);
        System.out.println("  Hourly Rate: " + hourlyRate);
        System.out.println("  Salary: " + (hoursWorked * hourlyRate));
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


