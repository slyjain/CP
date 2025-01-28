#include<bits/stdc++.h>
using namespace std;
#define int long long
double p[3001];
int n;
double dp[3001][3001];
bool done[3001][3001];
double rec(int level,int hc){
    //base case
    if(level<0){
        if((n-hc)<hc)return 1.0;
        return 0.0;
    }
    //cache check
    if(done[level][hc]!=false){
        return dp[level][hc];
    }
    done[level][hc]=true;
    //transitions
    double ans=p[level]*rec(level-1,hc+1)+(1-p[level])*rec(level-1,hc);
    // cout<<ans<<" ";
    //save and return
    return dp[level][hc]=ans;

}
void solve(){
    
    cin>>n;
    // cout<<n<<"\n";
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            done[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
        // cout<<p[i]<<" ";
    }
    cout<<setprecision(17)<<rec(n-1,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}