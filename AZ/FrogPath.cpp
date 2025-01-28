#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     int n;
     cin>>n;
     int st,en;
     cin>>st>>en;
     int u,d;
     cin>>u>>d;
     int diff=en-st;
     n=n-st;
    //  int inverse=st;
     if(diff<0){
        swap(u,d);
        n=en;
     }
     bool f=true;
     if((diff)%__gcd(u,d)!=0){
        f=false;
        return;
     }
     
     int uj=(diff+u-1)/u;
     int ans=0;
     if(u*uj>n){
        f=false;
     }
     if(u*uj>diff){
        ans=uj+((u*uj-diff)+d-1)/d;
     }else{
        ans=uj;
     }
     if(f){
        cout<<ans;
     }else{
        cout<<"-1";
     }
     

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    return 0;
}