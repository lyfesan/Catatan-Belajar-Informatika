#include<bits/stdc++.h>
using namespace std;

bool sortcondition(const pair<int, pair<int,string>>& a, const pair<int, pair<int,string>>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second.first > b.second.first);
}

int main(){
    int n,m,a,b;
    string s;
    //priority_queue<int,int,string, vector<pair<int,pair<int,string>>>, greater<int,int,string>> pq;
    vector<pair<int,pair<int,string>>> v;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s>>a>>b;
        v.push_back(make_pair(b,make_pair(a,s)));
        //cin>>v[i].second.second>>v[i].second.first>>v[i].first;
    }

    if(m==n){cout<<"Full senyum deck\n";return 0;}
    
    sort(v.begin(),v.end(),sortcondition);
    
    for(int i=0;i<n-1;i++){
        if(v[i].first==v[i+1].first && v[i].second.first==v[i+1].second.first){
            cout<<"Kamu jodoh ya "<<v[i].second.second<<" - "<<v[i].first<<" && "<<v[i+1].second.second<<" - "<<v[i+1].first<<"\n";
            return 0;
        }
    }
    
    cout<<"Pasien selanjutnya adalah: "<<v[m].second.second<<" - "<<v[m].first<<"\n";
}