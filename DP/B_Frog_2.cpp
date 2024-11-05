#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int h[100010];
int dp[100010];
int rec(int level){
    // pruning
    if(level<0){
        return 1e18;
    }
    //base case
    if(level==0){
        return 0;
    }
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    // compute
    int ans=1e18;
    for(int i=1;i<=k;i++){
        if(level-i>=0){
            ans=min(ans,abs(h[level]-h[level-i])+rec(level-i));
        }
        
    }
    // save and return
    return dp[level]=ans;

}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}