#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=1e9+7;
//typedef long long ll;
typedef vector<int > vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<ll> vl;
// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//---- Debugger ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
ll binpow(ll b,ll p,ll mod){ll ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
//----------------- //
inline void add(ll &a, ll b) {
    if(a<0){
        a+=M;
    }
    if(b<0){
        b+=M;
    }
  a += b;
  a%=M;
  if (a >= M) a -= M;
}

inline void sub(ll &a, ll b) {
    if(a<0){
        a+=M;
    }
    if(b<0){
        b+=M;
    }
  a -= b;
  a%=M;
  if (a < 0) a += M;
}

inline ll mul(ll a, ll b) {
  return (ll) ((long long) a * b % M);
}
inline ll power(ll a, long long b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline ll inv(ll a) {
  a %= M;
  if (a < 0) a += M;
  ll b = M, u = 0, v = 1;
  while (a) {
    ll t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += M;
  return u;
}
// ll fact[N];

// void pre() {
//     fact[0] = 1;
//     for(ll i = 1; i < N; i++)
//         fact[i] = mul(fact[i - 1], i);
//     return;
// }
ll n,m;
vector<vector<ll>>g,vis;
bool nodeIsValid(ll row, ll col){
    if(vis[row][col]==0&&g[row][col]!=1&&row>=0&&row<n&&col>=0&&col<m){
        return true;
    }
    return false;
}
ll dy[]={-1,1,0,0};
ll dx[]={0,0,-1,1};
ll sz=0;
void dfs(ll row, ll col){
    sz++;
    vis[row][col]=1;
    for(ll i=0;i<4;i++){
        if(nodeIsValid(row+dy[i],col+dx[i])){
            dfs(row+dy[i], col+dx[i]);
        }
    }
    if(sz==1){
        g[row][col]=0;
    }
    else{
        g[row][col]=sz;
    }


}
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    
    while(t--){
       cin>>n>>m;
        g.assign(n,vector<ll>(m,0));
        vis.assign(n,vector<ll>(m,0));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>g[i][j];
                //cout<<g[i][j]<<" ";
            }
            //cout<<"\n";
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(vis[i][j]==0&&g[i][j]==0){
                    sz=0;
                    dfs(i,j);
                }
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout<<g[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
