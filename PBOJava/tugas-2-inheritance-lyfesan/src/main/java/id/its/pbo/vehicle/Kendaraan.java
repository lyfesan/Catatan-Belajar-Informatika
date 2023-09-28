package id.its.pbo.vehicle;

public class Kendaraan {
	
	private String merk; 
	private int tahunProduksi;
	
	public Kendaraan() {
		this.setMerk("");
		this.setTahunProduksi(0);
	}
	
	public Kendaraan(String newMerk, int newTahunProduksi) {
		this.setMerk(newMerk);
		this.setTahunProduksi(newTahunProduksi);
	}
	
	protected String getMerk() {
		return this.merk;
	}
	
	protected int getTahunProduksi() {
		return this.tahunProduksi;
	}
	
	protected void setMerk(String newMerk) {
		this.merk = newMerk;
	}
	
	protected void setTahunProduksi(int newTahunProduksi) {
		this.tahunProduksi = newTahunProduksi >=0 ? newTahunProduksi : 0;
	}
	
	protected String infoKendaraan() {
		return "Merk: " + this.getMerk() + ", Tahun: " + this.getTahunProduksi();
	}
}
