package id.its.pbo.store;

import java.util.ArrayList;
import java.util.List;

public class TokoBuku {

    private List<Buku> bukuList;

    public TokoBuku() {
    	this.bukuList = new ArrayList<>();
    }
    public void tambahBuku(Buku bukuTambah) {
        bukuList.add(bukuTambah);
    }

    public void hapusBuku(Buku bukuHapus){
        bukuList.remove(bukuHapus);
    }

    public Buku cariBuku(String isbn) {
        return this.bukuList.stream()
                .filter(Buku -> Buku.getIsbn().equals(isbn))
                .findFirst()
                .orElse(null);
    }

    public List<Buku> getDaftarBuku() {
    	return this.bukuList;
    }
    
    public void showDaftarBuku() {
    	for(Buku buku : bukuList) {
            System.out.println(buku.getBuku());
    	}
    }
}
