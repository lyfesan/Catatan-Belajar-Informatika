package id.its.pbo.bank;

public class PengecekanAkunBankProgram {

	public static void main(String[] args) throws Exception {
		try {
			Bank bankTC = new Bank();
			AkunBank akun1 = new AkunBank("0928392", 6000);
			AkunBank akun2 = new AkunBank("0938392", 4000);
			bankTC.tambahAkun(akun1);
			bankTC.tambahAkun(akun2);
			//bankTC.cariAkun("000000");
			akun1.tarik(6000);
			akun2.tarik(5000);
			
		} catch(Exception e){
			e.printStackTrace();
		}
	}

}
