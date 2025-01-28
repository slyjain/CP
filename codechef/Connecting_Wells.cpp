#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 1e18;
using ii=pair<int,int>;
vector<vector<ii>>g;
class priority{
    public:
    bool operator()(ii a,ii b){
        return a.S>b.S;
    }
};

int distances(ii p1,ii p2){
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}
vector<int>dist;
vector<int>vis;
void dijkstra(int sc){
    dist[sc]=0;
    priority_queue<ii,vector<ii>,priority>pq;
    pq.push({sc,0});
     while(pq.empty()==false){
        auto cur=pq.top();
        pq.pop();
        int currNode=cur.F;
        int wt=cur.S;
        if(vis[currNode]==1){
            continue;
        }
        vis[currNode]=1;
        for(auto v:g[currNode]){
            if(dist[v.F]>dist[currNode]+v.S){
                dist[v.F]=dist[currNode]+v.S;
                pq.push({v.F,dist[v.F]});
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>cnates;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        cnates.push_back({x,y});
    }
    g.resize(n+1);
    dist.resize(n+1,1e18);
    vis.resize(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ii x=cnates[i],y=cnates[j];
            g[i].push_back({j,distances(x,y)});  
            g[j].push_back({i,distances(x,y)});          
        }
    }
    
    dijkstra(1);

    
    
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