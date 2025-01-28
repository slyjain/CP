#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007//1000000007
#define MAXN 100010
int binpow(int a,int p){
    int ans=1;
    while(p){
        if(p%2){
            ans=(ans*a)%mod;
        }
        p>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int fact[MAXN]{},invFact[MAXN]{};
void pre(){
    fact[0]=1;
    for(int i=1;i<=MAXN;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    invFact[MAXN]=binpow(fact[MAXN],mod-2);
    for(int i=MAXN-1;i>=0;i--){
        invFact[i]=((i+1)*invFact[i+1])%mod;
    }
}
int ncr(int n,int r){
    if(r>n||r<0)return 0;
    if(r==0||n==r)return 1;
    return (fact[n]*((invFact[n-r]*invFact[r])%mod))%mod;
}
void solve(){
     int n;
     cin>>n;
     vector<int>a(n+1);

     for(int i=1;i<=n;i++){
        cin>>a[i];
     }
     sort(a.begin(),a.end());
     int ans=binpow(2,n-1);
    
     for(int i=1;i<n;i++){  
        int l=i-1;
        int r=n-i;
        int k=upper_bound(a.begin()+i,a.end(),a[i])-(a.begin()+i+1);
        // cout<<k<<" ";
        int mn=min(l,r-1);
        for(int j=0;j<=mn;j++){
            ans=(ans+(ncr(l,j)*((ncr(r,j+1)-ncr(r-k,j+1)+mod)%mod)%mod))%mod;
        }
     }
     cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    pre();
    while(t--)
        solve();
    return 0;
}