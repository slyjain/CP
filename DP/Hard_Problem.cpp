#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[10010];
int n;
string s;
string t="hard";
int dp[10010][4];
int rec(int level,int match){
    if(match==4){
        return 0;
    }
    if(level==n){
        return 1e18;
    }
    
    //cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    //compute
    int ans=1e18;
    
    if(s[level]==t[match]){
        ans=min(rec(level+1,match),rec(level+1,match+1)+arr[level]);
        // ans=min(,ans);
    }
    else{
        
        ans=min(ans,rec(level+1,match));
    }
    return dp[level][match]=ans;
}
void solve(){
    cin>>n>>s;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
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