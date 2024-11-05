#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[401];
int dp[401][401];
int parr[401];
int p(int l,int r){
    if(l==r){
        return arr[l];
    }
    if(l==0){
        return parr[r];
    }
    return parr[r]-parr[l-1];
}
int rec(int l,int r){
    //base case
    if(l==r){
        return 0;
    }
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //compute
    int ans=1e18;
    for(int i=l;i<r;i++){
        ans=min(ans,rec(l,i)+rec(i+1,r)+p(l,i)+p(i+1,r));
    }
    //save and return 
    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        parr[i]=arr[i];
        if(i){
            parr[i]+=parr[i-1];
        }
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