#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int dp[1001][1001];
int rec(int l,int r){
    //base case
    if(l==r){
        return 0;
    }
    if(l>r){
        return 0;
    }
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //transitions
    int ans=1e9;
    if(s[l]==s[r]){
        ans=rec(l+1,r-1);
    }
    ans=min(ans,rec(l+1,r)+1);
    ans=min(ans,rec(l,r-1)+1);
    //save and return
    return dp[l][r]=ans;

}
void solve(){
    cin>>s;
    n=s.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}