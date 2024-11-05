#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y;
int dp[1001][1001];
int rec(int i,int j){
    if(i==0&&j==0){
        return 0; 
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int win=0;
    for(int k=1;k<=i;k++){
        if(rec(i-k,j)==0){
            win=1;
        }
    }
    for(int k=1;k<=j;k++){
        if(rec(i,j-k)==0){
            win=1;
        }
    }
    for(int k=1;k<min(i,j);k++){
        if(rec(i-k,j-k)==0){
            win=1;
        }
    }
    return dp[i][j]=win;
}
void solve(){
    cin>>x>>y;
    memset(dp,-1,sizeof(dp));
    cout<<rec(x,y)<<"\n";
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