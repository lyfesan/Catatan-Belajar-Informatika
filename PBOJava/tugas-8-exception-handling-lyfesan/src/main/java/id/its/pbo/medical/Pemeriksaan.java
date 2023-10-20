package id.its.pbo.medical;

public class Pemeriksaan {

	public void periksaData(Pasien pasien) throws Exception {
		try {
			pasien.validasiData();
		} catch (DataTidakValidException e1) {
			throw new Exception("Pemeriksaan Gagal: Data yang dimasukkan tidak valid.", e1);
		} catch (DataTidakLengkapException e2) {
			throw new Exception("Pemeriksaan Gagal: Data pasien tidak lengkap.", e2);
		}
		
	}

}
