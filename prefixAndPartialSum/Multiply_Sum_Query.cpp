#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,q;
int arr[1000010],p1[1000010],p2[1000010];
int add(int x,int y){
    return (x+y+mod)%mod;
}
int mul(int x,int y){
    return (x*y)%mod;
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        // cout<<x<<" ";
        x%=mod;
        arr[i]=x;
        p1[i]=x;
        p2[i]=(x*i)%mod;
        
            p1[i]+=p1[i-1];
            p1[i]%=mod;
            p2[i]+=p2[i-1];
            p2[i]%=mod;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        
        cout<<add(add(p2[r],-p2[l-1]),mul(1-l,add(p1[r],-p1[l-1])))<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}