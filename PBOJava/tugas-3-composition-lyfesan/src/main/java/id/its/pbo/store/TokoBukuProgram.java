package id.its.pbo.store;

public class TokoBukuProgram {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TokoBuku toko = new TokoBuku();
		Buku buku1 = new Buku("1234567890", "Harry Potter", 150000);
		Buku buku2 = new Buku("0192738296", "Quiet", 124000);
		toko.tambahBuku(buku1);
		toko.tambahBuku(buku2);
		Buku bukuCari = toko.cariBuku("1234567890");
		//System.out.println(bukuCari.getBuku());
		toko.showDaftarBuku();
	}

}
