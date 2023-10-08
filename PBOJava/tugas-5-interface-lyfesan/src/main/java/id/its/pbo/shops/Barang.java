package id.its.pbo.shops;

public abstract class Barang {

	private String merk;
	
	public Barang(String merk) {
		this.setMerk(merk);
	}
	
	public String getMerk() {
		return this.merk;
	}
	
	public void setMerk(String merk) {
		this.merk = merk;
	}

}
