public class Reservation {
    private String reservationId;
    private String clientName;
    private int tableNumber;
    private String reservationTime;
    private int guestCount;

    public Reservation(String reservationId, String clientName, int tableNumber, String reservationTime, int guestCount) {
        this.reservationId = reservationId;
        this.clientName = clientName;
        this.tableNumber = tableNumber;
        this.reservationTime = reservationTime;
        this.guestCount = guestCount;
    }

    public void showInfo() {
        System.out.println("Reservation Info:");
        System.out.println("  Reservation ID: " + reservationId);
        System.out.println("  Client Name: " + clientName);
        System.out.println("  Table Number: " + tableNumber);
        System.out.println("  Reservation Time: " + reservationTime);
        System.out.println("  Guest Count: " + guestCount);
    }

    public void changeTime(String newTime) {
        this.reservationTime = newTime;
        System.out.println("Reservation time changed to: " + newTime);
    }

    public void changeGuestCount(int newCount) {
        this.guestCount = newCount;
        System.out.println("Guest count changed to: " + newCount);
    }

    public String getReservationId() {
        return reservationId;
    }

    public void setReservationId(String reservationId) {
        this.reservationId = reservationId;
    }

    public String getClientName() {
        return clientName;
    }

    public void setClientName(String clientName) {
        this.clientName = clientName;
    }

    public int getTableNumber() {
        return tableNumber;
    }

    public void setTableNumber(int tableNumber) {
        this.tableNumber = tableNumber;
    }

    public String getReservationTime() {
        return reservationTime;
    }

    public void setReservationTime(String reservationTime) {
        this.reservationTime = reservationTime;
    }

    public int getGuestCount() {
        return guestCount;
    }

    public void setGuestCount(int guestCount) {
        this.guestCount = guestCount;
    }
}


