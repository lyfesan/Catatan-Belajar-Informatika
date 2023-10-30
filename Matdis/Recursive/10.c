#include<stdio.h>

//Find the biggest integer of two integer a & b
int max(int a, int b){
    return a>b ? a : b;
}
//Recursive function to find maximum in array of integer
int findMaxInt(int arr[], int n){
    if(n==1) return arr[0];
    return max(arr[n-1], findMaxInt(arr,n-1));
}

int main(){
    int a[] = {10,12,18,29,9,8};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Set : ");
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\nMax integer in the set is : %d", findMaxInt(a,n));
}