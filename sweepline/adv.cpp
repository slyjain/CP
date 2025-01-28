#include<bits/stdc++.h>
using namespace std;
#define int long long
using event=pair<pair<int,int>,pair<int,int>>;
#define S second
#define F first
void solve(){
    int n;
    cin>>n;
    vector<event>events;
    for(int i=0;i<n;i++){
        int l,r,x;
        cin>>l>>r>>x;
        events.push_back({
            {l,0},
            {x,i}
        });
        events.push_back({
            {r,2},
            {x,i}
        });
    }
    int q;
    cin>>q;
    int ans[q];
    for(int i=0;i<q;i++){
        int y,k;
        cin>>y>>k;
        events.push_back({
            {y,1},
            {k,i}
        });
    }
    multiset<int>activeParts;
    sort(events.begin(),events.end());
    for(event v:events){
        if(v.F.S==0){
            activeParts.insert(v.S.F);
        }
        else if(v.F.S==2){
            auto it=activeParts.find(v.S.F);
            activeParts.erase(it);
        }
        else{
            int totalK=v.S.F;
            int sum=0;
            for(auto it=activeParts.rbegin();it!=activeParts.rend()&&totalK>0;it++,totalK--){
                sum+=(*it);
            }
            ans[v.S.S]=sum;
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}