#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
char a[1001],b[1001];
int dp[1001][1001];
int rec(int i,int j){
    //pruning
    //base case
    if(i>=n||j>=m){
        return 0;
    }
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //compute
    int ans=0;
    ans=max(rec(i+1,j),ans);
    ans=max(rec(i,j+1),ans);
    if(a[i]==b[j]){
        ans=max(1+rec(i+1,j+1),ans);
    }
    //save and return 
    return dp[i][j]=ans;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    memset(dp,-1,sizeof(dp));
     cout<<rec(0,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}