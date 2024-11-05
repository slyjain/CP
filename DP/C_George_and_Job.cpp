#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,arr[5100];
int parr[5100],dp[5100][5100];

int p(int l,int r){
    if(l==r){
        return arr[l];
    }
    if(l<0){
        return -1e18;
    }
    if(l==0){
        return parr[r];
    }
   return parr[r]-parr[l-1];
}
int rec(int level,int partition){
    if(partition<0){
        return -1e18;
    }
    if(level<-1){
        return -1e18;
    }
    //base case
    if(level==-1&& partition==0){
        return 0;
    }
    else if(level==-1){
        return -1e18;
    }
    //cache check
    if(dp[level][partition]!=-1){
        return dp[level][partition];
    }
    //transitions
    int ans=0;
    if(ans<rec(level-m,partition-1)+p(level-m+1,level)){
        // cout<<level-m+1<<" "<<level<<" "<<p(level-m+1,level)<<"\n";
        ans=(rec(level-m,partition-1)+p(level-m+1,level));
    }

    if(ans<rec(level-1,partition)){
        ans=rec(level-1,partition);
    }
    // ans=rec(level-1,partition);
    
    
    
    //save and return 
    return dp[level][partition]=ans;

}
void solve(){
    cin>>n>>m>>k;
    
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        parr[i]=arr[i];
        if(i){
            parr[i]+=parr[i-1];
        }
        // cout<<parr[i]<<" ";
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,k);
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
