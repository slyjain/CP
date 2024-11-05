#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
int n,m;
int dp[1010][1010];
int rec(int i,int j){
    //base case
    if(i==n&&j==m){
        return 0;
    }

    if(i==n){
        return m-j;
    }
    if(j==m){
        return n-i;
    }
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //compute

     int ans=1e9;
    if(s1[i]==s2[j]){
        ans =min(ans,rec(i+1,j+1));
    }
    else{
       
        ans=min(ans,1+rec(i+1,j+1));
        ans=min(ans,1+rec(i,j+1));
        ans=min(ans,1+rec(i+1,j));
    }
    //save and return
    return dp[i][j]=ans;
}
void solve(){
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}