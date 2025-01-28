#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>g,ga;
vector<int>topo,outdegree;
int t;
void kahn(){
    t=n;
    map<int,int>mp;
    priority_queue<int>pq;
    for(int i=1;i<=n;i++){
        if(outdegree[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int tp=pq.top();
        pq.pop();
        mp[tp]=t;
        t--;
        topo.push_back(tp);
        for(auto x:ga[tp]){
            outdegree[x]--;
            if(outdegree[x]==0){
                pq.push(x);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<mp[i]<<" ";
    }

    
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    ga.resize(n+1);
    outdegree.resize(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        ga[y].push_back(x);
        outdegree[x]++;
    }
    kahn();
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}