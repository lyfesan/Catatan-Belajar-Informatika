#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    string s;
    int x;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9') {    
            st.push(s[i]-'0');
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
            x=st.top();
            st.pop();
            if(s[i]=='+') x=st.top()+x;
            else if(s[i]=='-') x=st.top()-x;
            else if(s[i]=='*') x=st.top()*x;
            st.pop();
            st.push(x);
        }
    }
    cout<<st.top()<<"\n";
}