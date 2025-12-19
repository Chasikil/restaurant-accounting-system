public class Report {
    private String reportName;
    private String period;
    private double totalAmount;

    public Report(String reportName, String period, double totalAmount) {
        this.reportName = reportName;
        this.period = period;
        this.totalAmount = totalAmount;
    }

    public void generateReport() {
        System.out.println("Generating report: " + reportName);
        System.out.println("Period: " + period);
        System.out.println("Total Amount: " + totalAmount);
        System.out.println("Report generated successfully.");
    }

    public void showInfo() {
        System.out.println("Report Info:");
        System.out.println("  Report Name: " + reportName);
        System.out.println("  Period: " + period);
        System.out.println("  Total Amount: " + totalAmount);
    }

    public String getReportName() {
        return reportName;
    }

    public void setReportName(String reportName) {
        this.reportName = reportName;
    }

    public String getPeriod() {
        return period;
    }

    public void setPeriod(String period) {
        this.period = period;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public void setTotalAmount(double totalAmount) {
        this.totalAmount = totalAmount;
    }
}


