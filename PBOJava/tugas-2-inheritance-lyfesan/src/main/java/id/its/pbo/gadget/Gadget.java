package id.its.pbo.gadget;

public class Gadget {
	
	private String brand;
	private int tahunRilis;
	
	public Gadget() {
		//this.setBrand("");
		//this.setTahunRilis(0);
		this.brand = "";
		this.tahunRilis = 0;
	}
	
	public Gadget(String newBrand, int newTahunRilis) {
		//this.setBrand(newBrand);
		//this.setTahunRilis(newTahunRilis);
		this.brand = newBrand;
		this.tahunRilis = newTahunRilis;
	}
	/*
	String getBrand() {
		return this.brand;
	}
	
	int getTahunRilis() {
		return this.tahunRilis;
	}
	
	void setBrand(String newBrand) {
		this.brand = newBrand;
	}
	
	void setTahunRilis(int newTahunRilis) {
		this.tahunRilis = newTahunRilis >=0 ? newTahunRilis : 0;
	}
	*/
	protected String infoGadget() {
		//return "Brand: " + this.getBrand() + ", Tahun Rilis: " + this.getTahunRilis();
		return "Brand: " + this.brand + ", Tahun Rilis: " + this.tahunRilis;
	}
}
