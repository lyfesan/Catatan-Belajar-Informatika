#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(st.empty() || s[i]=='[' || s[i]=='(' || s[i]=='{') st.push(s[i]);
        else if(s[i]==']' && st.top()=='[' || s[i]==')' && st.top()=='(' || s[i]=='}' && st.top()=='{') st.pop();
    }
    if(st.empty()) cout<<"valdi\n";
    else cout<<"unvaldi\n";
}