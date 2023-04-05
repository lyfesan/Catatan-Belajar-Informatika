#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    long long q, id, n, m;
    cin>>q;
    priority_queue<pair<long long, long long>>h_player;
    vector<pair<long long, long long>>l_player;
    vector<pair<long long, long long>>hasil;
    for (long long i=0; i<q; i++) {
        cin>>id;
		cin>>n>>m;
        bool playerExists=false;
        while (!h_player.empty() && !playerExists) {
            pair<long long, long long>top=h_player.top();
            h_player.pop();
            if (top.second==id) {
                top.first+=500*n-200*m;
                h_player.push(top);
                playerExists=true;
            }else{
                l_player.push_back(top);
            }
        }
        if(!playerExists) {
            h_player.push({500*n-200*m, id});
        }
        for (const auto& p:l_player) {
            h_player.push(p);
        }
        hasil.push_back(h_player.top());
        l_player.clear();
    }
    for (const auto& p:hasil) {
        cout<<p.second<<" "<<p.first<<'\n';
    }
    return 0;
}
