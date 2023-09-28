package id.its.pbo;

public class Employee {

	private String firstName;
	private String lastName;
	private double monthlySalary;
	
	//Constructor
	public Employee() {
		this.firstName = "";
		this.lastName = "";
		this.monthlySalary = 0.0;
	}
	public Employee(String newFirstName, String newLastName, double newSalary) {
		this.firstName = newFirstName;
		this.lastName = newLastName;
		this.setMonthlySalary(newSalary);
	}
	
	//Getter Function
	public String getFirstName() {
		return this.firstName;
	}
	
	public String getLastName() {
		return this.lastName;
	}
	
	public double getMonthlySalary() {
		return this.monthlySalary;
	}
	public double getYearlySalary() {
		return this.monthlySalary * 12;
	}
	
	//Setter Function
	public void setMonthlySalary(double newSalary) {
		if(newSalary >= 0.0) this.monthlySalary = newSalary; 
	}
	
	public void raiseSalary(int raisePercentage) {
		double newSalary = this.getMonthlySalary() * (raisePercentage+100)/100.0;
		if(newSalary >= this.getMonthlySalary()) this.setMonthlySalary(newSalary);
	}
}
