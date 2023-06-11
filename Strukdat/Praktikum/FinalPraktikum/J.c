#include<stdio.h>
typedef unsigned long long ull;
const ull MOD = 1000000009;

ull binpow(ull a, ull b, ull m){
    a%=m;
    ull res = 1;
    while(b>0){
        if(b&1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res%MOD;
}

int main(){
    ull m,n,res;
    scanf("%llu", &m);
    while(m--){
        scanf("%llu", &n);
        if(n&1) res = binpow(binpow(2,(n-1)/2,MOD),n,MOD); 
        else res = binpow(binpow(2,n/2,MOD),n-1,MOD);
        printf("Zodiak found: %llu signs\n", res);
    }
}