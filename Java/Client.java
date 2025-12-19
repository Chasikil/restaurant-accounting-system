public class Client {
    private String name;
    private String phone;
    private int visitsCount;
    private double totalSpent;
    private String status;

    public Client(String name, String phone) {
        this.name = name;
        this.phone = phone;
        this.visitsCount = 0;
        this.totalSpent = 0.0;
        this.status = "Bronze";
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

    public void showInfo() {
        System.out.println("Client Info:");
        System.out.println("  Name: " + name);
        System.out.println("  Phone: " + phone);
        System.out.println("  Visits: " + visitsCount);
        System.out.println("  Total Spent: " + totalSpent);
        System.out.println("  Status: " + status);
    }
}

