package id.its.pbo.zoo;

import java.util.ArrayList;
import java.util.List;

public class KebunBinatang {

	private List<Hewan> hewanList;
	
	public KebunBinatang() {
		this.hewanList = new ArrayList<Hewan>();
	}
	
	public void tambahHewan(Hewan newHewan) {
		this.hewanList.add(newHewan);
	}
	
	public List<Hewan> tampilkanHewanBersuara(){
		List<Hewan> s = new ArrayList<Hewan>();
		for(Hewan hewanListTmp : this.hewanList) {
			if(hewanListTmp instanceof BisaBersuara) {
				s.add(hewanListTmp);
			}
		}
		return s;
	}

}
