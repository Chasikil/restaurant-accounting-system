// Производный класс VIPClient наследуется от Client и реализует множественное наследование
// (от класса Client, который наследуется от RestaurantEntity, и интерфейсов Payable, Displayable)
public class VIPClient extends Client {
    private String vipLevel;
    private double discount;

    public VIPClient(String name, String phone, String vipLevel, double discount) {
        super(name, phone); // Вызов конструктора базового класса Client
        this.vipLevel = vipLevel;
        this.discount = discount;
        // VIP клиенты сразу получают статус Gold
        this.status = "Gold";
    }

    // Переопределение метода базового класса с вызовом базового метода
    @Override
    public void showInfo() {
        super.showInfo(); // Вызов метода базового класса Client
        System.out.println("  VIP Level: " + vipLevel);
        System.out.println("  Discount: " + discount + "%");
        System.out.println("  Discounted Total: " + calculateValue());
    }

    @Override
    public String getType() {
        return "VIPClient";
    }

    @Override
    public double calculateValue() {
        return totalSpent * (1.0 - discount / 100.0);
    }

    // Переопределение метода интерфейса Payable
    @Override
    public double getAmount() {
        return calculateValue(); // С учетом скидки
    }

    @Override
    public String getPaymentInfo() {
        return "VIP Client " + getName() + " discounted total: " + calculateValue() + 
               " (original: " + totalSpent + ", discount: " + discount + "%)";
    }

    // Новые методы
    public void setVipLevel(String level) {
        this.vipLevel = level;
    }

    public String getVipLevel() {
        return vipLevel;
    }

    public double getDiscount() {
        return discount;
    }
}

