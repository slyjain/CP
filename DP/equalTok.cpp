#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int dp[1001][1001][2];
int rec(int level,int depth,int seenk){
    if(depth>k||depth<0){
        return 0;
    }
    if(level==n){
        if(depth==0 && seenK==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    //cache check
    if(dp[level][depth][seenk]!=-1){
        return dp[level][depth][seenk];
    }

    //compute
    int ans=rec(level+1,depth+1,seenk||(depth+1)==k)+rec(level+1,depth-1,seenk);

    dp[level][depth][seenk]=ans;
    return dp[level][depth][seenk];

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