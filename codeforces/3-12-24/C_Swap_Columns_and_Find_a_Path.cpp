#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>ar,br,arr;

void solve(){
   
    cin>>n;
    ar.resize(n);
    br.resize(n);
    arr.resize(n);
    // int ans=0;
    int mx=-1e18;
    int index=-1;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ar[i]=x;
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        br[i]=x;
    }
    for(int i=0;i<n;i++){
        arr[i]=max(ar[i],br[i]);
        if(mx<ar[i]+br[i]){
            mx=ar[i]+br[i];
            index=i;
        }
    }
    // cout<<"\n";
    for(int i=0;i<n;i++){
        if(index==i){
            sum+=mx;
        }
        else{
            sum+=arr[i];
        }
    }
    cout<<sum<<"\n";
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}