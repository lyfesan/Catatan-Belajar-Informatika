#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,pair<int,string>>> pii;

int main(){
    int n,m,a,b;
    string s;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pii tmp, ans;
    //vector<pair<int,pair<int,pair<int,string>>>> v;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s>>a>>b;
        pq.push(make_pair(b,make_pair(a,make_pair(i,s))));
    }
    
    //sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++){
        if(v[i].first==v[i+1].first && v[i].second.first==v[i+1].second.first){
            cout<<"Kamu jodoh ya "<<v[i].second.second.second<<" - "<<v[i].first<<" && "<<v[i+1].second.second.second<<" - "<<v[i+1].first<<"\n";
            return 0;
        }
    }
    /*
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second.second<<" "<<v[i].second.second.first<<"\n";
    }
    */
    if(m==n) cout<<"Full senyum deck\n";
    else cout<<"Pasien selanjutnya adalah: "<<v[m].second.second.second<<" - "<<v[m].first<<"\n";
}
