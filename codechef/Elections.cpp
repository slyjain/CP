#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>a,b,c;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        b.push_back(t);
    }
    for(int i=0;i<n;i++){
        if(a[i]-b[i]<=0){
            c.push_back(a[i]-b[i]);
        }
    }
    int req=(n/2)+1;
    int won=n-c.size();
    sort(c.rbegin(),c.rend());
    // for(auto i:c){
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    int i=0;
    while(x>0&&i!=c.size()){
        // cout<<x<<" "<<c[i]<<"\n";
        if(x>=(-c[i]+1)){
            won++;
        }
        x-=(-c[i]+1);
        i++;
    }
    if(won>=req){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    
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