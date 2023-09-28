package id.its.pbo;

public class Invoice {

	private String partNumber;
	private String partDescription;
	private int quantity;
	private double price;
	
	//Default constructor
	public Invoice() {
		this.partNumber = "";
		this.partDescription = "";
		this.quantity = 0;
		this.price = 0.0;
	}
	//Constructor
	public Invoice(String newPartNumber, String newPartDescription, int newQuantity, double newPrice) {
		this.setPartNumber(newPartNumber);
		this.setPartDescription(newPartDescription);
		this.setQuantity(newQuantity);
		this.setPrice(newPrice);
	}
	
	//Getter Function
	public String getPartNumber() {
		return partNumber;
	}
	
	public String getPartDescription() {
		return partDescription;
	}
	
	public int getQuantity() {
		return quantity;
	}
	
	public double getPrice() {
		return price;
	}
	
	//Setter Function
	public void setPartNumber (String newPartNumber) {
		this.partNumber = newPartNumber;
	}
		
	public void setPartDescription (String newDescription) {
		this.partDescription = newDescription;
	}
	
	public void setQuantity (int newQuantity) {
		if(newQuantity < 0) this.quantity = 0;
		else this.quantity = newQuantity;
	}
	
	public void setPrice (double newPrice) {
		if(newPrice < 0.0) this.price = 0.0;
		else this.price = newPrice;
	}
	
	//Get Invoice Amount
	public double getInvoiceAmount() {
		return this.getPrice() * this.getQuantity();
	}
	
}