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

void solve(){
    cin>>s;
    n=s.length();
    for(int len=1;len<=n;len++){
        for(int l=0;l+len-1<n;l++){
            int r=l+len-1;
            if(r-l+1<=1)dp1[l][r] =1;
            else if(len==2)dp[l][r]=s[l]==s[r];
            else dp1[l][r]=(s[l]==s[r]&&dp1[l+1][r-1]);
        }
    }
    // memset(dp2,-1,sizeof(dp2));
    for(int i=0;i<n;i++){
        dp2[i]=INF;
        for(int j=i;j>=0;j--){
            if()
        }
    }
    cout<<rec(n-1)<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}