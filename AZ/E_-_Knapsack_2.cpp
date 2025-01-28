#include<bits/stdc++.h>
using namespace std;
#define int long long
int p[101],wi[101];
const int INF=2e9;
int n,w;
int dp[101][100010];
int rec(int level,int profitRem){
    //prunning
    if(profitRem<0)return INF;
    //base case
     if(level==n){
        if(profitRem==0)return 0;
        else return INF;
     }
     //cache check
     if(dp[level][profitRem]!=-1){
        return dp[level][profitRem];
     }
     //transitions
     int ans =rec(level+1,profitRem);
     ans=min(ans,rec(level+1,profitRem-p[level])+wi[level]);
     return dp[level][profitRem]=ans;

}
void solve(){
    
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>wi[i]>>p[i];
    }
    int ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<100010;i++){
        if(rec(0,i)<=w){
            ans=i;
        }
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}