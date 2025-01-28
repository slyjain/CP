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
void solve(){
    int n,q;
    cin>>n>>q;
    while(q--){
        int a,d,l,r;
        cin>>a>>d>>l>>r;
        ar[l]=add(ar[l],add(a,-mul(l,d)));
        ar[r+1]=add(ar[r+1],-add(a,-mul(d,l)));
        b[l]=add(b[l],d);
        b[r+1]=add(b[r+1],-d);
        // cout<<ar[l]<<" "<<b[l]<<"\n";

    }
    for(int i=1;i<=n;i++){
        ar[i]=add(ar[i],ar[i-1]);
        b[i]=add(b[i],b[i-1]);
        // cout<<b[i]<<" ";
        
    }
    cout<<"\n";
    for(int i=1;i<=n;i++){
        b[i]=mul(i,b[i]);
        // cout<<b[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        int x=add(ar[i],b[i]);
        cout<<x<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}