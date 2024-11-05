#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int parr[510];
int arr[510];
int dp[510][510];
int p(int l,int u){
    if(u==l){
        return arr[u];
    }
    if(l==0){
        return parr[u];
    }
    return parr[u]-parr[l-1];
}
int rec(int l,int r){
    //prunning
    if(l>r){
        return 1e9;
    }
    //base case
    if(l==r){
        return 0;
    }
    //cache check

    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //compute
    int ans=1e9;
    for(int i=l;i<r;i++){
        // cout<<rec(l,i)<<" "<<rec(i+1,r)<<" "<<p(i,l)<<" "<<p(i,r)<<"\n";
        ans=min(rec(l,i)+rec(i+1,r)+(p(l,i))*(p(i+1,r)),ans);
    }
    //save and return 
    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        parr[i]=arr[i];
        if(i){
            
            parr[i]+=parr[i-1];
        }
        // cout<<parr[i]<<" ";
    }
    memset(dp,-1,sizeof(dp));
    cout<< rec(0,n-1);
    

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}