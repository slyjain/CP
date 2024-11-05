#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int dp[1000100];
int iter(int x){
    for(int i=0;i<=n;i++){
        if(i==0){
            dp[i]=0;
        }
        else{
            dp[i]=1e9;
            int k=i;
            int ans=1e9;
            while(k>0){
                ans=min(ans,1+dp[i-k%10]);
                k/=10;
            }
            dp[i]=ans;
        }
        // cout<<i<<" :"<<dp[i]<<"\n";
    }
    return dp[x];
}
void solve(){
    cin>>n;
    cout<<iter(n);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}