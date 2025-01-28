#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    map<int,int>freq;
    int ans=1;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr[i]=x;
        freq[x]++;
        if(freq[x]%2==0){
            ans=0;
            
        }
    }
    if(ans==0){
        if(l==0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }else{

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans*=(arr[i]^arr[j]);
            }
        }
        if(ans>=l&&ans<=r){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        
    
    }
    cout<<"\n";
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