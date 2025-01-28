#include<bits/stdc++.h>
using namespace std;
#define int long long
// int ar[10010];


void solve(){
    int n;
    cin>>n;
    vector<int>ar(n);
    int k;
    cin>>k;
    // vector<int>ar(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int psDev=0,nDev=0;
    int sum=0;
    for(int i=0;i<n;i++){
        
            sum+=(ar[i]/k);
            
        if(ar[i]>0&&ar[i]%k!=0){
            psDev++;
        }
        else if(ar[i]<0&&ar[i]%k!=0){
                nDev++;
            }
    }
    if(sum==0){
        cout<<"YES";
    }
    else if(sum>=0&&sum-nDev<=0){
        cout<<"YES";
    }
    else if(sum<=0&&psDev+sum>=0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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