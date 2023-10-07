package id.its.pbo.zoo;

public abstract class Hewan {
	
	private String nama;
	
	public Hewan(String nama) {
		this.setNama(nama);
	}
	
	public String getNama() {
		return this.nama;
	}
	
	public void setNama(String nama) {
		this.nama = nama;
	}
	
	public abstract String buatSuara();
}
