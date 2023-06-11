#include<stdio.h>

void swap(int x, int y, int a[]){
    a[x]+=a[y];a[y]=a[x]-a[y];a[x]-=a[y];
}

void insertionSort(int a[], int n){
    for(int i = 1;i<n;i++){
        for(int j = i;j > 0 && a[j] < a[j-1];j--){
            swap(j, j-1, a);
        }
    }
}

int main(){
    int n;
    printf("Masukkan size array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Input array : ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("\nAfter sorting : ");
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}