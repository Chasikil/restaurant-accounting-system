public class StandardServingStrategy implements ServingStrategy {
    @Override
    public double computeBonus(double hoursWorked, double hourlyRate, int tablesServed, double tips) {
        return tablesServed * 50.0;
    }

    @Override
    public String getName() {
        return "standard";
    }
}

