package id.its.pbo;

public class EmployeeProgram {
	
	public static void main(String[] args) {
		
		Employee employee1 = new Employee("Muhammad","Dengklek",6760000);
		Employee employee2 = new Employee("John","Doe",10500000);
		
		System.out.println("Employee Annual salary before raise :");
		System.out.printf("%s %s : %.3f\n",employee1.getFirstName(),employee1.getLastName(),employee1.getYearlySalary());
		System.out.printf("%s %s : %.3f\n",employee2.getFirstName(),employee2.getLastName(),employee2.getYearlySalary());
		System.out.println("\nEmployee Annual salary after 10% raise :");
		
		employee1.raiseSalary(10);
		employee2.raiseSalary(10);
		
		System.out.printf("%s %s : %.3f\n",employee1.getFirstName(),employee1.getLastName(),employee1.getYearlySalary());
		System.out.printf("%s %s : %.3f\n",employee2.getFirstName(),employee2.getLastName(),employee2.getYearlySalary());
		
	}
}