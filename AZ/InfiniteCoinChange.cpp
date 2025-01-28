#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     int n,m;
     cin>>n>>m;
     vector<int>val(n+1);
     for(int i=0;i<n;i++){
        cin>>val[i+1];
     }
     int dp[n+1][m+1];
     for(int i=n;i>=1;i--){
        for(int j=0;j<=m;j++){dp[i][j]=0;
            if(j%val[i]==0){
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=dp[i+1][j];
            if(j-val[i]>=0){
                dp[i][j]|=dp[i][j-val[i]];
            }
        }
     }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
    return 0;
}