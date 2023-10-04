package id.its.pbo.computer;

public class Komputer {
    
	private Processor processor;
    private Memory memory;
    
    public Komputer(Processor processor, Memory memory){
        this.setMemory(memory);
        this.setProcessor(processor);
    }
    
    public Memory getMemory() {
        return this.memory;
    }

    public Processor getProcessor() {
        return this.processor;
    }

    public void setMemory(Memory memory) {
        this.memory = memory;
    }

    public void setProcessor(Processor processor) {
        this.processor = processor;
    }

    public String infoKomputer(){
        return "Processor Brand: " + this.getProcessor().getBrand() + ", Kecepatan: " + this.getProcessor().getKecepatan() + " GHz, Memory Kapasitas: " + this.getMemory().getKapasitas() + " GB, Tipe: " + this.getMemory().getTipeMemory();

    }
}
