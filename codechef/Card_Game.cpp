#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,x;
    cin>>n>>x;
    if(n%2){
        if(x%2){
            cout<<(n+1)/2-1<<"\n";
        }
        else{
            cout<<(n/2)-1<<"\n";
        }
    }
    else{
        cout<<(n/2)-1<<"\n";
    }
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