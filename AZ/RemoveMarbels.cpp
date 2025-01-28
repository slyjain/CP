#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a;
vector<vector<vector<int>>>dp;
int n;
int rec(int l,int r,int latch){
    //pruning
    if(l>r){
        return 0;
    }
    //base case
    if(l==r){
        return (latch+1)*(latch+1);
    }
    //cache check;
    if(dp[l][r][latch]!=-1){
        return dp[l][r][latch];
    }
    //compute
    int ans=0;
    ans=max(ans,rec(l+1,r,0)+(latch+1)*(latch+1));
    for(int mid=l+1;mid<=r;mid++){
        if(a[l]==a[mid]){
            ans=max(ans,rec(l+1,mid-1,0)+rec(mid,r,latch+1));
        }
    }
    //save and return
    return dp[l][r][latch]=ans;
}
void solve(){
    
    cin>>n;
    a.resize(n);
    dp.assign(n,vector<vector<int>>(n,vector<int>(n,-1)));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rec(0,n-1,0);
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}