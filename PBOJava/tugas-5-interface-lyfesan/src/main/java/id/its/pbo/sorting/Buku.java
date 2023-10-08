package id.its.pbo.sorting;

public class Buku extends Item{

	private int jumlahHalaman;
	
	public Buku(String nama, int jumlahHalaman) {
		super(nama);
		this.setJumlahHalaman(jumlahHalaman);
	}
	
	public int getjumlahHalaman() {
		return this.jumlahHalaman;
	}
	
	public void setJumlahHalaman(int jumlahHalaman) {
		this.jumlahHalaman = jumlahHalaman;
	}
	
	@Override
	public int compare(Sortable obj) {
		
		if(obj instanceof Buku) {
			if(this.getjumlahHalaman() < ((Buku)obj).getjumlahHalaman()) {
				return -1;
			}
			else if(((Buku)obj).getjumlahHalaman() > ((Buku)obj).getjumlahHalaman()) {
				return 1;
			}	
			return 0;
		}
		else {
			return super.compare(obj);
		}
	}
}