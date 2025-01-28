#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n,m,k;
string a,b,c;
int dp[101][101][101];
int rec(int x,int y,int z){
    //prunning
    //base case
    if(x<0||y<0||z<0)return 0;
    
    
    //cache check
    if(dp[x][y][z]!=-1){
        return dp[x][y][z];
    }
    //transitions
    int ans=-1e9;
    ans=max(ans,rec(x-1,y,z));
    ans=max(ans,rec(x,y-1,z));
    ans=max(ans,rec(x,y,z-1));
    if(a[x]==b[y]&&b[y]==c[z]){
        ans=max(ans,1+rec(x-1,y-1,z-1));
    }
    //save and return 
    return dp[x][y][z]=ans;
}
void solve(){
    //  string a,b,c;
    memset(dp,-1,sizeof(dp));
     cin>>a>>b>>c;
    n=a.size(),m=b.size(),k=c.size();
    //  rec(n-1,m-1,k-1);
    int ans=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<k;l++){
                ans=max(ans,rec(i,j,l));
            }
        }
     }
     cout<<ans<<"\n";
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