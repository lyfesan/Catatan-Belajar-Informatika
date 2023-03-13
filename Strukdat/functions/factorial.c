#include<stdio.h>

typedef unsigned long long ull;

ull fact(ull x){
    if(!x) return 1;
    ull res=1;
    for(ull i=1;i<=x;i++){
        res*=i;
    }
    return res;
}

int main(){
    ull f;
    printf("=====Program menghitung faktorial=====\n");
    printf("Masukkan bilangan yang ingin difaktorial : ");
    scanf("%llu",&f);
    printf("Hasil dari %llu! adalah : %llu\n",f,fact(f));
}