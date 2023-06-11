#include<stdio.h>

void swap(int *a, int *b){
    *a+=*b;*b = *a - *b;*a-=*b;
}

int partition(int arr[], int l, int h){
    int pivot = arr[l];

    int i = l-1, j = h+1;
    while(1)
    {
        do{
            i++;
        } while(arr[i] < pivot);

        do{
            j--;
        } while(arr[j] > pivot);

        if(i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
    return -1;
}

void quickSort(int a[], int l, int r){
    if(l>=r) return;
    //int p = a[(l+r)/2-1];
    int x = partition(a,l,r);
    quickSort(a,l,x);
    quickSort(a,x+1,r);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n+5];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }    
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}