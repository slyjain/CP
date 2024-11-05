#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int n,k;
vector<int>arr;
int dp[100][100];
bool done[100][100];
int rec(int i,int j){
    if(i+1<j){
        return INF;
    }
    if(j<0){
        return  INF;
    }
    if(i==-1){
        if(j==0){
            return 0;
        }
        else{
            return INF;
        }
    }
    if(done[i][j]){
        return dp[i][j];
    }
    int ans=INF;
    int runMax=arr[i];
    for(int x=i;x>=0;x--){
        runMax=max(runMax,arr[i]);
        ans=min(ans,runMax+rec(x-1,j-1));

    }
    done[i][j]=1;
    return dp[i][j]=ans;

}
vector<int>cuts;
void geenrate(int i ,int j){

}
signed main(){
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    memset(done,0,sizeof(done));
    int ans=rec(n-1,k);
}