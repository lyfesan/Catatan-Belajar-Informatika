#include<bits/stdc++.h>
using namespace std;

char g[100][100];
bool v[100][100]={false};

void trav(int i, int j, int n){
    if(i>=n || i<0 || j>=n || j<0) return;
    if(g[i][j]=='#' || v[i][j]) return;
    v[i][j]=true;
    trav(i,j+1,n);
    trav(i,j-1,n);
    trav(i-1,j,n);
    trav(i-1,j-1,n);
    trav(i-1,j+1,n);
    trav(i+1,j,n);
    trav(i+1,j-1,n);
    trav(i+1,j+1,n);
}

int main(){
    int n,tot=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v[i][j]=false;
            cin>>g[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='+' && v[i][j]==false){
                tot++;
                trav(i,j,n);                
            }
        }
    }
    cout<<tot<<"\n";
}