// Order реализует интерфейс Cloneable для демонстрации клонирования
public class Order implements Cloneable, Payable, Displayable {
    private String orderId;
    private double totalAmount;
    private String orderTime;
    private String employeeName;
    private String notes; // Для демонстрации глубокого клонирования

    public Order(String orderId, String orderTime, String employeeName) {
        this.orderId = orderId;
        this.totalAmount = 0.0;
        this.orderTime = orderTime;
        this.employeeName = employeeName;
        this.notes = "";
    }

    public Order(String orderId, String orderTime, String employeeName, String notes) {
        this.orderId = orderId;
        this.totalAmount = 0.0;
        this.orderTime = orderTime;
        this.employeeName = employeeName;
        this.notes = notes;
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

    public String getNotes() {
        return notes;
    }

    public void setNotes(String notes) {
        this.notes = notes;
    }

    // Реализация интерфейса Cloneable - глубокое клонирование
    @Override
    public Object clone() {
        // Глубокое клонирование - создаем новый объект с копированием всех данных
        return new Order(this.orderId, this.orderTime, this.employeeName, this.notes);
    }

    // Поверхностное клонирование
    public Object shallowClone() {
        // Поверхностное клонирование - в Java для объектов String это аналогично глубокому,
        // но для демонстрации концепции создаем новый объект
        Order shallow = new Order(this.orderId, this.orderTime, this.employeeName, this.notes);
        shallow.totalAmount = this.totalAmount;
        return shallow;
    }

    // Реализация интерфейса Payable
    @Override
    public double getAmount() {
        return totalAmount;
    }

    @Override
    public void processPayment() {
        System.out.println("Processing payment for order: " + orderId);
    }

    @Override
    public String getPaymentInfo() {
        return "Order " + orderId + " total: " + totalAmount;
    }

    // Реализация интерфейса Displayable
    @Override
    public void display() {
        showInfo();
    }

    @Override
    public String getDisplayString() {
        return "Order: " + orderId + " - Amount: " + totalAmount;
    }
}


