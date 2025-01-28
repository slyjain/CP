#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
     int n;
     cin>>n;
     vector<int>a;
     bool leading=true;
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0&&leading){
            continue;
        }else{
            leading=false;
            a.push_back(x);
        }
     }
     n=a.size();
     for(int i=n-1;i>=0;i--){
        if(a[i]==0){
            a.pop_back();
        }else{
            // cout<<"here";
            break;
        }
     }
    //  for(auto x:a){
    //     cout<<x<<" ";
    //  }
    //  cout<<"\n";
     map<int,int>mp;
     n=a.size();
     int rest=0;
     for(int i=0;i<n;i++){
        if(a[i]!=0){
            rest++;
        }else{
            mp[0]++;
        }
     }
     int ans=0;
     if(mp[0]>0&&rest>0){
        ans=2;
     }else if(mp[0]==n){
        ans=0;
     }else if(mp[0]==0){
        ans=1;
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