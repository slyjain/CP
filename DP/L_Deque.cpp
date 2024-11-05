#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[3001];
int dp[3001][3001];
int rec(int l,int r){
    //base case
    if(l==r){
        return arr[l];
    }
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //compute
    int ans=max(arr[l]-rec(l+1,r),arr[r]-rec(l,r-1));
    //save and return 
    return dp[l][r]=ans;
   
}
void solve(){
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