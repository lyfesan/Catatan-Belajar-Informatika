#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    string s1, s2;
    map<string, string> user;
    map<string, map<string, vector<string>>> msg;
    cin >>n>>q;
    while(n--){
        cin>>s1>>s2;
        user[s1] = s2;
    }

    while(q--){
        string fr,sd,m;
        cin>>fr>>sd;
        getline(cin, m);
        if(user.find(fr)==user.end() || user.find(sd)==user.end()) continue; 
        msg[sd][fr].push_back(m); 
    }
    //Print message
    for(auto it = user.begin(); it != user.end(); it++){
        if(msg[it->first].empty()) continue;
        string dest = it->first;
        cout<<"==========="<<endl;
        cout<<"Mail: "<< it->second<<endl; 
        
        for(auto j = msg[dest].begin(); j != msg[dest].end(); j++) {
            string sender = j->first;
            //if(user[sender]==it->second) continue;
            cout<<"From: "<<user[sender]<<endl;
        
            for(int i = 0; i < msg[dest][sender].size(); i++) {
                cout<<">> "<<msg[dest][sender][i]<<endl; 
            }
        }   
    }
}