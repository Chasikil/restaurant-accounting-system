public class Order {
    private String orderId;
    private double totalAmount;
    private String orderTime;
    private String employeeName;

    public Order(String orderId, String orderTime, String employeeName) {
        this.orderId = orderId;
        this.totalAmount = 0.0;
        this.orderTime = orderTime;
        this.employeeName = employeeName;
    }

    public void addAmount(double amount) {
        this.totalAmount += amount;
        System.out.println("Added " + amount + " to order. New total: " + totalAmount);
    }

    public void resetAmount() {
        this.totalAmount = 0.0;
        System.out.println("Order amount reset to 0.0");
    }

    public void showInfo() {
        System.out.println("Order Info:");
        System.out.println("  Order ID: " + orderId);
        System.out.println("  Total Amount: " + totalAmount);
        System.out.println("  Order Time: " + orderTime);
        System.out.println("  Employee Name: " + employeeName);
    }

    public String getOrderId() {
        return orderId;
    }

    public void setOrderId(String orderId) {
        this.orderId = orderId;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public void setTotalAmount(double totalAmount) {
        this.totalAmount = totalAmount;
    }

    public String getOrderTime() {
        return orderTime;
    }

    public void setOrderTime(String orderTime) {
        this.orderTime = orderTime;
    }

    public String getEmployeeName() {
        return employeeName;
    }

    public void setEmployeeName(String employeeName) {
        this.employeeName = employeeName;
    }
}


