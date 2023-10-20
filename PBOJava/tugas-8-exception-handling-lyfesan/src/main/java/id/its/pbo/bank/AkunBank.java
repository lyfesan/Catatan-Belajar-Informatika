package id.its.pbo.bank;

public class AkunBank {

	private static double batasPenarikanHarian = 5000.0;
	private String nomorAkun;
	private double saldo;
	
	public AkunBank(String nomorAkun, double saldo) {
		this.setNomorAkun(nomorAkun);
		this.setSaldo(saldo);
	}

	public double getSaldo() {
		return saldo;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	public String getNomorAkun() {
		return nomorAkun;
	}

	private void setNomorAkun(String nomorAkun) {
		this.nomorAkun = nomorAkun;
	}
	
	public static double getBatasPenarikanHarian() {
		return batasPenarikanHarian;
	}

	public static void setBatasPenarikanHarian(double batasPenarikanHarian) {
		AkunBank.batasPenarikanHarian = batasPenarikanHarian;
	}
	
	public void tarik(double jumlah) throws SaldoTidakCukupException, BatasPenarikanException {
		if (jumlah > this.getSaldo()) {
			throw new SaldoTidakCukupException();
		}
		if (jumlah > AkunBank.getBatasPenarikanHarian()) {
			throw new BatasPenarikanException();
		}
		//Penarikan berhasil
		this.setSaldo(this.getSaldo()-jumlah);
	}

}
