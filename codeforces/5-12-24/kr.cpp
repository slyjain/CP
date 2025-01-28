#include<bits/stdc++.h>
using namespace std;
#define int long long

string a,b,c;
int n,m;
vector<vector<int>> dp;

int rec(int i,int j){
  int  k = i+j;
    if(k == n+m){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int ans = 1e18;
    if(i<n && a[i]==c[k]){
        ans = min(ans,rec(i+1,j));
    }
    else if(i<n && a[i]!=c[k]){  // Added explicit mismatch check
        ans = min(ans,rec(i+1,j)+1);
    }

    if(j<m && b[j]==c[k]){
        ans = min(ans,rec(i,j+1));
    }
    else if(j<m && b[j]!=c[k]){  // Added explicit mismatch check
        ans = min(ans,rec(i,j+1)+1);
    }
    
    return dp[i][j] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c;
        n = a.size();
        m = b.size();
        dp.clear();
        dp.assign(n+1,vector<int>(m+1,-1));
        cout<<rec(0,0)<<"\n";
    }
    return 0;
}