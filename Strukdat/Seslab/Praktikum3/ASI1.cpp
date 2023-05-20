#include<bits/stdc++.h>
using namespace std;

int power(int n, int p){
    if(p==0) return 1;
    int sum=1;
    for(int i=0;i<p;i++){
        sum*=n;
    }
    return sum;
}

int solve(int xi, int yi, int xj, int yj, int d){
    return pow(abs(xj-xi),d) + pow(abs(yj-yi),d);
}

int main(){
    int n,d,maks=-10000,mins=10000,tmp;
    cin>>n>>d;
    int x[n+5], y[n+5];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            tmp=solve(x[i],y[i],x[j],y[j],d);
            if(tmp>maks) maks=tmp;
            if(tmp<mins) mins=tmp;
        }
    }
    cout<<mins<<" "<<maks<<"\n";
}