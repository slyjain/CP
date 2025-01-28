#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]].push_back(i);
    }
    // int ans=1;
    // int mx=1;
    // for(int j=0;j<n;j++){
    //     for(int k=0;k<j;k++){
    //         int pre=arr[k];
    //     for(int i=k+j;i<n;i=i+j){
    //         if(arr[i]==pre){
    //             ans++;
    //             mx=max(mx,ans);
    //         }else{
    //             pre=arr[i];
    //             ans=1;
    //         }
    //     }
    //     }
        
    // }
    int mx=0;
    for(auto x:mp){
        vector<int>temp=x.second;
        int sz=temp.size();
        for(int k=1;k<sz;k++){
            int pre=arr[k];
            int ans=0;
            for(int j=k;j<sz;j=j+k){
                if(pre==arr[j]){
                    ans++;
                    mx=max(mx,ans);
                }else{
                    pre=arr[j];
                    ans=1;
                }
            }
        }
    }
    cout<<mx<<"\n";
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}