#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int arr[1001][1001];
int dp[501][501][501];
int dx[]={0,1};
int dy[]={1,0};
bool check(int i,int j){
    if(i<n&&i>=0&&j<n&&j>=0){
        return true;
    }
    return false;
}
int rec(int i,int j,int a,int b){
    //base case
    if(i==n-1&&j==m-1){
        return 0;
    }
    //cache check
    if(dp[i][j][a]!=-1){
        return dp[i][j][a];
    }
    // cout<<"here";
    //transition
    int ans=0;
    for(int k1=0;k1<2;k1++){
        for(int k2=0;k2<2;k2++){
            int ni,nj,na,nb;
            ni=i+dx[k1];
            nj=j+dy[k1];
            na=a+dx[k2];
            nb=ni+nj-na;
            if(check(ni,nj)&&check(na,nb)){
                // cout<<"here";
                int t=arr[ni][nj]+arr[na][nb]+rec(ni,nj,na,nb);
                if(ni==na){
                    t-=arr[ni][nj];
                }
                ans=max(t,ans);
                
            }
        }
    }
    // cout<<ans;
    //save and return 
    return dp[i][j][a]=ans;

    
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0,0);
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}