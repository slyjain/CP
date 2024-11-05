#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int arr[100100];
int dp[100100];
bool rec(int X){
    //base case
    if(X==0){
        return false;
    }
    //cache chech
    if(dp[X]!=-1){
        return dp[X];
    }
    //compute
    int win=0;
    for(int i=0;i<n;i++){
        if((X-arr[i]>=0)&&!rec(X-arr[i])){
            win=1;
        }
    }
    //save and return 
    return dp[X]=win;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    if(rec(k)){
        cout<<"First";
    }
    else{
        cout<<"Second";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}