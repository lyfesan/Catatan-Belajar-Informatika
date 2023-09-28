package id.its.pbo.book;

public class PerpustakaanProgram {

	public static void main(String[] args) {
		BukuFiksi buku1 = new BukuFiksi("Never Let Me Go","Kazuo Ishiguro","Sci-Fi");
		BukuPelajaran buku2 = new BukuPelajaran("Java How to Program","Paul Deitel, Harvey Deitel", "Computer Science");
		buku1.showInfo();
		buku2.showInfo();
	}

}
