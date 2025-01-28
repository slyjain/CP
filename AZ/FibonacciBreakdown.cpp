#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
vector<int>fib;
void fibo(){
    fib.push_back(1);
    fib.push_back(1);
    int temp=fib[0]+fib[1];
    int c=2;
    while(temp<=1e9){
        fib.push_back(temp);
        temp=fib[c]+fib[c-1];
        c++;
    }
}
void solve(){
     int k;
     cin>>k;
     int ans=0;
     while(k!=0){
         ans++;
        auto it=lower_bound(fib.begin(),fib.end(),k);
        if(*it==k){
           k-=(*it);
        }else{
            it--;
            k-=(*it);
        }
     }
     cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fibo();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}