// Client наследуется от абстрактного класса RestaurantEntity и реализует интерфейсы
public class Client extends RestaurantEntity implements Payable, Displayable {
    private String phone;
    protected int visitsCount; // protected для доступа из производных классов
    protected double totalSpent;
    protected String status;
    private static int totalClients = 0;

    public Client(String name, String phone) {
        super(totalClients + 1, name); // Вызов конструктора базового класса
        this.phone = phone;
        this.visitsCount = 0;
        this.totalSpent = 0.0;
        this.status = "Bronze";
        totalClients++;
        this.entityId = totalClients; // Обновляем ID после увеличения счетчика
    }

    public void addVisit() {
        visitsCount++;
        determineStatus();
    }

    public void updateTotalSpent(double amount) {
        totalSpent += amount;
        determineStatus();
    }

    public void determineStatus() {
        if (totalSpent >= 10000.0 || visitsCount >= 50) {
            status = "Gold";
        } else if (totalSpent >= 5000.0 || visitsCount >= 20) {
            status = "Silver";
        } else {
            status = "Bronze";
        }
    }

    // Переопределение абстрактных методов из базового класса
    @Override
    public void showInfo() {
        System.out.println("Client Info:");
        System.out.println("  ID: " + entityId);
        System.out.println("  Name: " + name);
        System.out.println("  Phone: " + phone);
        System.out.println("  Visits: " + visitsCount);
        System.out.println("  Total Spent: " + totalSpent);
        System.out.println("  Status: " + status);
    }

    @Override
    public String getType() {
        return "Client";
    }

    @Override
    public double calculateValue() {
        return totalSpent;
    }

    // Реализация интерфейса Payable
    @Override
    public double getAmount() {
        return totalSpent;
    }

    @Override
    public void processPayment() {
        System.out.println("Processing payment for client: " + name);
    }

    @Override
    public String getPaymentInfo() {
        return "Client " + name + " has spent: " + totalSpent;
    }

    // Реализация интерфейса Displayable
    @Override
    public void display() {
        showInfo();
    }

    @Override
    public String getDisplayString() {
        return "Client: " + name + " (" + phone + ") - " + status;
    }

    // Геттеры
    public String getPhone() {
        return phone;
    }

    public static int getTotalClients() {
        return totalClients;
    }
}

