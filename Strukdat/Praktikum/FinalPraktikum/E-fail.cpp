#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount;
    vector<vector<pair<long, long>>> adjList;
    vector<vector<long>> adjM;
    void init(long v){
        vertexCount = v;
        for(int i=0; i<=vertexCount; i++){
            adjList.push_back({}); // inserts V amount of empty vector
            adjM.push_back({});
            for(int j=0;j<=vertexCount;j++){
                adjM[i].push_back({});
            }
        }
    }

    void add_edge(long vertex1, long vertex2, long weight){
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        adjM[vertex1][vertex2] = weight;
        adjM[vertex2][vertex1] = weight;
    }

    void dijkstra(vector<long> &result, vector<long> &parent, long start){
        vector<bool> visited(vertexCount, false);
        priority_queue <pair<long, long>, 
                        vector <pair<long, long>>, 
                        greater <pair<long, long>> > pq;
        
        result = vector<long>(vertexCount+1, LONG_MAX);
        
        pq.push(make_pair(0, start));
        result[start] = 0;
        parent[start] = -1;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;
            
            for(auto vertex:adjList[temp.second]){
                long nextVertex = vertex.first;
                long weight = vertex.second;

                if(!visited[nextVertex]){
                    if(temp.first + weight < result[nextVertex]) {
                        result[nextVertex] = temp.first + weight;
                        pq.push(make_pair(result[nextVertex], nextVertex));
                        parent[nextVertex]=temp.second;
                    }
                }
            }
        }
    }

    void findMax(long v, vector<long> parent, long &maxi){
        if(v==1) return;
        if(maxi<adjM[v][parent[v]]) maxi = adjM[v][parent[v]];
        findMax(parent[v], parent, maxi);
    }
};

int main(){
    graph g;
    long n,m,x,y,w,maxi=LONG_MAX*-1;
    cin>>n>>m;
    g.init(n+1);
    while(m--){
        cin>>x>>y>>w;
        g.add_edge(x,y,w);
    }
    vector<long> dijkstra_result;
    vector<long> parent(n+1,1);
    
    g.dijkstra(dijkstra_result, parent, 1);
    g.findMax(n,parent,maxi);
    cout<<maxi;
    /*
    for(int i=1; i<dijkstra_result.size(); i++){
        cout << i << " " << dijkstra_result[i] << endl;
    }
    */
}