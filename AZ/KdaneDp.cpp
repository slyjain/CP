#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    dp[0]=(arr[0]);
    int mx=arr[0];
    for(int i=1;i<n;i++){

        dp[i]=max(dp[i-1],1LL*0)+arr[i];
        mx=max(mx,dp[i]);
    }
    cout<<mx;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}