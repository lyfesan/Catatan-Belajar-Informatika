#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,pair<int,string>>> pii;

int main(){
    int n,m,a,b;
    bool y=true;
    string s;
    vector<pii> v;
    pii tmp;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s>>a>>b;
        v.push_back(make_pair(b,make_pair(a,make_pair(i,s))));
    }
    
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++){
        if(v[i].first==v[i+1].first && v[i].second.first==v[i+1].second.first){
            pq.push(make_pair(v[i].second.second.first,make_pair(v[i].first,make_pair(v[i].second.first,v[i].second.second.second))));
            pq.push(make_pair(v[i+1].second.second.first,make_pair(v[i+1].first,make_pair(v[i+1].second.first,v[i+1].second.second.second))));
            //cout<<"Kamu jodoh ya "<<v[i].second.second.second<<" - "<<v[i].first<<" && "<<v[i+1].second.second.second<<" - "<<v[i+1].first<<"\n";
            y=false;
        }
        //cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second.first<<" "<<v[i].second.second.second<<"\n";
    }
    /*
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second.second<<" "<<v[i].second.second.first<<"\n";
    }
    */
    if(y){
        if(m==n) cout<<"Full senyum deck\n";
        else cout<<"Pasien selanjutnya adalah: "<<v[m].second.second.second<<" - "<<v[m].first<<"\n";
    }
    else{
        tmp=make_pair(pq.top().second.second.first,make_pair(pq.top().second.first,make_pair(pq.top().second.first,pq.top().second.second.second)));
        pq.pop();
        while(!pq.empty()){
            if(tmp.second.first==pq.top().second.first && tmp.second.second.first==pq.top().second.second.first) break;
            else pq.pop();
        }
        cout<<"Kamu jodoh ya "<<tmp.second.second.second<<" - "<<tmp.second.first<<" && "<<pq.top().second.second.second<<" - "<<pq.top().second.first<<"\n";
        if(m==n) cout<<"Full senyum deck\n";
    }
}
