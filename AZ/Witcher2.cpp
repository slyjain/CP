#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n,m;
const int nv=-10000000000;
vector<vector<int>>g;
vector<vector<pair<int,int>>>dp;
pair<int,int>rec(int r,int c){
    //prunning
    if(r<0||c<0){
        return make_pair(-1e18,-1e18);
    }
    //base case
    if(r==0&&c==0){
        return make_pair(g[0][0],g[0][0]);
    }
    //cache check
    if(dp[r][c].F!=nv&&dp[r][c].S!=nv){
        return dp[r][c];
    }
    //transisitons
    pair<int,int>t1={nv,nv};
    pair<int,int>t2={nv,nv};

    if(r-1>=0){
        t1=rec(r-1,c);
        t1.F+=g[r][c];
    if(t1.F<t1.S){
        t1.S=t1.F;
    }
    }
    if(c-1>=0){
        t2=rec(r,c-1);
        t2.F+=g[r][c];
        if(t2.F<t2.S){
            t2.S=t2.F;
        }
    }
    pair<int,int>ans;
    if(t2.S<t1.S){
        ans=t1;
    }else if(t2.S>t1.S){
        ans=t2;
    }else{
        if(t2.F>t1.F){
            ans=t2;
        }else{
            ans=t1;
        }
    }
    
    //save and return 
    return dp[r][c]=ans;
}
void solve(){
  cin>>n>>m;
  g.assign(n,vector<int>(m,0));
  dp.assign(n,vector<pair<int,int>>(m,{nv,nv}));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>g[i][j];
    }
  }   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<rec(i,j).F<<" "<<rec(i,j).S<<"\t";
        }
        // cout<<"\n";
    }
    // int 
  if(rec(n-1,m-1).S>0){
    cout<<1<<"\n";
  }else{
    cout<<abs(rec(n-1,m-1).S)+1<<"\n";
  }

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