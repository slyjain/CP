#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
void solve(){
    cin>>n>>k;
    int p=0;
    int r=1;
    for(int i=0;i<k;i++){
        char x;
        cin>>x;
        if(x=='U'){
                p=(p+r+n)%n;
        }
        else if(x=='S'){
            p=(p+2*r+n)%n;
        }
        else if(x=='R'){
            r*=-1;
            p=(p+r+n)%n;
        }
    }
    cout<<p+1<<"\n";
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