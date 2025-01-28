#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n;
const int mod=1000000007;
int dp[1000010][5];
int rec(int level,int match){
    //prunning
    if(match==4){
        return 0;
    }
    //base case
    if(level==-1){
        // cout<<pre<<"\n";
        return 1;
    }
    //cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    
    //transitions
    int ans =0;
    if(match==0){
        ans=(rec(level-1,1)+rec(level-1,0))%mod;
    }else if(match==1){
        ans=(rec(level-1,2)+rec(level-1,0))%mod;
    }else if(match==2){
        ans=(rec(level-1,2)+rec(level-1,3))%mod;
    }else if(match==3){
        ans=(rec(level-1,4)+rec(level-1,0))%mod;
    }
    //save and return
    return dp[level][match]=ans;
}
void solve(){
    cin>>n;
    // dp.clear();
    // dp.assign(n,vector<int>(5,-1));
    
    cout<<rec(n-1,0)<<"\n";
     
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    while(t--)

        solve();
    return 0;
}