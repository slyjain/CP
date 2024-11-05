#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int abc[100010][3];
int dp[100010][3];
int rec(int day,int prev){
    // cout<<day<<" "<<prev<<"\n";
    //base case
    if(day==n){
        return 0;
    }
    //cache check
    // cout<<"here\n";
    if(dp[day][prev]!=-1&&prev!=-1){
        return dp[day][prev];
    }
    // cout<<"here1\n";
    //compute
    int ans=0;
    for(int i=0;i<3;i++){
        if(i==prev){
            continue;
        }
        // cout<<i<<" ";
        ans=max(ans,rec(day+1,i)+abc[day][i]);
    }
    //save and return 
    return dp[day][prev]=ans;

}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>abc[i][0]>>abc[i][1]>>abc[i][2];
        // cout<<abc[0][i]<<" "<<abc[1][i]<<" "<<abc[2][i]<<"\n";
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}