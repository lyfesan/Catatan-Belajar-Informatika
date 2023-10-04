package id.its.pbo.computer;

public class KomputerProgram {
	
    public static void main(String[] args){
        
    	Processor processor1 = new Processor("AMD",3.5);        
    	Memory memory1 = new Memory(16,"DDR4");
    	Komputer komputer1 = new Komputer(processor1, memory1);
        System.out.println(komputer1.infoKomputer());
    }
}
