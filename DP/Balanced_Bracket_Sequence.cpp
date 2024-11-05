#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n;
const int mod=1e9+7;
int dp[1001][1001];
int rec(int level,int depth){
    //prunning
    if(depth<0){
        return 0;
    }
    //base case
    if(level==n){
        if(depth==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    //cache check
    if(dp[level][depth]!=-1){
        return dp[level][depth];
    }
    //compute
    int ans=0;
    if(s[level]==')'){
        ans=rec(level+1,depth-1);
    }
    else if(s[level]=='('){
        ans=rec(level+1,depth+1);
    }
    else if(s[level]=='?'){
        ans=rec(level+1,depth+1)+rec(level+1,depth-1);
    }
    ans%=mod;
    //save and return
    return dp[level][depth]=ans;
}
void solve(){
    cin>>s;
    n=s.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<"\n";
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