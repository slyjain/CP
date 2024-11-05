#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
char arr[1001][1001];
int dp[1001][1001];
int rec(int i,int j){
    if(i<0||j<0){
        return 0;
    }
    //prunning
    if(arr[i][j]=='#'){
        return 0;
    }
    //base case
    if(i==0&&j==0){
        return 1;
    }
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //compute
    int ans=(rec(i-1,j)+rec(i,j-1))%mod;
    return dp[i][j]=ans;

}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,m-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}