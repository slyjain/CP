#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int x,y;
vector<vector<int>>g;
int rec(int i){
    int ans=0;
    if(dp[i]!=-1){
        return dp[i];
    }
    for(auto v:g[i]){
        ans=1+max(rec(v));
    }
    return dp[i]=ans;
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
    }
    int mx=0;
    for(int i=1;i<=n;i++)mx=max(rec(1),mx);
    cout<<mx;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}