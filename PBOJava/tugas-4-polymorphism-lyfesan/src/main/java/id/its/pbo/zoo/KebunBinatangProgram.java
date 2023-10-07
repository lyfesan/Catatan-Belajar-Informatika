package id.its.pbo.zoo;

public class KebunBinatangProgram {

	public static void main(String[] args) {
		
		Hewan oyen = new Kucing("oyen");
		Hewan dogi = new Anjing("Dogi");
		System.out.println(oyen.buatSuara());
		System.out.println(dogi.buatSuara());

	}

}
