#include<stdio.h>

int binpow(int a, int b){
    int res = 1;
    while(b>0){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

int main(){
    int a,b,t,x=0,y=0;
    scanf("%d %d", &a, &b);
    while(a--){
        scanf("%d", &t);
        x+=binpow(10,a)*t;
    }
    while(b--){
        scanf("%d", &t);
        y+=binpow(10,b)*t;
    }
    printf("%d\n", x+y);
}