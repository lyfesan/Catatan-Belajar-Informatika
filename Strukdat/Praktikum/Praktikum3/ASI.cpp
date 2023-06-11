#include<bits/stdc++.h>
using namespace std;

int solvecatalan(int n){
    if (n == 1) return 1; 
    return 2 * (2*n - 1) * solvecatalan(n-1) / (n+1);

}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        //if(n<0) cout<<0<<"\n";
        cout<<solvecatalan(n)<<"\n";
    }
}