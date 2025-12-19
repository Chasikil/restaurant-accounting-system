public class Table {
    private int tableNumber;
    private int seatsCount;
    private boolean occupied;

    public Table(int tableNumber, int seatsCount) {
        this.tableNumber = tableNumber;
        this.seatsCount = seatsCount;
        this.occupied = false;
    }

    public void occupyTable() {
        this.occupied = true;
        System.out.println("Table " + tableNumber + " is now occupied.");
    }

    public void freeTable() {
        this.occupied = false;
        System.out.println("Table " + tableNumber + " is now free.");
    }

    public boolean isOccupied() {
        return occupied;
    }

    public void showInfo() {
        System.out.println("Table Info:");
        System.out.println("  Table Number: " + tableNumber);
        System.out.println("  Seats Count: " + seatsCount);
        System.out.println("  Occupied: " + occupied);
    }

    public int getTableNumber() {
        return tableNumber;
    }

    public void setTableNumber(int tableNumber) {
        this.tableNumber = tableNumber;
    }

    public int getSeatsCount() {
        return seatsCount;
    }

    public void setSeatsCount(int seatsCount) {
        this.seatsCount = seatsCount;
    }

    public boolean getOccupied() {
        return occupied;
    }

    public void setOccupied(boolean occupied) {
        this.occupied = occupied;
    }
}


