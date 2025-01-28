#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j&&i==n/2&&n&1==1){
                cout<<"X";
            }else if(i==j){
                cout<<"\\";
            }else if(i==n-j-1){
                cout<<"/";
            }else{
                cout<<"*";
            }
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