package id.its.pbo.computer;

public class Processor {
    
	private String brand;
    private double kecepatan;

    public Processor() {
        this.brand = "";
        this.kecepatan = 0.0;
    }

    public Processor(String newBrand, double newKecepatan) {
        this.setBrand(newBrand);
        this.setKecepatan(newKecepatan);
    }

    public String getBrand() {
        return this.brand;
    }

    public double getKecepatan() {
        return this.kecepatan;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public void setKecepatan(double kecepatan) {
        this.kecepatan = kecepatan;
    }
}
