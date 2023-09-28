package id.its.pbo.book;

public class Buku {
	
	private String judul,pengarang;
	
	public Buku() {
		this.judul = "";
		this.pengarang = "";
	}
	
	public Buku(String newJudul, String newPengarang) {
		this.setJudul(newJudul);
		this.setPengarang(newPengarang);
	}
	
	public void setJudul(String newJudul) {
		this.judul = newJudul;
	}
	
	public void setPengarang(String newPengarang) {
		this.pengarang = newPengarang;
	}
	
	public String getJudul() {
		return this.judul;
	}
	
	public String getPengarang() {
		return this.pengarang;
	}
	
	public void showInfo() {
		System.out.println("Judul : " + this.getJudul());
		System.out.println("Pengarang : " + this.getPengarang());
	}
}	