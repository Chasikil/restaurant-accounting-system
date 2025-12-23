public interface ServingStrategy {
    double computeBonus(double hoursWorked, double hourlyRate, int tablesServed, double tips);
    String getName();
}

