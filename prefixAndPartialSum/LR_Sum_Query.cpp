#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
const int mod=1e9+7;
int arr[1000100],p[1000100];
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        p[i]=arr[i];
        if(i){
            p[i]+=p[i-1];
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<((p[r]-p[l-1]+mod)%mod)<<"\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}