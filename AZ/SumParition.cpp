#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define print(a) for(auto i:a){ cout<<i<<' ' ;}cout<<endl; 
#define read(x) int x ; cin>>x;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mt make_tuple
#define eb emplace_back

typedef vector<int> vin;
typedef vector<string> vst;
typedef vector<char> vch;
int n,k;

int rec(int rem1,int krem,vector<vector<int>>&dp){
    if(rem1==0)return 1;
    if(rem1<0||krem==0)return 0;
    if(dp[rem1][krem]!=-1){
        return dp[rem1][krem];
    }
    int ans=rec(rem1-krem,krem,dp);
    ans=(ans+rec(rem1,krem-1,dp))%MOD;
    return dp[rem1][krem]=ans;
}
void solve(){
     
     cin>>n>>k;
     vector<vector<int>>dp(n-k+1,vector<int>(k+1,-1));
    //  dp.assign
     cout<<rec(n-k,k,dp)<<"\n";
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