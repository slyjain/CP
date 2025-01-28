#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n,m,k;
const int nv=-1e9;
vector<vector<int>>a;
vector<vector<vector<int>>>dp;
// vector<vector<vector<bool>>>vis;
const int mod=1000000007;
int rec(int r,int c,int sm){
    //base case
    if(r==0){
        // cout<<r<<" "<<c<<" "<<sm+a[r][c]<<"\n";
        // vis[r][c][sm%k]=true;
        return (sm)%(k)==0?sm:-1;
    }
    //cache check
    if(dp[r][c][sm%(k)]!=-1){
        return dp[r][c][sm%(k)];
    }
    
    //transitions
    int ans=-1;
    if(c+1<m){
        int right=rec(r-1,c+1,sm+a[r-1][c+1]);
        if(right!=-1){
            ans=right;
        }
    }
    if(c-1>=0){
        int left=rec(r-1,c-1,sm+a[r-1][c-1]);
        if(left!=-1){
            ans=max(ans,left);
        }
    }
    
    return dp[r][c][sm%k]=ans;
}
    
void solve(){
    cin>>n>>m>>k;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }     
    a.assign(n,vector<int>(m,0));
    dp.assign(n,vector<vector<int>>(m,vector<int>(k,-1)));
    // vis.assign(n,vector<vector<bool>>(m,vector<bool>(k,false)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=s[i][j]-'0';
            // cout<<a[i][j]<<" ";
        }
        // cout<<"\n";
    }
    int ans=-1;
    for(int i=0;i<m;i++){
        ans=max(ans,rec(n-1,i,a[n-1][i]));
    }
    cout<<ans<<"\n";
    
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