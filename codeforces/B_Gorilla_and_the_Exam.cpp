#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE

void solve(){
     int n,k;
     cin>>n>>k;
     map<int,int>mp;
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
     }
    //  vector<pair<int,int>>p;
    // map<int,int>ump;
    // deque<pair<int,int>>p;
     vector<pair<int, int>> dq;
    for (auto x : mp) {
        dq.push_back({x.second, x.first});
    }

    sort(dq.begin(), dq.end());

    
    deque<pair<int, int>> p(dq.begin(), dq.end());
     while(!p.empty()&&k>=p.front().first&&p.size()>1){
        int t=p.front().first;
        k-=t;
        p.back().first+=t;
        p.pop_front();
     }
    //  cout<<"----------\n";
    //  for(auto x:p){
    //     cout<<x.first<<" "<<x.second<<"\n";
    // }
     cout<<p.size()<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}