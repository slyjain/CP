#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[201][201];
int n,m,k;
int dp[201][201][401];
vector<vector<pair<int,int>>>backArray;
int rec(int i,int j,int l){

    //base case
    if(i==0&&j==0){
        return 1;
    }
    //cache check
    if(dp[i][j][l]!=-1){
        return dp[i][j][l];
    }
    //compute
    int ans=0;
    if(arr[i-1][j]==0&&i>=1){
        
        ans+=rec(i-1,j,l);
    }
    else if(arr[i-1][j]==1){
        if(l>=1&&i>=1){
            ans+=rec(i-1,j,l-1);
        }
        
    }
    if(j>=1&&arr[i][j-1]==0){
        ans+=rec(i,j-1,l);
    }
    else if(arr[i][j-1]==1){
        if(l>=1&& j>=1){
            ans+=rec(i,j-1,l-1);
        }
        
    }
    return dp[i][j][l]=ans;

}
void solve(){
    cin>>n>>m>>k;
    // backArray.assign(n,vector<pair<int,int>>(m,{0,0}));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }        
    }
    
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(n-1,m-1,k)<<"\n";
    // for(int l=0;l<=k;l++){
    //     for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<rec(i,j,l)<<" "; 
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n\n";
    // }
    
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