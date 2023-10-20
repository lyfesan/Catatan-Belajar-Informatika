package id.its.pbo.medical;

public class Pasien {

	private String nama, alamat;
	private int umur;
	
	public Pasien(String nama, int umur, String alamat) {
		this.setNama(nama);
		this.setUmur(umur);
		this.setAlamat(alamat);
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

	public int getUmur() {
		return umur;
	}

	public void setUmur(int umur) {
		this.umur = umur;
	}
	
	public void validasiData() throws DataTidakLengkapException, DataTidakValidException{
		if(this.getNama()=="" || this.getAlamat()=="") {
			throw new DataTidakLengkapException();
		}
		if(this.getUmur() < 0 || this.getUmur() > 120) {
			throw new DataTidakValidException();
		}
	}

}
