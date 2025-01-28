#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     string s1,s2;
     cin>>s1>>s2;
     int i=0,j=0;
     int n=s1.size(),m=s2.size();
     while(i<n&&j<m){
        cout<<s1[i]<<s2[j];
        i++;j++;
     }
     while(i<n){
        cout<<s1[i];
        i++;
     }while(j<m){
        cout<<s2[j];
        j++;
     }
     cout<<"\n";
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