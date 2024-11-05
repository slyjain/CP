#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF= 1e9;
//the variables/ object that dont change
//can be kept in global
int n,W,k,M;
int w[1000];
int v[1000];
int W;
int dp[100][100][100];
int rec(int level,int x,int items_left){
    //pruning
    //base case
    if(i==n){
        int sum_of_take=W-x;
        if(sum_of_take%M==0){
            //valid solution
            return 0;
            // agar sahi kiya toh pehle wala hi
        }
        else{
            //invalid solution
            // agar galat hua toh infinite penalty
            return -INF;
        }
        return 0;
    }
    //chache check
    if(dp[level][x][items_left]!=-1){
        return dp[level][x][items_left];
    }
    //transition
    int ans=rec(level+1,x,items_left);
    if(w[i]<=x&&items_left>0){
        ans=max(ans,rec(level+2,x-w[i])+v[i],items_left-1);
        // if you take i then you can take i+1
    }
    //save and return 
    return dp[level][x][items_left]=ans;
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
    cin>>W>>k>>M;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W,k)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0)
    solve();
    return 0;
}