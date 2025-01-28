#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string a,b;
    cin>>a>>b;
    cout<<a.size()<<" "<<b.size()<<"\n";
    cout<<a<<b;
    char c1=a[0],c2=b[0];
    cout<<c2<<" ";
    for(int i=1;i<a.size();i++){
        cout<<a[i];
    }
    cout<<c1;
    for(int i=1;i<b.size();i++){
        cout<<b[i];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}