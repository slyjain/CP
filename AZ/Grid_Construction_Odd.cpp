#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     int n;
     cin>>n;
     vector<int>a(n,0);
     a[n/2]=n;
     int k=(n+1)/2;
     for(int i=0;i<n/2;i++){
        a[i]=i+1;
        a[n-i-1]=k++;
     }
    //  for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    //  }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[(i+j)%n]<<" ";
        }
        cout<<"\n";
     }
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