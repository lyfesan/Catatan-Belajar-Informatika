#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int l, int m, int r){
    
    int i=l;
    int j=m+1;
    int k=l;
    int tmp[n+5];

    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            tmp[k]=a[i];
            i++;
            k++;
        }
        else{
            tmp[k]=a[j];
            j++;
            k++;
        }
    }     

    while(i<=m){
        tmp[k]=a[i];
        i++;
        k++;
    } 
    
    while(j<=r){
        tmp[k]=a[j];
        j++;
        k++;
    }

    for(int i=l;i<=r;i++){
        a[i]=tmp[i];
    }
}

void MergeSort(int arr[], int l, int r){
    if(l<r){
        
        int m = l +(r-1)/2;
        
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        
        merge(arr,l,m,r);
    }    
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    MergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
/*
int main(){
    //printf("Masukkan jumlah elemen : ");
    scanf("%d", &n);
    int a[n+10];
    //printf("Masukkan elemen : ");
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}
*/