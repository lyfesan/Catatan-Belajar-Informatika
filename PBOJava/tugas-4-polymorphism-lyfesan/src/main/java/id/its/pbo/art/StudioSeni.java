package id.its.pbo.art;

import java.util.ArrayList;
import java.util.List;

public class StudioSeni {

	private List<KaryaSeni> karyaSeniList;
	
	public StudioSeni() {
		this.karyaSeniList = new ArrayList<KaryaSeni>();
	}
	
	public void tambahKaryaSeni(KaryaSeni karya) {
		this.karyaSeniList.add(karya);
	}
	
	public List<String> tampilkanSemuaKarya() {
		
		List<String> s =  new ArrayList<>();
		
		for (KaryaSeni karya : karyaSeniList) {
			s.add(karya.tampilkan());
		}
		
		return s;
	}
}