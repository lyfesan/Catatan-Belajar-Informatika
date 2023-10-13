package id.its.pbo.perusahaan;

public class Direktur extends Manager {

	private double gaji;
	
	public Direktur() {
		this("","","",0);
	}
	
	public Direktur(String nama, String id, String department, double gaji) {
		super(nama,id,department);
		this.setGaji(gaji);
	}
	
	public double getGaji() {
		return this.gaji;
	}
	
	public void setGaji(double gaji) {
		this.gaji = Math.max(0.0, gaji);
	}

}
