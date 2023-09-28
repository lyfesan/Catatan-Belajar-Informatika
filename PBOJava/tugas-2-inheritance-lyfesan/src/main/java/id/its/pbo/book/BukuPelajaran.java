package id.its.pbo.book;

public class BukuPelajaran extends Buku {
	
	private String subjek;
	
	public BukuPelajaran() {
		super();
		this.subjek = "";
	}
	
	public BukuPelajaran(String newJudul, String newPengarang ,String newSubjek) {
		super(newJudul, newPengarang);
		this.setSubjek(newSubjek);
	}
	
	public void setSubjek(String newSubjek) {
		this.subjek = newSubjek;
	}
	
	public String getSubjek() {
		return this.subjek;
	}
	
	@Override
	public void showInfo() {
		super.showInfo();
		System.out.println("Subjek : " + this.getSubjek());
	}
}
