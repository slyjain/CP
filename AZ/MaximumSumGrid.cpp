#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE

int kdane(vector<int>&kd){
    int last=kd[0];
    int curr=kd[0];
    int mx=curr;
    int n=kd.size();
    for(int i=1;i<n;i++){
        curr=kd[i]+max(1LL*0,last);
        last=curr;
        mx=max(mx,curr);
    }
    return mx;
}
void solve(){
     int n,m;
     cin>>n>>m;
     vector<vector<int>>g;
     if(n>=m){
        g.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
            }
        }
        vector<vector<int>>pg(n,vector<int>(m+1,0));
     for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            pg[i][j]=g[i][j-1];
            if(j>1){
                pg[i][j]+=pg[i][j-1];
            }
            // cout<<pg[i][j]<<"\t";
        }
        // cout<<"\n";
     }
     int ans=-1e18;
     for(int c1=1;c1<=m;c1++){
        for(int c2=c1;c2<=m;c2++){
            vector<int>kd;
            
            for(int i=0;i<n;i++){
                kd.push_back(pg[i][c2]-pg[i][c1-1]);
            }
            ans=max(ans,kdane(kd));

        }
     }
     cout<<ans<<"\n";
     }else{
        g.resize(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[j][i];
                // cout<<g[i][j]<<" ";
            }
            // cout<<"\n";
        }
        vector<vector<int>>pg(m,vector<int>(n+1,0));
     for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            pg[i][j]=g[i][j-1];
            if(j>1){
                pg[i][j]+=pg[i][j-1];
            }
            // cout<<pg[i][j]<<"\t";
        }
        // cout<<"\n";
     }
     int ans=-1e18;
     for(int c1=1;c1<=n;c1++){
        for(int c2=c1;c2<=n;c2++){
            vector<int>kd;
            
            for(int i=0;i<m;i++){
                kd.push_back(pg[i][c2]-pg[i][c1-1]);
            }
            ans=max(ans,kdane(kd));

        }
     }
     cout<<ans<<"\n";
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