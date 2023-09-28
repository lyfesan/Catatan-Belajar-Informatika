package id.its.pbo;
import java.util.Scanner;

public class DateProgram {

	//Input/change date
	public static Date inputDate(Scanner scan, Date date) {
		
		System.out.print("Enter month(1-12) : ");
		int month = scan.nextInt();
		
		System.out.print("Enter day(1-31) : ");
		int day = scan.nextInt();
		
		System.out.print("Enter year(greater than equal 0) : ");
		int year = scan.nextInt();
		
		date.changeDate(month, day, year);
		
		return date;
	}
	
	//Program capabilities
	public static void dateShowChange(Scanner scan, Date date) {
		while(true) {
			System.out.print("1. Display saved date\n2. Change date\n3. Exit\nEnter choice: ");
			int c = scan.nextInt();
			if(c==1) {
				System.out.println(date.displayDate());
			}
			else if(c==2) {
				date = inputDate(scan, date);
			}
			else if(c==3) break;
			else System.out.println("Invalid input");
		}
		
	}
	
	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		
		System.out.println("Date Program");
		
		Date dateCurrent = new Date();
		
		dateCurrent = inputDate(scan, dateCurrent);
		dateShowChange(scan,dateCurrent);

		scan.close();
	}

}
