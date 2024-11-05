#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string t;
int dp[1010][4];
int rec(int level,int match){

    //base case
    if(level==n){
        return 1;
    }
    //cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    //compute
    int ans=0;
    if(match==0){
        ans+=rec(level+1,0);
        ans+=rec(level+1,1);
    }
    else if(match==1){
        ans+=rec(level+1,1);
        ans+=rec(level+1,2);
    }
    else if(match==2){
        ans+=rec(level+1,3);
        ans+=rec(level+1,0);
    }
    else if(match==3){
        ans+=rec(level+1,2);
    }
    //save and return 
    return dp[level][match]=ans;
    
}
void solve(){
    cin>>n;
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