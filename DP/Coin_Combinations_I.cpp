#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[101];
int n,x;
int mod=1e9+7;
int dp[1000100];
int rec(int level){
    
    //base case
    if(level==0){
        return 1;
    }
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //compute
    int ans=0;
    for(int i=0;i<n;i++){
        if(level-arr[i]<0){
            continue;
        }
        ans+=rec(level-arr[i]);
        
    }
    //save and return 
    return dp[level]=ans;
}
int iter(int level){
    //base case
    if(level==0){
        return 1;
    }
    dp[0]=1;
    for(int i=0;i<=level;i++){
        dp[i]%=mod;
        for(int j=0;j<n;j++){
            if(i+arr[j]>x)break;
            dp[i+arr[j]]=(dp[i+arr[j]]+dp[i]);
        }
        
        
        // cout<<dp[i]<<" ";
        
    }
    return dp[level]%mod;
}
int iterCorrect(int x){
    for(int i=0;i<=x;i++){
        if(i==0){
            dp[i]=1;
        }
        else{
            dp[i]=0;
            for(int j=0;j<n;j++){
                if(i-arr[j]>=0)dp[i]+=dp[i-arr[j]];
            }
            dp[i]%=mod;
        }
    }
    return dp[x];
}
void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    // memset(dp,0,sizeof(dp));
    for(int i=0;i<=x;i++){
        dp[i]=0;
    }
    cout<<iter(x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}