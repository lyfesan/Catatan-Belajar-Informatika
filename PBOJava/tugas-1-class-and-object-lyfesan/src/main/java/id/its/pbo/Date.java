package id.its.pbo;

public class Date {
	
	private int month,day,year;
	
	//Constructor
	public Date() {
		this.month = 1;
		this.day = 1;
		this.year = 0;
	}
	
	public Date(int newMonth, int newDay, int newYear) {
		this.setDay(newDay);
		this.setMonth(newMonth);
		this.setYear(newYear);
		dateValidation();
	}
	
	//Private methods
	//Setter function
	private void setDay(int newDay) {
		if(newDay > 0 && newDay < 32) this.day = newDay;
		else this.day = 1;
	}
	
	private void setMonth(int newMonth) {
		if(newMonth > 0 && newMonth < 13) this.month = newMonth;
		else this.month = 1;
	}
	
	private void setYear(int newYear) {
		this.year = newYear >= 0 ? newYear : 0;
	}
	
	//Date Validation Process
	private Boolean isLeapYear() {
		return this.getYear()%4==0 && this.getYear()%100!=0 || this.getYear()%400==0;
	}
	
	private void dateValidation() {
		
		//Condition to determine if the month until day 31 or not
		if(this.getMonth()%2==0 && this.getMonth()<8 || this.getMonth()%2==1 && this.getMonth()>=8) {
			if(this.getDay()>30) this.setDay(1);
		}
		
		//Check Leap year day validation
		if(this.isLeapYear() && this.getMonth()!=2 && this.getDay()>28 || !this.isLeapYear() && this.getDay()>28) this.setDay(1);
	}
	
	//Change the date
	public void changeDate(int newMonth, int newDay, int newYear) {
		this.setDay(newDay);
		this.setMonth(newMonth);
		this.setYear(newYear);
		dateValidation();
	}
	
	//Getter function
	public int getDay() {
		return this.day;
	}
	
	public int getMonth() {
		return this.month;
	}
	
	public int getYear() {
		return this.year;
	}
	
	//Display Formatted Date
	public String displayDate() {
		return (getMonth() + "/" + getDay() + "/" + getYear());
	}
}