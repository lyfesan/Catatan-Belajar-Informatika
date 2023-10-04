package id.its.pbo.electronics;

public class TokoElektronikProgram {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		KeranjangBelanja keranjang = new KeranjangBelanja();
		keranjang.tambahProduk(new Produk("Sungsang Milkyway 2", 5899000),1);
		keranjang.tambahProduk(new Produk("Xiaoling 5 Pro", 3899000),1);
		keranjang.tambahProduk(new Produk("Oddo Dingko 7", 7999000),1);
		System.out.println("Total Belanja: Rp" + String.format("%.2f", keranjang.hitungTotalBelanja()));
	}

}
