package id.its.pbo.art;

public abstract class KaryaSeni {

	private String judul;
	
	public KaryaSeni(String judul) {
		this.setJudul(judul);
	}
	
	public String getJudul() {
		return this.judul;
	}
	
	public void setJudul(String judul) {
		this.judul = judul;
	}
	
	public abstract String deskripsi();
	
	public abstract String tampilkan();

}
