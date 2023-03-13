#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef unsigned long long ull;
#define MAX_PRIME 100000000

bool prime[MAX_PRIME];

void sieve_prime(){
    memset(prime,1,sizeof(prime));
    prime[0]=0;prime[1]=0;
    for(ull i=2;i<=MAX_PRIME;i++){
        if(prime[i]){
            for(ull j=i*i;j<=MAX_PRIME;j+=i){
                prime[j]=false;
            }
        }
    }
}

void print_prime(ull a, ull b){
    if(a>b) {a+=b;b=a-b;a-=b;}
    for(ull i=a;i<=b;i++){
        if(prime[i]) printf("%llu\n", i);
    }
}

int main(){
    int c;
    ull a,b;
    sieve_prime();
    while(1){
        printf("Program Bilangan Prima\n");
        printf("1.Cek bilangan prima\n2.Print bilangan prima dalam rentang a hingga b\n3.Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &c);
        if(c==1){
            printf("Masukkan bilangan yang ingin dicek : ");
            scanf("%llu", &a);
            prime[a] ? printf("%llu adalah bilangan prima\n",a) : printf("%llu bukan bilangan prima\n",a);
        }
        else if(c==2){
            printf("Masukkan bilangan a dan b sebagai rentang jarak bilangan prima yang ingin di output (format : a b) : ");
            scanf("%llu %llu", &a,&b);
            print_prime(a,b);
        }
        else {printf("Terima kasih telah menggunakan program ini...\n");break;}
    }
}