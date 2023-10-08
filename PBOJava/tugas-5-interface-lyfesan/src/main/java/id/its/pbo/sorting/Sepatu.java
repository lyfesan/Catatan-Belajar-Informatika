package id.its.pbo.sorting;

public class Sepatu extends Item implements Sortable {

	private int ukuran;
	
	public Sepatu(String nama, int ukuran) {
		super(nama);
		this.setUkuran(ukuran);
	}

	public int getUkuran() {
		return ukuran;
	}

	public void setUkuran(int ukuran) {
		this.ukuran = ukuran;
	}

	@Override
	public int compare(Sortable obj) {
		
		if(obj instanceof Sepatu) {
			if(this.getUkuran() < ((Sepatu)obj).getUkuran()) {
				return -1;
			}
			else if(this.getUkuran() > ((Sepatu)obj).getUkuran()) {
				return 1;
			}		
			return 0;
		}
		else {
			return super.compare(obj);
		}
	}
}
