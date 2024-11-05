#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[100010];
int mx=0;
int dp[100010];
vector<int>mp(100010,0);
int rec(int level){
    //base case
    if(level>=(mx+1)){
        return 0;
    }
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //transition
    int ans=rec(level+2)+mp[level]*level;
    ans=max(ans,rec(level+1));
    return dp[level]=ans;
}

void solve(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
        mx=max(mx,arr[i]);
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0);
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}