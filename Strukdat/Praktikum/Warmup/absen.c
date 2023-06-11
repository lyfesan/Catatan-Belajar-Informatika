#include<stdio.h>
int main(){
    int n,one=0,nil=0,x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        x ? one++ : nil++;
    }
    printf("%d %d\n", one, nil);
}