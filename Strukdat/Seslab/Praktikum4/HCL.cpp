#include<bits/stdc++.h>
using namespace std;

int cnt[9]={0};
bool vis[9]={false};

int conv(string s){
    if(s=="A1") return 0; 
    if(s=="A2") return 1; 
    if(s=="A3") return 2; 
    if(s=="B1") return 3; 
    if(s=="B2") return 4; 
    if(s=="B3") return 5; 
    if(s=="C1") return 6; 
    if(s=="C2") return 7; 
    if(s=="C3") return 8; 
    return 0;
}

void DFS(vector<int> adj[], bool vis[], int x, int l){
    if(!vis[x]) cnt[l]++;
    vis[x]=true;
    for(auto j:adj[x]){
        if(!vis[j]) DFS(adj,vis,j,l);
    }
}

int main(){
    int n,l=0,res=0;
    vector<int> adj[9];
    string s1,s2,s3;
    cin>>n;
    while(n--){
        cin>>s1>>s2>>s3;
        adj[conv(s1)].push_back(conv(s3));
        adj[conv(s3)].push_back(conv(s1));
    }
    for(int i=0;i<9;i++){
        if(!vis[i]){
            DFS(adj,vis,i,l);
            l++;
        }
    }
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            res+=(cnt[i]*cnt[j]);
        }
    }
    cout<<res<<"\n";
}