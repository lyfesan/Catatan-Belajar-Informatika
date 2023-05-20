#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], bool vis[], int x){
    vis[x]=true;
    for(auto j:adj[x]){
        if(!vis[j]) DFS(adj,vis,j);
    }
}

int main(){
    int n,m,a,b,cnt=0;
    cin>>n>>m;
    vector<int> adj[n];
    bool vis[n]={false};
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            DFS(adj,vis,i);
        }
    }
    if(cnt==1) cout<<"Kompleksitas entitas terbentuk\n";
    else cout<<"Seluruh kosmik tidak berkaitan, butuh "<<cnt-1<<" lagi\n";
}