#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
vector<int>a;
bool rec(int l,int r){
    if(r<l)return true;
    return a[l]==a[r]&&rec(l+1,r-1);
}
void solve(){
     int n;
     cin>>n;
     a.resize(n);
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
     cout<<(rec(0,n-1)?"YES\n":"NO\n");
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