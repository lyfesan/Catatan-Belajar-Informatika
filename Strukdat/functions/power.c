#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

long double powie(long long a, long long b){
    long double res=1.0;
    bool y = b>0 ? 0 : 1 ;
    b=llabs(b);
    while(b>0){
        if(b&1) res*=(long double)a;
        a*=a;
        b>>=1;
    }
    if(y) return 1.0/res; 
    return res;
}

int main(){
    long long x,y;
    printf("Program perpangkatan X^Y\n");
    printf("Masukkan nilai X^Y (format : X Y) : ");
    scanf("%lld %lld", &x, &y);
    printf("Hasil dari %lld^%lld = %Lg\n", x,y,powie(x,y));
}


