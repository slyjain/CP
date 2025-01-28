#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     int n;
     cin>>n;
     int x=0;
     cin>>x;
     int ans=0;
     int sign=1;
     for(int i=1;i<n;i++){
        int k;
        cin>>k;
        if(x<k&&sign!=(1)){
            cout<<x<<" "<<k<<"\n";
            ans++;
            sign=1;
        }else if(x>k&&sign!=-1){
            cout<<x<<" "<<k<<"\n";
            ans++;
            sign=-1;
        }
        
        x=k;
     }
     if(sign==-1){
        ans++;
     }
     cout<<ans<<"\n";
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