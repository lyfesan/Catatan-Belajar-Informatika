package id.its.pbo.bank;

import java.util.ArrayList;
import java.util.List;

public class Bank {
	
	private List<AkunBank> daftarAkun;

	public Bank() {
		this.daftarAkun = new ArrayList<AkunBank>();
	}
	
	public List<AkunBank> getDaftarAkun() {
		return daftarAkun;
	}

	public void tambahAkun(AkunBank akun) {
		this.daftarAkun.add(akun);
	}
	
	public void cariAkun(String nomorAkun) throws AkunTidakDitemukanException {
		Boolean found = false;
		for(AkunBank akun : this.daftarAkun) {
			if(akun.getNomorAkun() == nomorAkun) {
				found = true;
				break;
			}
		}
		if(!found) {
			throw new AkunTidakDitemukanException();
		}
	}
	
}
