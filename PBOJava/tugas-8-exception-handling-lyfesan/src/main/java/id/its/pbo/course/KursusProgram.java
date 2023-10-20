package id.its.pbo.course;

public class KursusProgram {

	public static void main(String[] args) {
		Peserta peserta1 = new Peserta("Udin", 19, "Sarjana");
		Peserta peserta2 = new Peserta("Albert", 28, "Magister");
		Peserta peserta3 = new Peserta("Ucok", 17, "Sarjana");
		KursusOnline kursus1 = new KursusOnline();
		try {
			kursus1.daftarPeserta(peserta1);
			kursus1.daftarPeserta(peserta2);
			kursus1.daftarPeserta(peserta3);
			
		} catch (Exception e1) {
			e1.printStackTrace();
		} finally {
			System.out.println("Proses pendaftaran selesai.");
		}
	}

}
