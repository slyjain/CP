#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n;
vector<int>a;
vector<int>dp(1010,-1);
int rec(int level){
    //base case
    if(level<0)return 0;
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //transitions
    int ans=1;
    for(int i=0;i<level;i++){
        if(a[i]<a[level]){
            ans=max(ans,dp[i]+1);
        }
    }
    //save and return
    return dp[level]=ans;
}
void solve(){
     cin>>n;
     a.resize(n+1);
     dp.assign(1010,-1);
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
     int mx=0;
     for(int i=0;i<n;i++){
        mx=max(mx,rec(i));
        cout<<rec(i)<<" ";
     }
     cout<<"\n";
     int cnt_lis=0;
     vector<int>mxlis;
     for(int i=0;i<n;i++){
        if(rec(i)==mx){
            mxlis.push_back(i);
        }
     }
     for(auto x:mxlis){
        for(int i=0;i<x;i++){
            if(rec(i)==mx-1&&a[i]<a[x]){
                cnt_lis++;
            }
        }
     }
     cout<<cnt_lis;
    cout<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}