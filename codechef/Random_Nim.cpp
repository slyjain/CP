#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
//----------------- //
inline void add(int &a, int b) {
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

inline void sub(int &a, int b) {
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

inline int mul(int a, int b) {
  return (int) ((long long) a * b % M);
}
inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= M;
  if (a < 0) a += M;
  int b = M, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += M;
  return u;
}
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int>a(n);
    int x=0,y;
    for(int i=0;i<n;i++){
        cin>>y;
        x^=y;
    }
    if(x!=0){
        cout<<mul((d+1),inv(2*d));
    }else{
        cout<<0<<"\n";
    }
    

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}