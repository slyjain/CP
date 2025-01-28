#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    vector<int>dp(n,0),pre(n,0);

    for(int i=n-1;i>=0;i--){
        pre[i]=a[i];
        if(i<n-1){
            pre[i]+=pre[i+1];
        }
        cout<<pre[i]<<" ";
    }
    for(int i=0;i<n;i++){
        dp[i]=pre[i];
        if(i+k<=n-1){
            dp[i]-=pre[i+k];
        }else{
            dp[i]-=pre[n-1];
        }
    }
    
    for(int i=0;i<n;i++){

    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}