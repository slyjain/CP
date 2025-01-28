#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,q,k;
int arr[1000010],p1[1000010],p2[1000010];
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
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        // cout<<x<<" ";
        x%=mod;
        arr[i]=x;

        p1[i]=mul(x,binpow(k,i));
        // cout<<binpow(k,i)<<" ";
        p1[i]=add(p1[i],p1[i-1]);
        
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        
        cout<<mul(add(p1[r],-p1[l-1]),inv(binpow(k,l)))<<"\n";
    }
    // cout<<binpow(4,2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}