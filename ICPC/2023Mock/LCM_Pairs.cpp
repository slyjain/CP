#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100100];
void solve(){
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a[x]++;

    }
    int ans=0;
    for(int i=1;i<=100000;i++){
        ans+=a[i]*(a[i]-1)/2;
        for(int j=2*i;j<=100000;j+=i){
            ans+=(a[j]*a[i]);
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