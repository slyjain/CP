#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int dp[5010][3];
int rec(int level,int prev){
    //base case
    if(level==s.size()){
        return 1;
    }
    //cache check
    if(dp[level][prev]!=-1){
        return dp[level][prev];
    }
    //compute
    int ans=0;
    int current=prev*10+(s[level]-'0');
    // cout<<current<<" ";
    if(current>26){
        return 0;
    }
    if(current==1||current==2){
        ans+=rec(level+1,current);
    }
    ans+=rec(level+1,0);

    //save and return
    return dp[level][prev]=ans;

}
void solve(){
    while(1){
        getline(cin,s);
        if(s=="0"){
            break;
        }
        memset(dp,-1,sizeof(dp));
        cout<<rec(0,0)<<"\n";
    }
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}