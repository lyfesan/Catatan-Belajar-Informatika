#include<bits/stdc++.h>
using namespace std;

int path(vector<vector<pair<int, int>>>& adj, int n){
    vector<int> res(n+1, INT_MAX);
    queue<int> q;
    res[0] = 0;res[1] = 0;
    q.push(1);
    while(!q.empty()){
        int top = q.front();
        q.pop();

        for (auto i : adj[top]){
            if(res[i.first] > max(res[top], i.second)){
                res[i.first] = max(res[top], i.second);
                q.push(i.first);
            }
        }
    }
    return res[n];
}

int main(){
    int n,m;
    int a,b,c;
    cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 1; i <=m; i++){
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    cout<<path(adj,n)<<endl;
}