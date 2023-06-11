#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<string> st;
    deque<string> dq;
    string s;
        
    while(cin>>s){
        if(s=="#") break;
        dq.push_back(s);
    }
    while(cin>>s){
        if(s==dq.front()) dq.pop_front();
        else st.push(s);
    }
    while(!st.empty()){
        if(st.top()==dq.back()){
            dq.pop_back();
            st.pop();
        }
        else break;
    }

    if(dq.empty() || st.empty()) cout<<"Bisa menang ini mah, gas mainin aja masbro\n";
    else cout<<"Gabisa sumpah, game ini red flag banget sih\n";
}

