#include<stdio.h>

//Recursive function to find gcd using substraction
int gcd(int a, int b){
    if(a==b) return a;

    if(a>b) return gcd(a-b,a);
    else return gcd(a,b-a);
}

int main(){
    int a=4;
    int b=18;
    printf("GCD of %d and %d is %d",a,b,gcd(a,b));
}