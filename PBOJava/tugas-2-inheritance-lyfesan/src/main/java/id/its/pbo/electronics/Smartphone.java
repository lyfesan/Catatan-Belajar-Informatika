package id.its.pbo.electronics;

import id.its.pbo.gadget.*;

public class Smartphone extends Gadget{

	private String sistemOperasi;
	
	public Smartphone() {
		super();
		this.setSistemOperasi("");
	}
	
	public Smartphone(String newBrand, int newTahunRilis, String newSistemOperasi) {
		super(newBrand, newTahunRilis);
		this.setSistemOperasi(newSistemOperasi);
	}
	
	public String getSistemOperasi() {
		return this.sistemOperasi;
	}
	
	public void setSistemOperasi(String newSistemOperasi) {
		this.sistemOperasi = newSistemOperasi;
	}
	
	public String infoSmartphone() {
		return this.infoGadget() + ", Sistem Operasi: " + this.getSistemOperasi();
	}
	
}
