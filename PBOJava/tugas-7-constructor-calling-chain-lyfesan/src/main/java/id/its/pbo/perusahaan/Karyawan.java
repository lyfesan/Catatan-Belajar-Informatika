package id.its.pbo.perusahaan;

public class Karyawan {

	private String nama,id;
	
	public Karyawan() {
		this("-","-");
	}
	
	public Karyawan(String nama, String id) {
		this.setNama(nama);
		this.setId(id);
	}
	
	public String getNama() {
		return this.nama;
	}
	
	public String getId() {
		return this.id;
	}
	
	public void setNama(String nama) {
		this.nama = nama;
	}
	
	public void setId(String id) {
		this.id = id;
	}

}
