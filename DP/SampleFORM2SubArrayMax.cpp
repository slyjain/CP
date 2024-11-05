#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,arr[1001],dp[1001][101];
int rec(int level,int partRem){
    //prunning
    if(partRem<0){
        return -1e9;
    }
    //base case
    if(level==-1){
        if(partRem==0){
            return 0;
        }
        if( partRem>0){
            return  -1e9;
        }
    }
    //cache check
    if(dp[level][partRem]!=-1){
        return dp[level][partRem];
    }
    //compute/transitions
    int ans=-1e9;
    int maxSeen=arr[level];
    for(int i=level-1;i>=-1;i--){
        ans=max(ans,rec(i,partRem-1)+maxSeen);
        maxSeen=max(maxSeen,arr[i]);
    }
    //save and return
    return dp[level][partRem]=ans;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,k);
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}