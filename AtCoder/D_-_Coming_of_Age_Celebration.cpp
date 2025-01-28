#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    
    vector<int>a(n,0),pre(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i){
            pre[i]+=pre[i-1];
        }
        int val=a[i]+pre[i];
        
        int loss=n-i-1;
        int overflow=val-loss;
        pre[i+1]+=1;
        cout<<a[i]<<" "<<pre[i]<<" "<<val<<" "<<loss<<" "<<overflow<<"\n";
        if(overflow>=0){
            // cout<<a[i]<<" "<<overflow<<"\n";
            continue;
        }
        pre[i+1+val]=(-1);
        // cout<<a[i]<<" "<<0<<"\n";
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}