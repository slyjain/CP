#include<bits/stdc++.h>
using namespace std;
#define int long long
int dpWin[61][160][260][11][2];
int dpPos[61][160][11];
 int r[]={1,2,3,4,6,0};
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
int rec2(int ballRem,int runRem,int wickRem){
    
    if(ballRem==0 || runRem<=0 || wickRem==0)return 1;
    if(dpPos[ballRem][runRem][wickRem]!=-1){
        return dpPos[ballRem][runRem][wickRem];
    }
    int ans=0;
    for(int i=0;i<5;i++){
        ans+=rec2(ballRem-1,runRem-r[i],wickRem);
    }
    ans+=rec2(ballRem-1,runRem,wickRem-1);
    return dpPos[ballRem][runRem][wickRem]=ans%M;
}

int rec1(int ballRem,int runRem,int vkRuns,int wickRem,int strike){
    //base case

    if(wickRem==0)return 0;
    if(runRem<=0 ){
        return (vkRuns>=100);
    }
    if(ballRem==0){
        return 0;
    }
    //cache check
    if(dpWin[ballRem][runRem][vkRuns][wickRem][strike]!=-1){
        return dpWin[ballRem][runRem][vkRuns][wickRem][strike];
    }
    int ans=0;
    for(int i=0;i<5;i++){
        if(ballRem%6==0){
            if(r[i]%2==0){
                ans+=rec1(ballRem-1,runRem-r[i],vkRuns+r[i],wickRem,!strike);
            }else{
                ans+=rec1(ballRem-1,runRem-r[i],vkRuns+r[i],wickRem,strike);   
            }
        }else{
            if(r[i]%2!=0){
                ans+=rec1(ballRem-1,runRem-r[i],vkRuns+r[i],wickRem,!strike);
            }else{
                ans+=rec1(ballRem-1,runRem-r[i],vkRuns+r[i],wickRem,strike);   
            } 
        }
    }
    if(!strike){
        if(ballRem%6!=0)
        ans+=rec1(ballRem-1,runRem,vkRuns,wickRem-1,strike);
        else
        ans+=rec1(ballRem-1,runRem,vkRuns,wickRem-1,!strike);
    }
    //save and return
    return dpWin[ballRem][runRem][vkRuns][wickRem][strike]=ans%M;
}

// int fn(int n,int b,int w,int x,int s){
//     if(w==0)return 0;
//     if(b==0){
//         return (!n && x==100);
//     }
//     if(n<=0){
//         return (x>=100);
//     }
//     int one,two,three,four,six,wicket=0;
//     if(!b%6 ){
//         one=fn(n-1,b-1,w,x+1,s);
//         two=fn(n-2,b-1,w,x+2,!s);
//         three=fn(n-3,b-1,w,x+3,s);
//         four=fn(n-4,b-1,w,x+4,!s);
//         six=fn(n-6,b-1,w,x+6,!s);
//         if(!s){
//             wicket=fn(n,b-1,w,x,!s);
//         }
//     }else{
//         one=fn(n-1,b-1,w,x+1,!s);
//          two=fn(n-2,b-1,w,x+2,s);
//          three=fn(n-3,b-1,w,x+3,!s);
//          four=fn(n-4,b-1,w,x+4,s);
//          six=fn(n-6,b-1,w,x+6,s); 
//          wicket=fn(n,b-1,w-1,x,s);
//     }
//     return one+two+three+four+six+wicket;
// }
int N,b,w,x;
void solve(){
    memset(dpWin,-1,sizeof(dpWin));
    memset(dpPos,-1,sizeof(dpPos));
    cin>>N>>b>>w>>x;
    int p=rec1(b,N,x,10-w,1);
    int q=rec2(b,N,10-w);
    cout<<mul(p,inv(q))<<"\n";
    // cout<<rec1(b,N,x,10-w,1)<<" "<<rec2(b,N,10-w)<<"\n";

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