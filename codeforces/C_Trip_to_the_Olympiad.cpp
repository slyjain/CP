#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     int l,r;
     cin>>l>>r;
     int firstDifferentBit;
     for(int i=31;i>=0;i--) {
        if(((l>>i)&1)!=((r>>i)&1)){
            firstDifferentBit=i;
            break;
        }
     }
    //  cout<<firstDifferentBit<<"\n";
     int a=0,b=0,c=0;
     for(int i=31;i>=firstDifferentBit;i--){
        a|=(r&(1<<i));
        b|=(r&(1<<i));
        
     }
     b--;
     c=r;
     while(c==a||c==b&&c>=l){
        c--;
     }
     cout<<a<<" "<<b<<" "<<c<<"\n";
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