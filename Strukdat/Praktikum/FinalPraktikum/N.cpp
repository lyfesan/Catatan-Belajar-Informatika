#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt1=1,n,ans=0,x;
    cin>>n;
    while(n--){
        cin>>x;
        if(x==1){
            cnt1++;
            ans+=cnt1;
        }
        else ans++;
    }
    cout<<ans<<"\n";
}