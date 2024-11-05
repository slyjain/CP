#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int arr[1001][1001];
int dp[1001][1001];
int done[1001][1001];
int rec(int row,int col){
    //pruning
    if(row<0||col<0){
        return -1e18;
    }
    //base case
    if(row==0&&col==0){
        return arr[0][0];
    }
    //cache check
    if(done[row][col]){
        return dp[row][col];
    }
    //compute
    int ans=-1e18;
    if(row>0){
        ans=max(ans,rec(row-1,col)+arr[row][col]);
    }
    if(col>0){
        ans=max(ans,rec(row,col-1)+arr[row][col]);
    }
    //save and return 
    return  dp[row][col]=ans;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            done[i][j]=0;
        }
    }
    cout<<rec(n-1,m-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}