#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
int dp[2][100010];
vector<pair<int,int>>arr;
void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    int mx=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            
            if(i>0){
                // cout<<"here";
                int ans=0;
                ans=max(dp[(i-1)%2][j],ans);
                if(j-arr[i-1].first>=0){
                    ans=max(ans,dp[(i-1)%2][j-arr[i-1].first]+arr[i-1].second);
                }
                dp[i%2][j]=ans;
            }
            cout<<dp[i%2][j]<<"\t";
        }
        cout<<"\n";
    }
    // int mx=0;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         mx=max(mx,dp[i][j]);
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<mx;
    cout<<mx;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}