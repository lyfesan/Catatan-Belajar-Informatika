package id.its.pbo.shops;

public class TokoBarangProgram {

	public static void main(String[] args) {
		Barang tv1 = new Televisi("LG");
		Barang fan1 = new KipasAngin("Maspion");
		Barang ioniqCar = new MobilListrik("Hyundai");
		
		System.out.println(ElectricityProvider.supplyPower((Electrifiable) tv1));
		System.out.println(ElectricityProvider.supplyPower((Electrifiable) ioniqCar));
		System.out.println(ElectricityProvider.supplyPower((Electrifiable) fan1));
		
	}

}
