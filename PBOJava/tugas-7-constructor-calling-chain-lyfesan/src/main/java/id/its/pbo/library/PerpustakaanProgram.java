package id.its.pbo.library;

public class PerpustakaanProgram {

	public static void main(String[] args) {
		Perpustakaan perpusTC = new Perpustakaan();
		Buku buku1 = new Buku("How a Realist Hero Rebuilt the Kingdom: Volume 14","Dojyomaru",2021);
		Buku buku2 = new Buku("Never Let Me Go","Kazuo Ishiguro", 2005);
		Anggota anggota1 = new Anggota("Rana","1101");
		Anggota anggota2 = new Anggota("Nara", "Jl. Penuh kenangan", "1009");
		perpusTC.tambahAnggota(anggota1);
		perpusTC.tambahAnggota(anggota2);
		perpusTC.tambahBuku(buku1);
		perpusTC.tambahBuku(buku2);
		perpusTC.pinjamBuku(anggota1, buku1);
		perpusTC.pinjamBuku(anggota2, buku2);
		perpusTC.pinjamBuku(anggota2, buku1);
		
		//Print daftar buku cara 1 di dalam main
		System.out.println("Print data dengan cara 1 (tampilkan list di dalam main)");
		System.out.println("Info Buku:");
		for (Buku buku : perpusTC.getDaftarBuku()) {
			System.out.println("- " + buku.getInfoBuku());
		}
		System.out.println();
		System.out.println("Info Anggota:");
		for (Anggota anggota : perpusTC.getDaftarAnggota()) {
			System.out.println("- " + anggota.getInfoAnggota());
		}
		System.out.println();
		//Daftar peminjam buku "buku1"
		System.out.println("Daftar Peminjam Buku " + buku1.getJudul());
		for(Anggota anggota : buku1.getDaftarPeminjam()) {
			System.out.println("- " + anggota.getInfoAnggota());
		}
		System.out.println();
		
		//Print data dengan cara 2 memanggil method print
		System.out.println("Print data dengan cara 2 (memanggil method di dalam kelas)");
		perpusTC.printDaftarBuku();
		System.out.println();
		perpusTC.printDaftarAnggota();
		System.out.println();
		buku1.printDaftarPeminjam();
		
	}

}
