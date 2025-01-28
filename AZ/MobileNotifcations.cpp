#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     map<int,vector<int>>mp;
     vector<pair<int,bool>>qu;
     int n,q;
     cin>>n>>q;
     int idx=0;
    while(q--){
        int x;
        cin>>x;
        
        if(x==1){
            int app;
            cin>>app;
            
            mp[app].push_back(idx);
            qu.push_back({app,false});
            idx++;
            cout<<idx<<"\n";
        }else if(x==2){
            int app;
            cin>>app;
            for(auto i:mp[app]){
                if(qu[i].second==false){
                    qu[i].second=true;
                    idx--;
                }
            }
            cout<<idx<<"\n";
        }else{
            int y;cin>>y;
            for(int i=0;i<y;i++){
                if(qu[i].second==false){
                    qu[i].second=true;
                    idx--;
                }
            }
            cout<<idx<<"\n";
        }
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