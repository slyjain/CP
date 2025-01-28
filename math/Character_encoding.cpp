        #include<bits/stdc++.h>
        using namespace std;
        #define int long long
        int mod=1e9+7;
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
        int f[n+k];
        int inf[n+k];
        f[0]=1;
        for(int i=1;i<n+k;i++){
            f[i]=(i*f[i-1])%mod;
        }
        inf[n+k-1]=binpow(f[n+k-1],mod-2);
        for(int i=n+k-2;i>=0;i--){
            inf[i]=(inf[i+1]*(i+1))%mod;
        }
        int ans=0;

        for(int i=0;i<=n;i++){
            int x=n+k-1-i*m;
            if(x<n-1)break;

            // int temp=(((((f[n]*(inf[i]*inf[n-i])%mod)%mod)*((f[x]*inf[n-1])%mod))%mod)*inf[x-(n-1)])%mod;
            int p=(f[n]*((inf[n-i]*inf[i])%mod))%mod;
            int q=(f[x]*((inf[x-(n-1)]*inf[n-1])%mod))%mod;
            int temp=(p*q)%mod;
            // cout<<temp<<"\n";
            if(i%2){
                ans=(ans-temp)%mod;
                if(ans<0)ans+=mod;
            }else{
                ans=(ans+temp)%mod;
            }
        }
        cout<<ans;
        }

        signed main(){
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            solve();
            return 0;
        }