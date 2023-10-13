package id.its.pbo.library;

public class Anggota {

	private String nama, alamat, nomorAnggota;
	
	public Anggota(String nama, String nomorAnggota) {
		this.setNama(nama);
		this.setAlamat("Alamat belum diisi");
		this.setNomorAnggota(nomorAnggota);
	}
	
	public Anggota(String nama, String alamat, String nomorAnggota) {
		this.setNama(nama);
		this.setAlamat(alamat);
		this.setNomorAnggota(nomorAnggota);
	}
	
	public String getNama() {
		return nama;
	}
	
	public void setNama(String nama) {
		this.nama = nama;
	}
	
	public String getAlamat() {
		return alamat;
	}
	
	public void setAlamat(String alamat) {
		this.alamat = alamat;
	}
	
	public String getNomorAnggota() {
		return nomorAnggota;
	}
	
	public void setNomorAnggota(String nomorAnggota) {
		this.nomorAnggota = nomorAnggota;
	}
	
	public String getInfoAnggota() {
		return this.getNama() + ", " + this.getAlamat() + ", " + this.getNomorAnggota();
	}

}
