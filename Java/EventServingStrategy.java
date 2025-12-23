public class EventServingStrategy implements ServingStrategy {
    @Override
    public double computeBonus(double hoursWorked, double hourlyRate, int tablesServed, double tips) {
        return tablesServed * 80.0 + tips * 0.05;
    }

    @Override
    public String getName() {
        return "event";
    }
}

