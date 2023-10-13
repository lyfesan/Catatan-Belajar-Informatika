package id.its.pbo.library;

import java.util.ArrayList;
import java.util.List;

public class Perpustakaan {

	private List<Buku> daftarBuku;
	private List<Anggota> daftarAnggota;
	
	public Perpustakaan() {
		this.daftarBuku =  new ArrayList<Buku>();
		this.daftarAnggota = new ArrayList<Anggota>();
	}

	public void tambahBuku(Buku buku) {
		this.daftarBuku.add(buku);
	}
	
	public void tambahAnggota(Anggota anggota) {
		this.daftarAnggota.add(anggota);
	}
	
	public void pinjamBuku(Anggota anggota, Buku buku) {
		buku.tambahPeminjam(anggota);
	}
	
	public List<Buku> getDaftarBuku(){
		return this.daftarBuku;
	}
	
	public List<Anggota> getDaftarAnggota(){
		return this.daftarAnggota;
	}
	
	public void printDaftarBuku() {
		System.out.println("Info Buku:");
		for (Buku buku : this.daftarBuku) {
			System.out.println("- " + buku.getInfoBuku());
		}
	}

	public void printDaftarAnggota() {
		System.out.println("Info Anggota:");
		for (Anggota anggota : this.daftarAnggota) {
			System.out.println("- " + anggota.getInfoAnggota());
		}
	}
}
