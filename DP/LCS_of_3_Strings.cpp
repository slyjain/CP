#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c;
int n,m,l;
int dp[110][110][110];
int rec(int i,int j,int k){
    //base case
    if(i==n||j==m||k==l){
        return 0;
    }
    //cache check
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    //compute
    int ans=0;
    // cout<<"here";
    if((a[i]==b[j])&&(b[j]==c[k])){
        // cout<<a[i]<<" ";
        ans=max(ans,1+rec(i+1,j+1,k+1));
    }
    ans=max(ans,rec(i+1,j,k));
    ans=max(ans,rec(i,j+1,k));
    ans=max(ans,rec(i,j,k+1));
    //save and return 
    return dp[i][j][k]=ans;

}
void solve(){
    cin>>a>>b>>c;
    // cout<<a<<b<<c;
    n=a.size();
    m=b.size();
    l=c.size();
    // cout<<n<<" "<<m<<" "<<l<<" ";
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}