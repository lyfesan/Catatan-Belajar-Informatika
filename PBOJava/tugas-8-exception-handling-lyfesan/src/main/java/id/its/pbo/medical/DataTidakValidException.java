package id.its.pbo.medical;

public class DataTidakValidException extends Exception {

	public DataTidakValidException() {
		super("Data yang dimasukkan tidak valid.");
	}
	public DataTidakValidException(String message, Throwable cause) {
		super(message, cause);
	}

}
