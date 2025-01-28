#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n,m;
vector<vector<int>>g,dp;

int rec(int r,int c){
    //pruning
    if(r<0||c<0)return 0;
    //base case
    if(r==0||c==0)return g[r][c];
    //cache check
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    //transitions
    int ans=0;
    if(g[r][c]==1){
        ans=1+min({rec(r-1,c),rec(r-1,c-1),rec(r,c-1)});
    }
    //save and return
    return dp[r][c]=ans;
}
void solve(){
     
     cin>>n>>m;
     
     g.assign(n,vector<int>(m,0));
     dp.assign(n,vector<int>(m,-1));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
     }
     int mx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mx<rec(i,j)*rec(i,j)){
                mx=rec(i,j)*rec(i,j);
                // cout<<i<<" "<<j<<"\n";
            }
        }
    }
    cout<<mx<<"\n";
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