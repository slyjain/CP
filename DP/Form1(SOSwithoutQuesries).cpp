#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
int arr[101];
int dp[101][10010];
int rec(int level,int sum_taken){
    //pruning

    //base case
    if(level==n){
        if(sum_taken==t){
            return 1;
        }
        else{
            return 0;
        }
        
    }   
    if(sum_taken==t){
        return 1;
    }
    //cache check
    if(dp[level][sum_taken]!=-1){
        return dp[level][sum_taken];
    }    
    //compute
    int ans=0;
     ans|=rec(level+1,sum_taken+arr[level]);
     ans|=rec(level+1,sum_taken);
    //save and return 
    return dp[level][sum_taken]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    int t;
    cin>>t;
    cout<<rec(0,0);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}