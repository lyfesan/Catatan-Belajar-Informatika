#include <bits/stdc++.h>
using namespace std;

void solve(multiset<int> &it, int n) {
	int maxi = 0;
	while (!it.empty()){
    	int cnt = it.count(*it.begin());   	 
    	maxi = max(maxi, cnt);   	 
    	it.erase(*it.begin());
	}
	if (n-maxi>=maxi){
    	if (n&1) cout<<1<<"\n";
        else cout<<0<<"\n";
	} 
    else cout<<maxi-(n-maxi)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int t,n,p;
	cin>>t;
	while (t--){
	    cin>>n;
        multiset<int> it;
        for(int i=0;i<n;i++){
            cin>>p;
            it.insert(p);
	    }
        solve(it,n);
	}
}