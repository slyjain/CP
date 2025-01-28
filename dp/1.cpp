#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[101];
int t[101],s[101];
int dp[101][101][101];
int n,k,x;
//n items, k slots, x time
int rec(int level,int itemRem,int timeRem){
    //prunning
    if(itemRem<=0||timeRem<=0){
        return 0;
    }
    //base case
    if(level==n){
        return 0;
    }
    //cache check
    if(dp[level][itemRem][timeRem]!=-1){
        return dp[level][itemRem][timeRem];
    }
    //transitions
    int ans=0;
    ans=rec(level+1,itemRem,timeRem);
    ans=max(ans,rec(level+1,itemRem-1,timeRem-t[level])+s[level]);
    return dp[level][itemRem][timeRem]=ans;
}
void solve(){
    cin>>n>>k>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,k,x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}