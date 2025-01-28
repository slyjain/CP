#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>>wt;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        wt.push_back({x,y});
    }
    for(int i=1;i<=d;i++){
        int mx=0;
        for(int j=0;j<n;j++){
            mx=max(mx,wt[j].first*(wt[j].second+i));
        }
        cout<<mx<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}