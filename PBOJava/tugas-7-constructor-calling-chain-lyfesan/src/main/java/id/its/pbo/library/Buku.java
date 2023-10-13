package id.its.pbo.library;

import java.util.ArrayList;
import java.util.List;

public class Buku {

	private String judul, pengarang;
	private int tahunTerbit;
	private List<Anggota> listPeminjam;
	
	public Buku(String judul, String pengarang, int tahunTerbit) {
		this.listPeminjam = new ArrayList<Anggota>();
		this.setJudul(judul);
		this.setPengarang(pengarang);
		this.setTahunTerbit(tahunTerbit);
	}
	

	public String getJudul() {
		return judul;
	}

	public void setJudul(String judul) {
		this.judul = judul;
	}

	public String getPengarang() {
		return pengarang;
	}

	public void setPengarang(String pengarang) {
		this.pengarang = pengarang;
	}

	public int getTahunTerbit() {
		return tahunTerbit;
	}

	public void setTahunTerbit(int tahunTerbit) {
		this.tahunTerbit = tahunTerbit;
	}
	
	public void tambahPeminjam(Anggota anggota) {
		this.listPeminjam.add(anggota);
	}
	
	public void printDaftarPeminjam(){
		System.out.println("Daftar Peminjam Buku " + this.getJudul());
		for(Anggota anggota : listPeminjam) {
			System.out.println("- " + anggota.getInfoAnggota());
		}
	}
	
	public List<Anggota> getDaftarPeminjam(){
		return this.listPeminjam;
	}
	
	public String getInfoBuku() {
		return this.getJudul() + ", " + this.getPengarang() + ", " + this.getTahunTerbit();
	}
}
