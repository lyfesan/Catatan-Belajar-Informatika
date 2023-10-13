package id.its.pbo.registration;

public class PendaftaranProgram {

	public static void main(String[] args) {
		
		Mahasiswa mhs1 = new Mahasiswa("Alfa");
		Mahasiswa mhs2 = new Mahasiswa("Beta");
		Mahasiswa mhs3 = new Mahasiswa("Charlie");
		System.out.println("Nomor pendaftaran: " + mhs1.getNomorPendaftaran());
		System.out.println("Nomor pendaftaran: " + mhs2.getNomorPendaftaran());
		System.out.println("Nomor pendaftaran: " + mhs3.getNomorPendaftaran());
		System.out.println("Total mahasiswa mendaftar: " + Mahasiswa.getTotalRegistrant());
		Mahasiswa.resetRegistrantCounter();
		System.out.println("Total mahasiswa mendaftar setelah reset: " + Mahasiswa.getTotalRegistrant());
	}

}
