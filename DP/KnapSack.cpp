#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,w;
vector<pair<int,int>>wv;
int dp[101][100100];
int rec(int level,int wtRem){
    //prunning
    if(wtRem<0){
        return -1e18;
    }
    //base case
    if(wtRem==0){
        return 0;
    }
    if(level==n){
        return 0;
    }
    //cache check
    if(dp[level][wtRem]!=-1){
        return dp[level][wtRem];
    }
    //compute
    int ans=-1e18;
    if(wtRem>=wv[level].first){
        ans=max(ans,rec(level+1,wtRem-wv[level].first)+wv[level].second);
    }
    ans=max(ans,rec(level+1,wtRem));
    //save and return 
    return dp[level][wtRem]=ans;
}
void solve(){
    cin>>n>>w;
    for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    wv.push_back({x,y});
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,w);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}