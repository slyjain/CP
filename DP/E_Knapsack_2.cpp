#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
int w[101],v[101];
int dp[101][1010];
int rec(int level,int profit){
    //prunning
    // if(profit<0){
    //     return 1e9;
    // }
    //base case
    if(level==n&&profit==0){
        return 0;
    }
    else if(level==n){
        return 1e9;
    }
    //cache check
    if(dp[level][profit]!=-1){
        return dp[level][profit];
    }
    //tranisitions
    
    int ans=(rec(level+1,profit-v[level])+w[level]);
    // cout<<ans<<" ";
    ans=min(rec(level+1,profit),ans);
    // cout<<ans<<"\n";
    //save and return
    return dp[level][profit]=ans;
}
// int check(int pro){
//     if(rec(0,pro)<=x){
//         return true;
//     }
//     return false;
// }
void solve(){
    cin>>n>>x;
    cout<<n<<" "<<x;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    int ans=0;
    
    memset(dp,-1,sizeof(dp));
    
    for(int i=1;i<=10010;i++){
        if(rec(0,i)<=x){ans=i;
        // cout<<rec(0,i)<<"\n";
        }
    }
    // cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}