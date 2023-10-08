package id.its.pbo.zoo;

public class KebunBinatangProgram {

	public static void main(String[] args) {
		
		KebunBinatang kbs = new KebunBinatang();
		Hewan simba = new Singa("Simba");
		Hewan anaconda = new Ular("Conda");
		Hewan pony1 = new Kuda("Twilight Sparkle");
		Hewan pony2 = new Kuda("Rarity");
		kbs.tambahHewan(simba);
		kbs.tambahHewan(pony2);
		kbs.tambahHewan(anaconda);
		kbs.tambahHewan(pony1);
		System.out.println(kbs.tampilkanHewanBersuara());
	}

}
