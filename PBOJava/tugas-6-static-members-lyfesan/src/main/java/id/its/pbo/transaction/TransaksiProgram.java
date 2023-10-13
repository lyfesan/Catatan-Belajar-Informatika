package id.its.pbo.transaction;

public class TransaksiProgram {

	public static void main(String[] args) {
		Transaksi transaksi1 = new Transaksi(100.5);
		Transaksi transaksi2 = new Transaksi(20.25);
		Transaksi transaksi3 = new Transaksi(10.75);
		System.out.println("ID: " + transaksi1.getTransaksiID() + "\nTotal transaksi: " + Transaksi.getTotalTransaksi());
		System.out.println("ID: " + transaksi2.getTransaksiID() + "\nTotal transaksi: " + Transaksi.getTotalTransaksi());
		System.out.println("ID: " + transaksi3.getTransaksiID() + "\nTotal transaksi: " + Transaksi.getTotalTransaksi());
		Transaksi.resetCounter();
		System.out.println("Total transaksi: " + Transaksi.getTotalTransaksi());
	}

}
