#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,x;
int arr[101];
int dp[2][1000100];
int iter(int x){
    // int k=n%2;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=x;j++){
            dp[i%2][j]=0;
            if(j==0){
                dp[i%2][j]=1;
                // cout<<dp[i%2][j]<<" ";
                continue;
            }
            else if(j-arr[i]>=0)dp[i%2][j]=(dp[i%2][j]+dp[i%2][j-arr[i]])%mod;
            if((i+1)<n)dp[i%2][j]=(dp[i%2][j]+dp[(i+1)%2][j])%mod;

            dp[i%2][j]%=mod;
            // cout<<dp[i%2][j]<<" ";
        }
        // cout<<"\n";
        
    }
    return dp[0][x];
}
void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,0,sizeof(dp));
    cout<<iter(x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}