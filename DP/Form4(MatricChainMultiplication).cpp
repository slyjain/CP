#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int x[101],y[101];
int dp[101][101];
int back[101][101];
int rec(int l,int r){
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
    for(int mid=l;mid<=r-1;mid++){
        if(ans>rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r]){
            ans=rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r];
            back[l][r]=mid;
        }
        
    }
    //save and return 
    return dp[l][r]=ans;
}
int opb[101],clb[101];
void generate(int l,int r){
    if(l==r){
        return;
    }
    opb[l]++;
    clb[r]++;
    int mid=back[l][r];
    generate(l,mid);
    generate(mid+1,r);
}
void solve(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
}
memset(dp,-1,sizeof(dp));
memset(opb,0,sizeof(opb));
memset(clb,0,sizeof(clb));
cout<<rec(0,n-1)<<"\n";
generate(0,n-1);
for(int i=0;i<n;i++){
    for(int x=0;x<opb[i];x++){
        cout<<"(";
    }
    cout<<" "<<i<<" ";
    for(int x=0;x<clb[i];x++){
        cout<<")";
    }
}
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}