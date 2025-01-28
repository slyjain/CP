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
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
string s1,s2;
int n;
int dp[41][41];
int rec(int l,int r){
    //base case
    if(l==r){
        return true;
    }
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //compute
    bool ans=false;
    for(int len=1;len<r-l+1;len++){
        string temp=s1.substr(l,len);
        reverse(all(temp));
        string temp2=s2.substr(l,len);
        if(temp==temp2){
            // cout<<temp<<" "<<temp2<<"\n";
            ans|=(rec(l+len,r));
        }
    }
    //save and return
    return dp[l][r]=ans;

}
void solve(){
    cin>>s1>>s2;
    n=s1.size();
    memset(dp,-1,sizeof(dp));
    cout<<(rec(0,n-1)?"Yes":"No")<<"\n";     
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