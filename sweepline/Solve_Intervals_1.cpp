#include<bits/stdc++.h>
using namespace std;
#define int long long
using event=pair<int,int>;
#define S second 
#define F first
void solve(){
    int n,L;
    cin>>n>>L;
    vector<event>events;
    for(int i=0;i<n;i++){
    int l,r;   
    cin>>l>>r;
    events.push_back({l,r});
    }
    sort(events.begin(),events.end());
    set<set<pair<int,int>>>mt;
    for(auto e:events){
        if(mt.empty()){
            set<pair<int,int>>s;
            s.insert(e);
            mt.insert(s);
        }else{
            for(auto v:mt){
                for(auto x:v){
                    if(x.second>=e.first){
                        set<pair<int,int>>temp=v;
                        temp.insert(e);
                        mt.insert(temp);
                    }
                }
            
            }
            for(auto v:mt){
                
            }
        }
    }
    int mn=INT_MAX;
    for(auto t:mt){
        if(t.begin()->first==0&&t.rbegin()->second==L){
            mn=min(mn,(int)t.size());
        }
    }
    cout<<mn<<"\n";

}
// void solve(){
//     int n,L;
//     cin>>n>>L;
    
// }
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}