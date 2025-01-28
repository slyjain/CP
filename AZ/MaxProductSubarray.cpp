#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int sign(int x) {
    return (x == 0) ? 0 : (x > 0 ? 1 : -1);
}

void solve(){
     int n;
     cin>>n;
     vector<int>a(n);
     int mx=-1e18;
     for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
     }
     vector<pair<int,int>>dp(n,make_pair(0,0));
     for(int i=0;i<n;i++){
        if(sign(a[i])==1){
            dp[i].first=a[i];
            dp[i].second=0;
        }else if(sign(a[i])==-1){
            dp[i].first=0;
            dp[i].second=a[i];
        }
     }
     for(int i=1;i<n;i++){
        if(a[i-1]!=0){
            if(sign(a[i])==1){
                dp[i].first=max(dp[i-1].first*a[i],dp[i].first);
                dp[i].second=min(dp[i-1].second*a[i],dp[i].second);
                
            }else if(sign(a[i])==-1){
                dp[i].second=min(dp[i-1].first*a[i],dp[i].second);
                dp[i].first=max(dp[i-1].second*a[i],dp[i].first);
            }
            mx=max({mx,dp[i].first,dp[i].second});
        }
     }
    //  for(int i=0;i<n;i++){
    //     cout<<dp[i].first<<"\t";
    //  }
    //  cout<<"\n";NS
    //  for(int i=0;i<n;i++){
    //     cout<<dp[i].second<<"\t";
    //  }
    //  cout<<"\n";
     cout<<mx<<"\n";

     
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