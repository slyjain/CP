#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
int n;
cin>>n;
int t,v;
int curr=0;
cin>>t>>v;
curr=v;
for(int i=1;i<n;i++){int temp;
    cin>>temp>>v;
    curr=max((int)0,curr-(temp-t))+v;
    t=temp;
}
cout<<curr;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}