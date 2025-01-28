#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
//typedef long long int;
typedef vector<int > vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<int> vl;
// // Common file
// #include <ext/pb_ds/assoc_container.hpp>
// // Including tree_order_statistics_node_update
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, nuint_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// int binpow(int b,int p,int mod){int ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
// //----------------- //
// inline void add(int &a, int b) {
//     if(a<0){
//         a+=M;
//     }
//     if(b<0){
//         b+=M;
//     }
//   a += b;
//   a%=M;
//   if (a >= M) a -= M;
// }

// inline void sub(int &a, int b) {
//     if(a<0){
//         a+=M;
//     }
//     if(b<0){
//         b+=M;
//     }
//   a -= b;
//   a%=M;
//   if (a < 0) a += M;
// }

// inline int mul(int a, int b) {
//   return (int) ((long long) a * b % M);
// }
// inline int power(int a, long long b) {
//   int res = 1;
//   while (b > 0) {
//     if (b & 1) {
//       res = mul(res, a);
//     }
//     a = mul(a, a);
//     b >>= 1;
//   }
//   return res;
// }

// inline int inv(int a) {
//   a %= M;
//   if (a < 0) a += M;
//   int b = M, u = 0, v = 1;
//   while (a) {
//     int t = b / a;
//     b -= t * a; swap(a, b);
//     u -= t * v; swap(u, v);
//   }
//   assert(b == 1);
//   if (u < 0) u += M;
//   return u;
// }
// // int fact[N];

// // void pre() {
// //     fact[0] = 1;
// //     for(int i = 1; i < N; i++)
// //         fact[i] = mul(fact[i - 1], i);
// //     return;
// // }
void solve(){
    int n;
    cin>>n;
    int x=0;
    int sum=0, ans=0;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;
    }
    ans=(n+1)*50-sum;
    if(ans>100){
        cout<<-1<<"\n";
    }
    else if(ans>=0){
        cout<<ans<<"\n";
    }
    else{
        cout<<0<<"\n";
    }
}
signed main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
       solve();
    }
    return 0;
}