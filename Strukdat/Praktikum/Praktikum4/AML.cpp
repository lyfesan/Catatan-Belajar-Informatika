#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,x;
    cin>>n;
    vector<int> adj[n];
    bool op[n]={false},y=true;
    op[0]=true;
    for(int ll=0;ll<n;ll++){
        cin>>t;
        for(int i=0;i<t;i++){
            cin>>x;
            if(op[ll]) op[x]=true;
            adj[ll].push_back(x);
        }
    }
    for(int i=0;i<n;i++){
        if(op[i]==true){
            for(auto ll:adj[i]){
                op[ll]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(op[i]==false){y=false;break;}
    }
    if(y) cout<<"Para peserta LBH berhasil keluar!\n";
    else cout<<"Para peserta LBH terjebak selamanya.\n";
}