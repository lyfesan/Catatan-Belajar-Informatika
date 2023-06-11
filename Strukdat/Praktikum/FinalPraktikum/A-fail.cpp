#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,cnt;
    string s1,s2,s3,tmp;
    multimap<pair<string,string>,string> dat;
    set<pair<string,string>> fr;
    map<string,string> mp;
    cin>>n>>m;
    while(n--){
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    while(m--){
        cin>>s2>>s1;
        getline(cin,s3);
        if(mp.find(s1)!=mp.end() && mp.find(s2)!=mp.end()){
            fr.insert(make_pair(s1,s2));
            dat.insert(pair<pair<string,string>,string>(make_pair(s1,s2),s3));
        }
    }
    int cnt,cnt1,y;
    for(auto i:mp){
        cout<<"===========\n";
        cout<<"Mail: "<<i.second<<"\n";
        for(auto j:fr){
            if(j.first==i.first){
                cout<<"From: "<<mp[j.second]<<"\n";
                for(auto k:dat){
                    if(k.first.first==i.first && k.first.second==j.second){
                        cout<<">> "<<k.second<<"\n";
                    }
                }
            }    
        }
    }
}