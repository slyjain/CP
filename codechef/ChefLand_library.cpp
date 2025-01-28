#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     int n;
     cin>>n;
     map<int,int>mp;

     for(int i=1;i<=n;i++){
        int x;cin>>x;
        mp[x]=i;
     }
     int sum=0;
     for(auto x:mp){
        sum+=x.second;
     }
     cout<<sum<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}