#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m, x,y;
vector<vector<char>>a;
int dp[1010][2];
vector<int>whiteCount,blackCount,prw,prb;
int cols[1010];
int p(int l,int r,int col){
    if (col == 0) {  // white
    return (l == 0) ? prw[r] : prw[r] - prw[l - 1];
} else {  // black
    return (l == 0) ? prb[r] : prb[r] - prb[l - 1];
}

    
    
}

int rec(int level,int col){
    //base case
    if(level==-1){
        return 0;
    }
    //cache check
    if(dp[level][col]!=-1){
        return dp[level][col];
    }
    //compute
    int ans=1e9;
    
    for(int i=x;i<=y;i++){
        if(level-i>=-1){
            // ans=min(ans,rec(level-i,1-col)+p(level-i+1,level,col));
            if(ans>rec(level-i,1-col)+p(level-i+1,level,col)){
                for(int j=level-i+1;j<=level;j++){
                    cols[j]=col;
                }
                ans=rec(level-i,1-col)+p(level-i+1,level,col);
            }

        }
        
    }
    
    //save and return
    return dp[level][col]=ans;

}
void solve(){
    cin>>n>>m>>x>>y;
    a.resize(n);
    for(int i=0;i<n;i++){
        a[i].resize(m);
    }
    int wc=0;
    for(int i=0;i<n;i++){
        wc=0;
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            // cout<<a[i][j];
        }
        // cout<<"\n";
        
    }
    whiteCount.resize(m);
    blackCount.resize(m);
    prw.resize(m);
    prb.resize(m);
    for(int i=0;i<m;i++){
        wc=0;
        for(int j=0;j<n;j++){
            if(a[j][i]=='.')wc++;
            
        }
        whiteCount[i]=wc;
        
        blackCount[i]=n-wc;
        // cout<<wc<<" "<< n-wc<<"\n";
        prw[i]=wc;
        prb[i]=n-wc;
        if(i)prw[i]+=prw[i-1];
        if(i)prb[i]+=prb[i-1];
        
    }
    memset(dp,-1,sizeof(dp));
    // for(int i=0;i<m;i++){
    //     cout<<rec(i,0)<<" "<<rec(i,1)<<"\n";
    // }
    
    int ans=1e9;
    if(rec(m-1,0)<ans){
        cols[m-1]=0;
        ans=rec(m-1,0);
    }
    if(ans>rec(m-1,1)){
        cols[m-1]=1;
        ans=rec(m-1,1);
    }
    // for(int i=0;i<m;i++){cout<<cols[i]<<" ";}
    cout<<"\n";
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}