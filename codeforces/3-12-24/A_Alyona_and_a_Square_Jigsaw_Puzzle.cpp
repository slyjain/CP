#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
int n;
cin>>n;
int sum=0;
int ct=1;
int ans=0;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    sum+=x;
    if(sum==ct*ct){
        ans++;
        ct+=2;
    }
     if(sum>ct*ct){
        while(sum>ct*ct){
            ct+=2;
        }  
        if(sum==ct*ct){
            ans++;
            ct+=2;
        } 
    }
     
}
cout<<ans<<"\n";
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