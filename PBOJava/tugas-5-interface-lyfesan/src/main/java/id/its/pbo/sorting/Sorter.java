package id.its.pbo.sorting;

public class Sorter {
	
	public static Sortable[] sortItems(Sortable[] objList){
		quickSort(objList, 0, objList.length-1);
		return objList;
	}
	
	// The main function that implements QuickSort
    // objList[] --> Array to be sorted,
    // low --> Starting index,
    // high --> Ending index
    static void quickSort(Sortable[] objList, int low, int high)
    {
        if (low < high) {
 
            // pi is partitioning index, objList
            // is now at right place
            int pi = partition(objList, low, high);
 
            // Separately sort elements before
            // partition and after partition
            quickSort(objList, low, pi - 1);
            quickSort(objList, pi + 1, high);
        }
    }
	
	public static void swap(Sortable[] objList, int i, int j) {
		Sortable tmp = objList[i];
		objList[i] = objList[j];
		objList[j] = tmp;	
	}
	
    static int partition(Sortable[] objList, int low, int high)
    {
        // Choosing the pivot
        Sortable pivot = objList[high];
 
        // Index of smaller element and indicates
        // the right position of pivot found so far
        int i = (low - 1);
 
        for (int j = low; j <= high - 1; j++) {
 
            // If current element is smaller than the pivot
            if (objList[j].compare(pivot) == -1) {
 
                // Increment index of smaller element
                i++;
                swap(objList, i, j);
            }
        }
        swap(objList, i + 1, high);
        return (i + 1);
    }
}