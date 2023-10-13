package id.its.pbo.registration;

public class Mahasiswa {

	private static int registrantCounter = 0;
	private int nomorPendaftaran;
	private String nama;
	
	public Mahasiswa(String nama) {
		registrantCounter++;
		this.nomorPendaftaran = registrantCounter;
		this.nama = nama;
	}
	
	public void setNama(String nama) {
		this.nama = nama;
	}
	
	public String getNama() {
		return this.nama;
	}
	
	public int getNomorPendaftaran() {
		return this.nomorPendaftaran;
	}
	
	public static int getTotalRegistrant() {
		return registrantCounter;
	}
	
	public static void resetRegistrantCounter() {
		registrantCounter = 0;
	}

}
