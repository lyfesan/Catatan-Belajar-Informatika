#include<bits/stdc++.h>
using namespace std;

bool BFS(vector<int> adj[], int s, int x, int v, int pre[], int dis[]){
    list<int> q;
    bool vis[v+5];
    memset(vis,0,sizeof(vis));
    memset(dis,INT_MAX,sizeof(&dis));
    memset(pre,-1,sizeof(&pre));
    vis[s]=true;
    dis[s]=true;
    q.push_back(s);
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for(int i=0;i<adj[u].size();i++){
            if(!vis[adj[u][i]]){
                vis[adj[u][i]]=true;
                dis[adj[u][i]] = dis[u]+1;
                pre[adj[u][i]] = u;
                q.push_back(adj[u][i]);

                if(adj[u][i]==x) return true;
            }
        }
    }
    return false;
}

void shortDist(vector<int> adj[], int s, int x, int v){
    int pre[v+5], dis[v+5];
    if(!BFS(adj, s, x, v, pre, dis)){
        cout<<"RIP LAPET 2023\n";
        return;
    }
    stack<int> p;
    int t=x;
    p.push(t);
    while(pre[t]!=-1){
        p.push(pre[t]);
        t=pre[t];
    }
    cout<<dis[x]<<"\n";
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<"\n";
}

int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<int> adj[n+5];
    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    shortDist(adj,1,n,n);
}