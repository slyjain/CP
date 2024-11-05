#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,q;
int arr[1000100];
int gn[1000100];
void solve(){
    cin>>n>>k>>q;
    
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        arr[l]+=1;
        arr[r+1]-=1;
    }
    // int gn=0;
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
        if(arr[i]>=k){
            gn[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        gn[i]+=gn[i-1];
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<gn[r]-gn[l-1]<<"\n";
    }
    // cout<<gn;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}