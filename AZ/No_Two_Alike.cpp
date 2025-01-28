#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1,0);
    vector<int>dis(n+1,0);
    map<int,int>lastseen;
    for(int i=1;i<=n;i++){
        int x;
        cin>>arr[i];
        // cout<<arr[i]<<" ";
        if(lastseen[arr[i]]==0){
            dis[i]++;
        }
        lastseen[arr[i]]=i;
    }
    for(int i=1;i<=n;i++){
        dis[i]+=dis[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int first=i;
        int last=lastseen[arr[i]];
        for(int j=first;j<=last;j++){
            last=max(last,lastseen[arr[j]]);
        }
        // cout<<first<<" "<<last<<"\n";
        if(first!=last){
            ans+=dis[last]-dis[first-1];
        }
        
        i=last;
    }
    cout<<ans;
    cout<<"\n";
     
    
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