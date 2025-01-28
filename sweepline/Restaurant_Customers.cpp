#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n;
    vector<pair<int,int>>events;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        events.push_back({l,1});
        events.push_back({r,-1});
    }
    sort(events.begin(),events.end());
    int cnt=0;
    int ans=0;
    int sz=events.size();
    for(int i=0;i<sz;i++){
        // cout<<cnt<<"\n";
        cnt+=events[i].second;
        if(i+1<sz&&events[i+1].first!=events[i].first){
            ans=max(ans,cnt);
        }
        
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}