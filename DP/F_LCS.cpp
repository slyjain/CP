#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
int n,m;
//FORM3-Longest common sub sequence
int dp[3001][3001];
int backArray[3001][3001];
int rec(int i,int j){
    //base case
    if(i==n||j==m){
        return 0;
    } 
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //compute
    int ans=0;
    if(s1[i]==s2[j]){
        if((rec(i+1,j+1)+1)>ans){
            backArray[i][j]=0;
            ans=rec(i+1,j+1)+1;
        }
    }
    if(rec(i+1,j)>ans){
        ans=rec(i+1,j);
        backArray[i][j]=1;
    }
    if(rec(i,j+1)>ans){
        ans=rec(i,j+1);
        backArray[i][j]=2;
    }
    return dp[i][j]=ans;
}
void generate(int i,int j){
    if(i==n||j==m){
        return ;
    }
    switch(backArray[i][j]){
        case 0:
        cout<<s1[i];
        generate(i+1,j+1);
        break;
        case 1:
        generate(i+1,j);
        break;
        case 2:
        generate(i,j+1);
        break;
    }


}
void solve(){
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    memset(dp,-1,sizeof(dp));
    memset(backArray,-1,sizeof(backArray));
    rec(0,0);
    generate(0,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}