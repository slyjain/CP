#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
int n;
cin>>n;

    int i=1;
    int j=3*n;
    cout<<(n+1)/2<<"\n";
    while(i<j){
        cout<<i<<" "<<j<<"\n";
        i+=3;
        j-=3;
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