// Абстрактный базовый класс для всех сущностей ресторана
public abstract class RestaurantEntity {
    protected int entityId;
    protected String name;

    public RestaurantEntity(int id, String name) {
        this.entityId = id;
        this.name = name;
    }

    // Абстрактные методы (должны быть реализованы в производных классах)
    public abstract void showInfo();
    public abstract String getType();

    // Виртуальный метод с реализацией по умолчанию
    public double calculateValue() {
        return 0.0;
    }

    // Невиртуальный метод, который вызывает виртуальный
    public void displayInfo() {
        System.out.println("Displaying info via non-virtual function:");
        showInfo(); // Вызов абстрактного метода
    }

    // Геттеры
    public int getId() {
        return entityId;
    }

    public String getName() {
        return name;
    }
}

