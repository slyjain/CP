#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
double p[3000];
double dp[3000][3000];
double rec(int level,int head){
    //base case
    if(level==n){
        
        if(head>n-head){
            // cout<<level<<" "<<head<<"\n";
            return 1.0;
        }
        else{
            return 0.0;
        }
    }
    //cache check
    if(dp[level][head]!=-1.0){
        return dp[level][head];
    }
    //compute
    double ans=p[level]*rec(level+1,head+1)+(1-p[level])*rec(level+1,head);
    //save and return 
    return dp[level][head]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1.0;
        }
    }
    cout<<fixed<<setprecision(10)<<rec(0,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}