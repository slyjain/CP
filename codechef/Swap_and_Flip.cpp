#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int c1=0,c2=0;
    for(auto x:a){
        if(x=='1'){
            c1++;
        }
    }
    for(auto x:b){
        if(x=='1'){
            c2++;
        }
    }
    if(c1%2==c2%2){
        cout<<"YES";
    }else{
        cout<<"NO";
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