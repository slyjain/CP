#include<bits/stdc++.h>
using namespace std;
#define int long long

//the variables/ object that dont change
//can be kept in global
int n;
int w[1000];
int v[1000];
int W;
int dp[1000][1000];
int rec(int level,int x){
    //pruning
    //base case
    if(i==n){
        return 0;
    }
    //chache check
    if(dp[level][x]!=-1){
        return dp[level][x];
    }
    //transition
    int ans=rec(level+1,x);
    if(w[i]<=x){
        ans=max(ans,rec(level,x-w[i])+v[i]);
    }
    //save and return 
    return dp[level][x]=ans;
}
vector<int>solution;
void generate(int level,int x){
    if(i==n){
        return ;
    }
    else{
        int dont_take=rec(level+1,x);
        if(w[level]<=x){
            //can possibly take
            int take=rec(level+1,x-w[level])+v[level];
            if(dont_take>take){
                generate(level+1,x);
            }
            else{
                solution.push_back(level);
                generate(level+1,x-w[level]);
            }
        }
        else{
            generate(level+1,x);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cin>>W;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0)
    solve();
    return 0;
}