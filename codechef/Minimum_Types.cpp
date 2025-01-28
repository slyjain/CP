#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int i;bool hogaya=false;
    for(i=n-1;i>=0;i--){
        x=x-a[i]*b[i];
        if(x<=0){
            hogaya=true;
            break;
        }
    }
    if(hogaya){
        cout<<n-i;
    }else{
        cout<<-1;
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