package id.its.pbo.transport;

import id.its.pbo.vehicle.Kendaraan;

public class Mobil extends Kendaraan {
	
	private String jenis;
	
	public Mobil() {
		super();
		this.setJenis("-");
	}	
	
	public Mobil(String newMerk, int newTahunProduksi, String newJenis) {
		super(newMerk, newTahunProduksi);
		this.setJenis(newJenis);
	}
	
	public String getJenis() {
		return this.jenis;
	}
	
	public void setJenis(String newJenis) {
		this.jenis = newJenis;
	}
	
	public String infoMobil() {
		return this.infoKendaraan() + ", Jenis: " + this.getJenis();
	}
	
}
