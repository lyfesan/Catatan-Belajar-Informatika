package id.its.pbo.art;

public class StudioSeniProgram {

	public static void main(String[] args) {
		StudioSeni lyfeStudio = new StudioSeni();
		KaryaSeni garudaWisnu = new Patung("Garuda Wisnu Kencana");
		KaryaSeni monaLisa = new Lukisan("Mona Lisa");
		KaryaSeni monumenHI = new Patung("Monumen Bundaran HI");
		lyfeStudio.tambahKaryaSeni(monumenHI);
		lyfeStudio.tambahKaryaSeni(monaLisa);
		lyfeStudio.tambahKaryaSeni(garudaWisnu);
		System.out.println(lyfeStudio.tampilkanSemuaKarya());
	}

}
