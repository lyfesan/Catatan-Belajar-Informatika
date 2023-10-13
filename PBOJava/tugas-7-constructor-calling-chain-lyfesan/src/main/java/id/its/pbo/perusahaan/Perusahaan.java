package id.its.pbo.perusahaan;

public class Perusahaan {

	public static void main(String[] args) {
		Direktur dirut1 = new Direktur("Richard", "ID1234", "HR", 27000000);
		System.out.println("Nama: " + dirut1.getNama() + "\nID: " + dirut1.getId() + "\nDepartemen: " 
				+ dirut1.getDepartemen() + "\nGaji: " + dirut1.getGaji());
	}

}
