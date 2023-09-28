package id.its.pbo;

public class InvoiceProgram {
	
	public static void main(String[] args) {
		Invoice invoice1 = new Invoice("012345", "This is part", 50, 150.10);
		Invoice invoice2 = new Invoice();
		invoice2.setPartNumber("543253");  
		invoice2.setPartDescription("This is part2");
		invoice2.setQuantity(100);
		invoice2.setPrice(85.45);
		System.out.println(invoice1.getInvoiceAmount());
		System.out.println(invoice2.getInvoiceAmount());
	}
}
