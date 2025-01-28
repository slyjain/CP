#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e9;
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n,x,y,z;
vector<int>a;
int done[55][55];
int dp[55][55][55];
int rec(int l,int r,int xx){
    //base case
    if(l==r){
        if(a[l]==xx){
            return 0;
        }else{
            return 1e9;
        }
    }
    
    //cache check
    if(done[l][r]!=-1){
        return dp[l][r][xx];
    }
    //compute
 
            for(int k=0;k<50;k++){
                dp[l][r][k]=1e9;
            }
        
    
    for(int mid=l;mid<r;mid++){
        for(int fs=0;fs<50;fs++){
            for(int ls=0;ls<50;ls++){
                dp[l][r][(fs*x+ls*y+z)%50]=min(dp[l][r][(fs*x+ls*y+z)%50],rec(l,mid,fs)+rec(mid+1,r,ls)+fs*ls);
            }
        }
    }
    //save and return 
    done[l][r]=1;
    return dp[l][r][xx];

}
void solve(){
     
     cin>>n>>x>>y>>z;
    //  memset(dp,-1,sizeof(dp));
        
     memset(done,-1,sizeof(done));
     a.resize(n);
     for(int i=0;i<n;i++)cin>>a[i];
     int ans=1e9;
     for(int i=0;i<50;i++){
        ans=min(ans,rec(0,n-1,i));
     }
    //  cout<<rec(0,n-1);
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
    return 0;
}