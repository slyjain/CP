#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int mod=1e9+7;
// int dp[2001][2001][2001];
vector<vector<vector<int>>>dp;
int rec(int level,int parts,int prev){
    //base case
    if(level==n){
        if(parts==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    //cache check
    if(dp[level][parts][prev]!=-1){
        return dp[level][parts][prev];
    }
    //transitions
    int ans=0;
    ans=rec(level+1,parts,prev);
    ans%=mod;
    for(int i=0;i<m;i++){
        if(i!=prev){
            ans+=rec(level+1,parts-1,i);
        }
        ans%=mod;
    }
    
    //save and return 
    return dp[level][parts][prev]=ans;
}
void solve(){
    cin>>n>>m>>k;
    // int mx=0;
    dp.assign(n+1,vector<vector<int>>(k+1,vector<int>(m+1,-1)));
    int ans=0;
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++){
        ans+=rec(0,k,i);
        ans%=mod;
    }
    cout<<ans<<"\n";
        
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}