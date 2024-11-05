#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e9;
int n;
string s;
int dp1[1000][1000];
int rec1(int l,int r){
    //pruning
    //base case
    if(r-l+1==0||r-l+1==1){
        return 1;
    }
    //cache check
    if(dp[l][r]!=-1){
        return dp1[l][r];
    }
    //compute
    int ans=0;
    if(rec(l+1,r-1)&&s[l]==s[r]){
        ans=1;
    }
    return dp1[l][r]=ans;
}
int dp2[1001];
int rec2(int i){
    //pruning
    //base case
    if(i==-1){
        return -1;
    }
    //cache check
    if(dp2[i]!=-1){
        return dp2[i];
    }
    //compute
    int ans=n;
    for(int j=i-1;j>=0;j--){
        if(rec(j,i)){
            ans=min(ans,1+rec2(j-1));
        }
    }
    return dp2[i]=ans;
}
void solve(){
    cin>>s;
    n=s.length();
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cout<<rec(n-1)<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}