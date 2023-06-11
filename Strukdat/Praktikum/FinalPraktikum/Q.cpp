#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({});
        }
    }

    void add_edge(long vertex1, long vertex2, long weight){
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void dijkstra(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        priority_queue <pair<long, long>, 
                        vector <pair<long, long>>, 
                        greater <pair<long, long>> > pq;
        result = vector<long>(vertexCount, LONG_MAX);
        
        pq.push(make_pair(0, start));
        result[start] = 0;

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
                    }
                }
            }
        }
    }
};

int main(){
    graph g;
    int n,x,y,w,lim,mins=INT_MAX,ans=0;
    string s;
    cin>>n;
    g.init(n+1);
    vector<pair<string,int>> v;
    v.push_back(make_pair("0",0));
    while(n--){
        cin>>s>>x;
        v.push_back(make_pair(s,x));
    }
    cin>>n;
    while(n--){
        cin>>x>>y>>w;
        g.add_edge(x,y,w);
    }
    cin>>lim;
    vector<long> res;

    g.dijkstra(res, 0);

    for(int i=1; i<res.size(); i++){
        if(res[i]<=lim && v[i].second<mins){
            mins=v[i].second;
            ans=i;
        }
    }

    cout<<"hari ini makan di "<<v[ans].first<<"\n";

    return 0;
}