package id.its.pbo.electronics;

public class ItemBelanja {

    private Produk produk;
    private int kuantitas;

    public ItemBelanja(Produk produk, int kuantitas) {
        this.setProduk(produk);
        this.setKuantitas(kuantitas);
    }

    public Produk getProduk() {
        return produk;
    }

    public int getKuantitas() {
        return kuantitas;
    }

    public void setProduk(Produk produk) {
        this.produk = produk;
    }

    public void setKuantitas(int kuantitas) {
        this.kuantitas = Math.max(kuantitas,0);
    }

    public double hitungTotal(){
        return this.produk.getHarga() * this.getKuantitas();
    }

}
