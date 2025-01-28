#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n,m;

void solve(){
    cin>>n>>m;
    vector<vector<int>>g(n,vector<int>(m,0));
    // g.clear();
    // g.assign;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }  
    vector<vector<int>>pre(n,vector<int>(m,0));   
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1){
                pre[i][j]=g[i][j];
                if(i){
                    pre[i][j]=1+pre[i-1][j];
                }
            }else{
                pre[i][j]=0;
            }
            // cout<<pre[i][j]<<" ";
        }
        // cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1){
                int ans=pre[i][j];
                int minHeight=pre[i][j];
                for(int k=j;k>=0;k--){
                    minHeight=min(minHeight,pre[i][k]);
                    ans= max(ans,minHeight*(j-k+1));
                }
                dp[i][j]=ans;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<dp[i][j]<<" ";
            ans=max(ans,dp[i][j]);
        }
        // cout<<"\n";
    }
    cout<<ans<<"\n";

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