#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    priority_queue<pll> pq;
    vector<pll> v;
    ll q,id,n,m;
    cin>>q;
    while(q--){
        cin>>id>>n>>m;
        bool y=false;
        while (!pq.empty() && !y){
            pll top=pq.top();
            pq.pop();
            if(top.second==id){
                top.first+=500*n-200*m;
                pq.push(top);
                y=true;
            }
            else v.push_back(top);
        }
        if(!y) pq.push(make_pair(500*n-200*m,id));
        for (const auto& p:v) {
            pq.push(p);
        }
        cout<<pq.top().second<<" "<<pq.top().first<<"\n";
        v.clear();
    }
}