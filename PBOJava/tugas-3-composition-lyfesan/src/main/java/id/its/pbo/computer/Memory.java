package id.its.pbo.computer;

public class Memory {
    
	private int kapasitas;
    private String tipeMemory;

    public Memory(){
        this.setKapasitas(0);
        this.setTipeMemory("");
    }

    public Memory(int kapasitas, String tipeMemory){
        this.setKapasitas(kapasitas);
        this.setTipeMemory(tipeMemory);
    }

    public int getKapasitas() {
        return this.kapasitas;
    }

    public String getTipeMemory() {
        return this.tipeMemory;
    }

    public void setKapasitas(int kapasitas) {
        this.kapasitas = kapasitas;
    }

    public void setTipeMemory(String tipeMemory) {
        this.tipeMemory = tipeMemory;
    }
}
