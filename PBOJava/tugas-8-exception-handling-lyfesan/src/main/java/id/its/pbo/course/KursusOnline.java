package id.its.pbo.course;

import java.util.ArrayList;
import java.util.List;

public class KursusOnline {
	
	private List<Peserta> pesertaList;
	
	public KursusOnline() {
		this.pesertaList =  new ArrayList<Peserta>();
	}
	
	public void daftarPeserta(Peserta peserta) throws PendidikanTidakMemenuhiSyaratException, UsiaTidakMemenuhiSyaratException {
		peserta.cekKelayakan();
		this.pesertaList.add(peserta);
	}
	
	public List<Peserta> getDaftarPeserta(){
		return this.pesertaList;
	}
	
}
