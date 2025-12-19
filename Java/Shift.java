public class Shift {
    private String shiftId;
    private String employeeName;
    private String startTime;
    private String endTime;

    public Shift(String shiftId, String employeeName, String startTime, String endTime) {
        this.shiftId = shiftId;
        this.employeeName = employeeName;
        this.startTime = startTime;
        this.endTime = endTime;
    }

    public int getShiftDuration() {
        System.out.println("Calculating shift duration from " + startTime + " to " + endTime);
        System.out.println("Shift duration calculated (demo: returning 8 hours)");
        return 8;
    }

    public void showInfo() {
        System.out.println("Shift Info:");
        System.out.println("  Shift ID: " + shiftId);
        System.out.println("  Employee Name: " + employeeName);
        System.out.println("  Start Time: " + startTime);
        System.out.println("  End Time: " + endTime);
        int duration = getShiftDuration();
        System.out.println("  Duration: " + duration + " hours");
    }

    public String getShiftId() {
        return shiftId;
    }

    public void setShiftId(String shiftId) {
        this.shiftId = shiftId;
    }

    public String getEmployeeName() {
        return employeeName;
    }

    public void setEmployeeName(String employeeName) {
        this.employeeName = employeeName;
    }

    public String getStartTime() {
        return startTime;
    }

    public void setStartTime(String startTime) {
        this.startTime = startTime;
    }

    public String getEndTime() {
        return endTime;
    }

    public void setEndTime(String endTime) {
        this.endTime = endTime;
    }
}

