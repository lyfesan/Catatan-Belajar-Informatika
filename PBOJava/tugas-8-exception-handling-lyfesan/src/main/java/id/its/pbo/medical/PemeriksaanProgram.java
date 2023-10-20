package id.its.pbo.medical;

public class PemeriksaanProgram {

	public static void main(String[] args) {
		Pasien p1 = new Pasien("John", 30, "Surabaya");
		Pasien p2 = new Pasien("Charles", 30, "");
		Pasien p3 = new Pasien("Jin", 1000, "Surabaya");
		Pemeriksaan periksa = new Pemeriksaan();
		try {
			periksa.periksaData(p1);
			periksa.periksaData(p2);
			periksa.periksaData(p3);
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}
	}

}
