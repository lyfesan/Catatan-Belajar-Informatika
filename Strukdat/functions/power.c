#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

long double powie(long double a, long long b){
    long double res=1.0;
    bool y = b>0 ? 0 : 1 ;
    b=llabs(b);
    while(b>0){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    if(y) return 1.0/res; 
    return res;
}

int main(){
    long long y;
    long double x;
    printf("Program perpangkatan X^Y\n");
    printf("Masukkan nilai X^Y (format : X Y) : ");
    scanf("%Lf %lld", &x, &y);
    printf("Hasil dari %Lg^%lld = %Lg\n", x,y,powie(x,y));
}


