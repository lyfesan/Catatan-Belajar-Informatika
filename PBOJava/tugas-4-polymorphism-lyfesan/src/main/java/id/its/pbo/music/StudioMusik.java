package id.its.pbo.music;

import java.util.ArrayList;
import java.util.List;

public class StudioMusik {

	private List<Instrumen> instrumenList;
	
	public StudioMusik() {
		this.instrumenList = new ArrayList<Instrumen>();
	}
	
	public void tambahInstrumen(Instrumen instrumen) {
		this.instrumenList.add(instrumen);
	}
	
	public String mainkanInstrumen() {
		
		String s="";
		
		for (Instrumen instrumen : instrumenList) {
			s += s!="" ? " " : "";
			s += instrumen.suara();
		}
		
		return s;
	}

}
