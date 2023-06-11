#include<bits/stdc++.h>

int fact(int n){
    if(n<=1) return 1;
    return n * fact(n-1);
}

int main(){
    std::cout<<fact(5);
}
/*
fact(5)
n * fact(4)
fact(4) -> 4 * fact(3)
...
base case : fact(0)/fact(1) -> fact(2) -> fact(3) -> .... -> fact(5)
*/