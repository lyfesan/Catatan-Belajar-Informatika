package id.its.pbo.perusahaan;

public class Manager extends Karyawan {

	private String departemen;
	
	public Manager() {
		this("-","-","-");
	}
	
	public Manager(String nama, String id, String departemen) {
		super(nama,id);
		this.setdepartemen(departemen);
	}
	
	public String getDepartemen() {
		return this.departemen;
	}
	
	public void setdepartemen(String departemen) {
		this.departemen = departemen;
	}

}
