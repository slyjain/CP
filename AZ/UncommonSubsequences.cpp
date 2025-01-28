#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s,t;
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
vector<vector<int>>pre,dp;
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int rec(int p1,int p2){
    //base case
    if(p1==-1)return 1e9;
    if(p2==-1)return 1;

    //cache check
    if(dp[p1][p2]!=-1){
        return dp[p1][p2];
    }
    //compute
    int ans=INF;
    ans=rec(p1-1,p2);
    if(pre[p1][p2]==-1)ans=1;
    else ans=min(ans,1+rec(p1-1,pre[p1][p2]-1));
    
    return dp[p1][p2]=ans;
}

void solve(){
     
     cin>>s>>t;
     n=s.size();
     m=t.size();
     dp.assign(n,vector<int>(m,-1));
     pre.assign(n,vector<int>(m,-1));
     for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j])p = j;
            pre[i][j] = p;
        }
    }
     cout<<(rec(n-1,m-1)==1e9?-1:rec(n-1,m-1))<<"\n";
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