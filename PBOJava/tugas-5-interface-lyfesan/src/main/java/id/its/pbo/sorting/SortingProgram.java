package id.its.pbo.sorting;

public class SortingProgram {

	public static void main(String[] args) {
		Item buku1 = new Buku("Harry Potter", 505);
		Item buku2 = new Buku("Art of War", 55);
		Item sepatu1 = new Sepatu("Nike",41);
		Item sepatu2 = new Sepatu("Adidas", 40);
		
		Sortable[] items = {buku2, buku1, sepatu2, sepatu1};
		for(Sortable tmp : items) {
			System.out.println();
	    	System.out.println(((Item)tmp).getNama());
	    }
		Sortable[] sortedItems = Sorter.sortItems(items);
	    for(Sortable tmp : sortedItems) {
	    	System.out.println(((Item)tmp).getNama());
	    }

	}

}
