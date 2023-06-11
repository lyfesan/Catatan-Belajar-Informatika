#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,pair<int,string>>> pii;

int main(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    priority_queue<pii, vector<pii>, greater<pii>> sm;
    pii tmp,ps;
    int n,m,a,b;
    string s;
    bool y=true;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s>>a>>b;
        pq.push(make_pair(b,make_pair(a,make_pair(i,s))));        
    }
    for(int i=0;i<n-1;i++){
        if(i==m) ps=pq.top();
        tmp=pq.top();
        pq.pop();
        if(tmp.second.first==pq.top().second.first && tmp.first==pq.top().first && !pq.empty()){
            y=false;
            if(tmp!=sm.top())sm.push(make_pair(tmp.second.second.first,make_pair(tmp.first,make_pair(tmp.second.first,tmp.second.second.second))));
            sm.push(make_pair(pq.top().second.second.first,make_pair(pq.top().first,make_pair(pq.top().second.first,pq.top().second.second.second))));
        }
    }
    if(y){
        if(m==n) cout<<"Full senyum deck\n";
        else cout<<"Pasien selanjutnya adalah: "<<ps.second.second.second<<" - "<<ps.first<<"\n";
    }
    else{
        tmp=sm.top();
        sm.pop();
        while(!sm.empty()){
            if(tmp.second.first==sm.top().second.first && tmp.second.second.first==sm.top().second.second.first) break;
            else sm.pop();
        }
        cout<<"Kamu jodoh ya "<<tmp.second.second.second<<" - "<<tmp.second.first<<" && "<<sm.top().second.second.second<<" - "<<sm.top().second.first<<"\n";
    }
}