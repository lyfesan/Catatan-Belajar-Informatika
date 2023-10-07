package id.its.pbo.music;

public class StudioMusikProgram {

	public static void main(String[] args) {
		
		StudioMusik studioTC = new StudioMusik();
		Instrumen gitar1 = new Gitar("Kasumi Star Guitar");
		Instrumen piano1 = new Piano("Arisa Roland Piano");
		Instrumen gitar2 = new Gitar("Otae Guitar");
		
		studioTC.tambahInstrumen(gitar1);
		studioTC.tambahInstrumen(piano1);
		studioTC.tambahInstrumen(gitar2);
		
		System.out.println(studioTC.mainkanInstrumen());
	}
}
