#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int ar[1000010],b[1000010],c[1000010];
int add(int x,int y){
    return (x+y+mod)%mod;
}
int mul(int x,int y){
    return (x*y)%mod;
}
int binpow(int x,int p){
    int ans=1;
    while(p>0){
        if(p%2==1)ans=mul(ans,x);
        p/=2;
        x=mul(x,x);
    }
    return ans;
}
int inv(int x){
    return binpow(x,mod-2);
}
void solve(){
    int n,q,k;
    cin>>n>>q>>k;
    while(q--){
        int a,l,r;
        cin>>a>>l>>r;
        ar[l]=add(a,ar[l]);
        ar[r+1]=add(ar[r+1],-mul(a,binpow(k,r-l+1)));
       
    }
    for(int i=1;i<=n;i++){
        ar[i]=add(ar[i],mul(ar[i-1],k));
        
         cout<<ar[i]<<" ";
    }
    
    // for(int i=1;i<=n;i++){
    //     int x=mul(ar[i],binpow(k,b[i]));
    //     x=mul(x,inv(c[i]));
    //     cout<<x<<" ";
    // }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}