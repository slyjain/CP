#include<bits/stdc++.h>
using namespace std;
#define int long long

void fn(vector<int> arr,int k){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for(int m=0;m<n;m++){
        int sum=0;
        int cnt=k;
        for(int i=m;i>=0;i--){
            if(cnt){
                sum+=arr[i];
                cnt--;
            }else{
                cnt=k;
            }
        }
        cout<<sum<<" ";
    }
}

void solve(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        fn(arr,k);
        cout<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}