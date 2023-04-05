#include<stdio.h>
#include<string.h>
int main(){
    long long n,q,x,op;
    char s[5];
    scanf("%llu", &n);
    long long a[n+5];
    for(long long i=0;i<n;i++){
        scanf("%llu", &a[i]);
    } 
    /*
    for(long long i=0;i<n;i++){
        printf("%llu", a[i]);
    }
    */
    scanf("%llu", &q);
    while(q--){
        scanf("%llu", &op);
        if(op==2){
            for(long long i=0;i<n;i++){
                printf("%llu ", a[i]);
            }
            printf("\n");
            //fflush(NULL);
        }
        else if(op==1){
            scanf("%s %llu",s,&x);
            for(long long i=0;i<n;i++){
                if(!strcmp(s,"XOR")) a[i]^=x;
                else if(!strcmp(s,"AND")) a[i]&=x;
                else if(!strcmp(s,"OR")) a[i]|=x; 
            }
            //fflush(NULL);
        }
        fflush(NULL);
    }
}