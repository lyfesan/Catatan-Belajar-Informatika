#include <stdio.h>

int findModeRecursive(int arr[], int n) {
  // Base case
  if (n == 1) return arr[0];

  // Recursive case by divide and conquer
  int leftMode = findModeRecursive(arr, n / 2);
  int rightMode = findModeRecursive(arr + n / 2, n / 2);

  // Compare two modes and return the modes with highest occurences count.
  int leftCount = 0, rightCount = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == leftMode) leftCount++;
    else if (arr[i] == rightMode) rightCount++;
  }

  return leftCount >= rightCount ? leftMode : rightMode;
}

int main() {
    int arr[] = {1,8,9,10,2,4,4,6,1,5,3,7,10,1,2,6,5,1,6,2,3,9,10,9,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Integer list: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    int mode = findModeRecursive(arr, n);
    printf("\nThe mode of the list is %d\n", mode);
}