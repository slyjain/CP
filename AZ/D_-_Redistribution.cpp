#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int n;
int dp[2001];
int rec(int level){
    //base case
    if(level<3){
        return 0;
    }
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //compute
    int ans=1;
    for(int i=3;i<=level-3;i++){
        ans=(ans+(rec(i)*rec(level-i))%MOD)%MOD;
    }
    return dp[level]=ans;
    
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<rec(n);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}