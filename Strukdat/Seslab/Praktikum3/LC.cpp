#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> item;
    map<string,int> tmp;
    string s,bf;
    int t,n,cnt,num,temp;
    while(1){
        getline(cin,s);
        if(s=="#") break;
        if(item.find(s)==item.end()) item[s]=1;
        else item[s]++;
    }
    while(n--){
        cnt=0;
        cin>>num;
        cin>>t;
        for(int i=0;i<t;i++){
            //cin>>bf;
            //getline(cin,bf);
            getline(cin,s);
            cin>>temp;
            tmp[s]=temp;
            if(i==0) temp*num-item[s]<0 ? cnt = (float)item[s]/temp : cnt = temp;
            else cnt*temp-item[s]<0 ? cnt = (float)item[s]/temp : cnt = cnt;
        }
        for(auto i = tmp.begin();i != tmp.end();i++){
            item[i->first] -= i->second;
        }
        if(cnt==num) cout<<"Material Fulfilled, Crafting "<<cnt<<"!\n";
        else cout<<"Insufficient Material, can only craft "<<cnt<<".\n";
    }
}