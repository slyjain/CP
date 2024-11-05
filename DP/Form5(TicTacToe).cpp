#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[100010];
int rec(int x){
    //prunning

    //base case
    
    if(x==0){
        return 0;
    }
    //cache check
    if(dp[x]!=-1){
        return dp[x];
    }
    //compute
    int ans=0;
    for(int i=0;(1<<i)<=x;i++){
        if(rec(x-(1<<i))==0){
            ans=1;
        }
    }
    //save and return 
    return dp[x]=ans;

}
void solve(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
cout<<i<<" "<<rec(i)<<"\n";
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}