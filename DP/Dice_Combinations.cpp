#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int mod=1e9+7;
int dp[1000100];
int rec(int level){
    //prunning
    if(level<0){
        return 0;
    }
    //base case
    if(level==0){
        return 1;
    }
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //compute
    int ans=0;
    for(int i=1;i<=6;i++){
        ans=(ans+rec(level-i))%mod;
    }
    
    //save and return 
    return dp[level]=ans;
}
int iter(int level){
    //base case
    if(level==0){
        return 1;
    }
    dp[0]=1;
    for(int i=1;i<=level;i++){
        dp[i]=0;
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
    }
    return dp[level];
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<iter(n);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}