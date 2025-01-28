#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c;
int n,m;
vector<vector<int>>dp;
int rec(int i,int j){
    //base case
    int k=i+j;
    if(k==n+m){
        return 0;
    }
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //computation
    int ans=1e18;
    if(i<n&&a[i]==c[k]){
        ans=min(ans,rec(i+1,j));
    }
    else if(i<n&&a[i]!=c[k]){
        ans=min(ans,rec(i+1,j)+1);
    }
    if(j<m&&b[j]==c[k]){
        ans=min(ans,rec(i,j+1));
    }
    else if(j<m&&b[j]!=c[k]){
        ans=min(ans,rec(i,j+1)+1);
    }
    //save and return
    return dp[i][j]=ans;

}
void solve(){
cin>>a>>b>>c;
n=a.length();
m=b.length();
dp.clear();
dp.resize(n+1,vector<int>(m+1,-1));
cout<<rec(0,0)<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}