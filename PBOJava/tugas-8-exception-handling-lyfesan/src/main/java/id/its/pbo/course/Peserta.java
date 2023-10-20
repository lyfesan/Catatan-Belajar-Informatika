package id.its.pbo.course;

public class Peserta {
	
	private String nama, tingkatPendidikan;
	private int usia;
	
	public Peserta(String nama, int usia, String tingkatPendidikan) {
		this.setNama(nama);
		this.setUsia(usia);
		this.setTingkatPendidikan(tingkatPendidikan);
	}

	public String getTingkatPendidikan() {
		return tingkatPendidikan;
	}

	public void setTingkatPendidikan(String tingkatPendidikan) {
		this.tingkatPendidikan = tingkatPendidikan;
	}

	public String getNama() {
		return this.nama;
	}

	public void setNama(String nama) {
		this.nama = nama;
	}

	public int getUsia() {
		return this.usia;
	}

	public void setUsia(int usia) {
		this.usia = usia;
	}
	
	public void cekKelayakan() throws PendidikanTidakMemenuhiSyaratException, UsiaTidakMemenuhiSyaratException {
		if(this.getUsia() < 18) {
			throw new UsiaTidakMemenuhiSyaratException();
		}
		else if(this.getTingkatPendidikan() != "Sarjana" || this.getTingkatPendidikan() != "Magister") {
			throw new PendidikanTidakMemenuhiSyaratException();
		}
	}
}
