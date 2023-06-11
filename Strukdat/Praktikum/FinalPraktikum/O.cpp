#include<bits/stdc++.h>
using namespace std;

void color(vector<vector<int>> &a, int x, int y, int val, int lim, int n){
    if(val>lim || x>n || x<1 || y<1 || y>n) return;
    if(a[x][y]==0 || a[x][y]>val) a[x][y]=val;
    color(a,x+1,y,val+1,lim,n);
    color(a,x-1,y,val+1,lim,n);
    color(a,x,y+1,val+1,lim,n);
    color(a,x,y-1,val+1,lim,n);
}

int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<vector<int>> a(n+5,vector<int>(n+5,0));
    vector<pair<int,int>> lp;
    while(m--){
        cin>>x>>y;
        lp.push_back(make_pair(y,x));
    }
    for(int i=0;i<lp.size();i++){
        color(a,lp[i].first,lp[i].second,1,4,n);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}