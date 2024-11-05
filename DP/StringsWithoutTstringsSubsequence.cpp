#include<bits/stdc++.h>
using namespace std;
#define int long long
string t;
int n,m;
int dp[1001][1001];
int rec(int level,int match){
    //prunning
    if(match==m){
        return 0;
    }
    //base case
    if(level==n){
        return 1;
    }
    //cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    //compute
    int ans=0;
    ans=rec(level+1,match+1)+rec(level+1,match);
    return dp[level][match]=ans;

}
void solve(){
    cin>>n;
    cin>>t;
    m=t.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}