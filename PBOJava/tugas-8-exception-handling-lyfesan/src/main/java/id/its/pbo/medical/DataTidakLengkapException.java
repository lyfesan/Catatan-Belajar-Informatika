package id.its.pbo.medical;

public class DataTidakLengkapException extends Exception {

	public DataTidakLengkapException() {
		super("Data pasien tidak lengkap.");
	}
	public DataTidakLengkapException(String message, Throwable cause) {
		super(message, cause);
	}

}
