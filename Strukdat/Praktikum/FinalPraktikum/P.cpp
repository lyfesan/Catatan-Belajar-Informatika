#include<bits/stdc++.h>
using namespace std;

bool v[105][105];
char g[105][105];

void trav(int i, int j, int n, int m){
    if(i>=n || i<0 || j>=m || j<0) return;
    if(g[i][j]=='X' || v[i][j]) return;
    v[i][j]=true;
    trav(i,j+1,n,m);
    trav(i,j-1,n,m);
    trav(i-1,j,n,m);
    trav(i+1,j,n,m);
}

int main(){
    memset(v,0,sizeof(v));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!v[i][j] && (g[i][j]=='O' || g[i][j]=='^' || g[i][j]=='*') && (i==0 || i==n-1 || j==0 || j==m-1)) trav(i,j,n,m);    
            else if(!v[i][j] && !(i==0 || i==n-1 || j==0 || j==n-1) && g[i][j]=='^') trav(i,j,n,m);
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!v[i][j] && g[i][j]=='O') cout<<'X';
            else cout<<g[i][j];
        }
        cout<<"\n";
    }
}