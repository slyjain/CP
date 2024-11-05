#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[10010];
int dp[1001][1001];
int rec(int l,int r){
    //pruning

    //base case
    if(r==l+1){
        return 0;
    }

    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //compute
    int ans=1e9;
    for(int p=l+1;p<r;p++){
        ans=min(ans,arr[r]-arr[l]+rec(l,p)+rec(p,r));
    }
    //save and return
    return dp[l][r]=ans;
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}