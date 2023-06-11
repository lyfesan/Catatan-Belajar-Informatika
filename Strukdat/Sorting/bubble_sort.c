#include<stdio.h>
#include<stdbool.h>

void swap(int x, int y, int a[]){
    a[x]+=a[y];a[y]=a[x]-a[y];a[x]-=a[y];
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]) swap(j,j + 1,arr);
        }
    }
}
/*
void bubbleSort(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j<n-i;j++){
            if(a[j]>a[j+1]) swap(j,j+1,a);
        }
    }
}
*/
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
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}