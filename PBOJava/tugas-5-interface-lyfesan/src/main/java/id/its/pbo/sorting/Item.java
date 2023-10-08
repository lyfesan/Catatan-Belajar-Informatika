package id.its.pbo.sorting;

public abstract class Item implements Sortable{
	
	private String nama;
	
	public Item(String nama) {
		this.setNama(nama);
	}
	
	public String getNama() {
		return this.nama;
	}
	
	public void setNama(String nama) {
		this.nama = nama;
	}
	
	//Compare ukuran object Item 
	@Override
	public int compare(Sortable obj) {
		if(this.getNama().compareTo(((Item)obj).getNama()) < 0) {
			return -1;
		}
		else if(this.getNama().compareTo(((Item)obj).getNama()) > 0) {
			return 1;
		}
		return 0;
	}

}
