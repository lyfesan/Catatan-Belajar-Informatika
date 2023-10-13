package id.its.pbo.transaction;

public class Transaksi {

	private static int counter = 0;
	private int transaksiID;
	private double jumlah;
	
	public Transaksi(double jumlah) {
		counter++;
		this.transaksiID = counter;
		this.jumlah = jumlah;
	}
	
	public int getTransaksiID() {
		return this.transaksiID;
	}
	
	public static int getTotalTransaksi() {
		return counter;
	}
	
	public static void resetCounter() {
		counter = 0;
	}

}
