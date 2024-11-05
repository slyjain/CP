#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int dp[1001][1001];
int rec(int level,int depth){
    if(depth>k||depth<0){
        return 0;
    }
    if(level==n){
        if(depth==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    //cache check
    if(dp[level][depth]!=-1){
        return dp[level][depth];
    }

    //compute
    int ans=rec(level+1,depth+1)+rec(level+1,depth-1);

    dp[level][depth]=ans;
    return dp[level][depth];

}
void solve(){
    cin>>n>>k;
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