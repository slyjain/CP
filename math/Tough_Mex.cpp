#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int add(int a ,int b){
    return (a+b+mod)%mod;
}
int mul(int a ,int b){
    return (a*b)%mod;
}
int binpow(int a,int p){
    int temp=a;
    int ans=1;
    while(p){
        // cout<<p<<" "<<temp<<"\n";
        if(p%2==1){
            ans=(mul(ans,temp))%mod;
        }
        p>>=1;
        temp=mul(temp,temp)%mod;
    }
    return ans%mod;
}
void solve(){
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]>n){
        a[i]=n;
    }
}
if(n==0){cout<<1<<"\n";return;}
map<int,int>mp;
for(int i=0;i<n;i++){
    mp[a[i]]++;
}
int pre=1;
int ans=0;
int back=0;
for(int i=1;i<=n+1;i++){
    int curr=mp[i];
    int r=n-curr-back;
    ans=add(ans,mul(i,mul(pre,binpow(2,r))));
    // cout<<i<<" "<<pre<<" "<<r<<" "<<binpow(2,r)<<"\n";
    pre=mul(pre,add(binpow(2,curr),-1));
    back=add(back,curr);
}
cout<<ans<<"\n";

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