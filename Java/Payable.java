// Интерфейс для объектов, которые можно оплатить
public interface Payable {
    double getAmount();
    void processPayment();
    String getPaymentInfo();
}

