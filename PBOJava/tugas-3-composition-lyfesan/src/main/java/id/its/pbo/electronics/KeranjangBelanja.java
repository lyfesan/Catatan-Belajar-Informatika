package id.its.pbo.electronics;

import java.util.ArrayList;
import java.util.List;

public class KeranjangBelanja {

    private List<ItemBelanja> itemBelanjaList;

    public KeranjangBelanja() {
        this.itemBelanjaList = new ArrayList<>();
    }

    public void tambahProduk(Produk produk, int kuantitas) {
        this.itemBelanjaList.add(new ItemBelanja(produk, kuantitas));
    }
    
    public double hitungTotalBelanja() {
    	
    	double totalHarga = 0.0;
    	
    	for(ItemBelanja itemBelanja : itemBelanjaList) {
    		totalHarga += itemBelanja.hitungTotal();
    	}
    	
    	return totalHarga;
    }
}
