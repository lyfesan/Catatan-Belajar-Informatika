#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,k,cnt=0;
    string x;
    vector<string> v;
    cin>>n>>k;
    while(n--){
        cin>>x;
        v.push_back(x);
    }
    for(ll i=0;i<v.size();i++){
        for(ll j=0;j<v.size();j++){
            if(i==j) continue;
            if(stoll(v[i]+v[j])%k==0) cnt++;
        }
    }
    cout<<cnt<<'\n';
}