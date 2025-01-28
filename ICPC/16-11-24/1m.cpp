#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>c;
vector<int>p;
int dp[2*100010];

void solve(){
    memset(dp,0,sizeof(dp));
    int n,k;
    cin>>n>>k;
    c.clear();
    p.clear();
    p.resize(n+1);
    c.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
        // p[i]=c[i]+p[i-1];
    }
    sort(c.begin(),c.end());
    // for()
    for(int i=1;i<=n;i++){
        // cin>>c[i];
        p[i]=c[i]+p[i-1];
        // cout<<p[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        if(i<=k){
            dp[i]=p[i];
        }
        else{
            dp[i]=p[i]-p[i-k]+dp[i-(k+1)];
        }
        cout<<dp[i]<<" ";
    }
    


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    
    return 0;
}