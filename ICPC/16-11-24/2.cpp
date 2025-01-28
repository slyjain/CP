#include<bits/stdc++.h>
using namespace std;
#define int long long
int mx=4*1000000;
int ar[4*1000100];
void pre(){
    ar[4]=1;
    for(int i=4;i<mx;i=i<<1){
        for(int j=2*i;j<=mx;j+=i){
            ar[j]++;
        }
    }
}
void solve(){
    int x;
    cin>>x;
    cout<<ar[x]<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    pre();
    while(t--)
    solve();
    return 0;
}