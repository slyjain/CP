#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve(){
    cin>>n>>m;
    int ans=n*n;
    int l[n+2];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a==b){
            ans--;
        }
        else if(b>a){
            l[a]++;
            l[b+1]--;
        }

    }
    for(int i=1;i<=n;i++){
        l[i]+=l[i-1];
    }
    for(int i=1;i<n;i++){
        if(l[i]==0){
            cnt++
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}