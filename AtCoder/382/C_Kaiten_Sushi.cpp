#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int>a;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back({x,i+1});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        int ans=lower_bound(arr.begin(),arr.end(),make_pair(x,-(int)1e9))->second;
        cout<<ans+1<<"\n";
        //  cout<<-arr.begin()+1<<" ";
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}