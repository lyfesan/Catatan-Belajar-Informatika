#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;

    void init(long v){
        vertexCount = v;
        edgeCount = 0;
        for(int i=0; i<vertexCount; i++){
            adjList.push_back({});
        }
    }

    void add_edge(long vertex1, long vertex2){
        adjList[vertex1].push_back(vertex2);
        edgeCount++;
    }

    void bfs(vector<long> &dist, long start){
        queue<long> q;
        q.push(start);
        dist[start] = 0;
        while(!q.empty()){
            long temp = q.front();
            q.pop();
            for(auto vertex:adjList[temp]){
                if (dist[vertex]==0 || dist[vertex]>dist[temp]+1 && dist[vertex]!=0){
                    q.push(vertex);
                    dist[vertex] = dist[temp]+1;
                }
            }
        }
    }

    void path(){
        for(long i=0;i<vertexCount;i++){
            vector<long> dist(vertexCount, 0);
            bfs(dist,i);
            if(dist[i]!=0) cout<<dist[i]<<"\n";
            else cout<<"gak bisa pulang mamah\n";
        }
    }
};

int main(){
    graph g;
    long n,x,y;
    cin>>n;
    g.init(n);
    while(1){
        cin>>x>>y;
        if(x==-1 && y==-1) break;
        g.add_edge(x,y);
    }
    g.path();
}