#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
char arr[1001][1001];
int dp[1001][1001];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            // cout<<arr[i]
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(i==0&&i==j&&arr[i][j]!='*'){
                dp[i][i]=1;
            }else if(arr[i][j]!='*'){
                if(i>0&&arr[i-1][j]!='*'){
                    dp[i][j]=dp[i][j]+dp[i-1][j];
                }
                if(j>0&&arr[i][j-1]!='*'){
                    dp[i][j]=dp[i][j]+dp[i][j-1];
                }
            }
            // cout<<dp[i][j]<<" ";
            dp[i][j]%=mod;
            
        }
        // cout<<"\n";
    }
    cout<< dp[n-1][n-1];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}