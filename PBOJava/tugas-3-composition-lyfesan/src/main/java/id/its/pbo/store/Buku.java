package id.its.pbo.store;

public class Buku {
	
	private String isbn, judul;
	private double harga;
	
	public Buku(String isbn, String judul, double harga) {
		this.setIsbn(isbn);
		this.setJudul(judul);
		this.setHarga(harga);
	}

	public String getIsbn() {
		return isbn;
	}

	public String getJudul() {
		return judul;
	}

	public double getHarga() {
		return harga;
	}

	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}

	public void setJudul(String judul) {
		this.judul = judul;
	}

	public void setHarga(double harga) {
		this.harga = harga;
	}

	public String getBuku() {
		return "ISBN: " + this.getIsbn() + ", Judul: " + this.getJudul() + ", Harga: " + this.getHarga();
	}
}
