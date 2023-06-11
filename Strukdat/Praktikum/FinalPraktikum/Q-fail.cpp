#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<int> &result, vector<pair<int,int>> adj[], int start, int n){
    vector<bool> visited(n+1, false);
    priority_queue <pair<long, long>, 
                    vector <pair<long, long>>, 
                    greater <pair<long, long>> > pq;
        
    result = vector<int>(n+1, INT_MAX);
        
    pq.push(make_pair(0, start));
    result[start] = 0;

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();

        visited[temp.second] = true;
            
        for(auto vertex:adj[temp.second]){
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

int main(){
    int n,x,y,w,lim;
    string s;
    cin>>n;
    vector<pair<string,int>> v;
    v.push_back(make_pair("0",0));
    while(n--){
        cin>>s>>x;
        v.push_back(make_pair(s,x));
    }
    cin>>n;
    vector<pair<int,int>> adj[n+5];
    vector<int> res;
    while(n--){
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }
    cin>>lim;
    dijkstra(res,adj,0,n);

    for(int i=0; i<res.size(); i++){
        cout << i << " " << res[i] << endl;
    }
}