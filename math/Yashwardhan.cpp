#include<bits/stdc++.h>
using namespace std;

int mod= 1e9+7;

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans= (1LL*ans*a) % mod;
        a= (1LL*a*a) % mod;
        b/= 2;
    }
    return ans;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int f[n+k], inf[n+k];
    f[0] = 1;
    for(int i=1; i<n+k; i++)
        f[i]= (1LL*f[i-1]*i) % mod;
    inf[n+k-1]= binpow(f[n+k-1],mod-2);
    for(int i=n+k-2; i>=0; i--)
        inf[i]= (1LL*inf[i+1]*(i+1)) % mod;
    int ans = 0;
    for(int i=0; i<=min(k/m,n); i++){
        int x= n+k-1-(i*m);
        int p= (1LL*f[x]*inf[x-n+1]) % mod;
        p= (1LL*p*inf[n-1]) % mod;
        int q= (1LL*f[n]*inf[i]) % mod;
        q= (1LL*q*inf[n-i]) % mod;
        p= (1LL*p*q) % mod;
        if(i%2){
            ans= (ans-p) % mod;
            if(ans<0) ans+= mod;
        }else ans= (ans+p) % mod;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--) solve();
    return 0;
}