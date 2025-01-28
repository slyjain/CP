#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
        int n;
        cin>>n;
        for(int j=n-1;j>=0;j--){
            for(int i=j;i>=0;i--){
            cout<<"*";
        }
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