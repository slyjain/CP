#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,l;
char a[100],b[100],c[100];
int dp[100][100][100];
int rec(int i,int j,int k){
    //pruning
    //base case
    if(i>=n||j>=m||k>=l){
        return 0;
    }
    //cache check
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    //compute
    int ans=0;
    ans=max(rec(i+1,j,k),ans);
    ans=max(rec(i,j+1,k),ans);
    ans=max(ans,rec(i,j,k+1));
    if(a[i]==b[j]&&a[i]==c[k]){
        ans=max(1+rec(i+1,j+1,k+1),ans);
    }
    //save and return 
    return dp[i][j][k]=ans;
}
void solve(){
    cin>>n>>m>>l;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    for(int k=0;k<l;k++){
        cin>>c[k];
    }
    memset(dp,-1,sizeof(dp));
     cout<<rec(0,0,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}