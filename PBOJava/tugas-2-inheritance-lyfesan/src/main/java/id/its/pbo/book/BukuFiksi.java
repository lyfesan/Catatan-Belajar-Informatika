package id.its.pbo.book;

public class BukuFiksi extends Buku {
	
	private String genre;
	
	public BukuFiksi() {
		super();
		this.genre = "";
	}
	
	public BukuFiksi(String newJudul, String newPengarang ,String newGenre) {
		super(newJudul, newPengarang);
		this.setGenre(newGenre);
	}
	
	public void setGenre(String newGenre) {
		this.genre = newGenre;
	}
	
	public String getGenre() {
		return this.genre;
	}
	
	@Override
	public void showInfo() {
		super.showInfo();
		System.out.println("Genre : " + this.getGenre());
	}
	
}