#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n;
int p[101];
int dp[101][101];
int rec(int l,int r){
    if(r<l+2){
        return 0;
    }
    if(l+2==r){
        return p[l]*p[l+1]*p[r];
    }
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //transitions
    int ans=LLONG_MAX;
    for(int i=l+1;i<r;i++){
        ans=min(ans,rec(l,i)+rec(i,r)+p[l]*p[i]*p[r]);
    }
    return dp[l][r]=ans;
}
void solve(){
     
     cin>>n;
     memset(dp,-1,sizeof(dp));

     for(int i=1;i<=n;i++){
        cin>>p[i];
     }
     cout<<rec(1,n)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}