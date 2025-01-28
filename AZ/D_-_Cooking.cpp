#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int total_sum;
vector<int>a;
vector<vector<int>>dp;
int rec(int level,int o1){
    //base case
    if(level==n){
        return max(o1,total_sum-o1);
    }
    //cache check
    if(dp[level][o1]!=-1){
        return dp[level][o1];
    }
    //compute
    int ans=rec(level+1,o1+a[level]);
    ans=min(ans,rec(level+1,o1));
    return dp[level][o1]=ans;
}
void solve(){
    cin>>n;
    a.resize(n);
    
    total_sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        total_sum+=a[i];
    }
    dp.assign(n+1,vector<int>(total_sum,-1));
    cout<<rec(0,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}