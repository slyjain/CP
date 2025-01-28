#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>a;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        // if(mp[x]==0){
            a.push_back(x);
        // }
        mp[x]++;
        // cin>>a[i];
    }
    int sum=0;
    for(auto x:a){
        // cout<<x<<" "<<lower_bound(a.begin(),a.end(),x/2)-a.begin()<<"\n";
        sum+=((upper_bound(a.begin(),a.end(),x/2)-a.begin()));
    }
    cout<<sum;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}