#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string t;
//we keep track of bitmask of the first m-1 
//characters
//eg 0101- last three:010 (2)
//001000- last m-1 00100(4)
int dp[1001][31];
int val=-1;
int BM(string k){
    if(val!=-1){
        return val;
    }
    int ans=0;
    for(int i=0;i<m-1;i++){
        ans*=2;
        ans+=(k[i]-'0');
    }
    return val=ans;
}
int rec(int level,int bitmask){
    //base case
    if(level==n+1){
        return 1;
    }
    //cache check
    if(dp[level][bitmask]!=-1){
        return dp[level][bitmask];
    }
    //compute
    int ans=0;
    if(BM(t)==bitmask){
        ans+=rec(level+1,(bitmask*2+(!(t[m-1]-'0')))%(1<<(m-1)));
    }
    else{
        ans+=rec(level+1,(bitmask*2+1)%(1<<(m-1)));
        ans+=rec(level+1,(bitmask*2+0)%(1<<(m-1)));
    }
    //save and return 
    return dp[level][bitmask]=ans;

}
void solve(){
    cin>>n;
    cin>>t;
    m=t.size();
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