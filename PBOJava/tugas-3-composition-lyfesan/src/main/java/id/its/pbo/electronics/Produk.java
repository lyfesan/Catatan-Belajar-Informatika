package id.its.pbo.electronics;

public class Produk {

    private String nama;
    private double harga;

    public Produk(String nama, double harga) {
        this.setNama(nama);
        this.setHarga(harga);
    }

    public String getNama() {
        return nama;
    }

    public double getHarga() {
        return harga;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setHarga(double harga) {
        this.harga = Math.max(harga, 0.0);
    }
}
