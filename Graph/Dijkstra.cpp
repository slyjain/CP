#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
using ii=pair<int,int>;
#define INF 1e9
class priority{
    public:
    bool operator()(ii a,ii b){
        return a.S>b.S;
    }
};
vector<vector<ii>>g;
vector<int>dis;
vector<int>vis;
int n,m;
void dijkstra(int sc){
    
    dis[sc]=0;
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
            if(dis[v.F]>dis[currNode]+v.S){
                dis[v.F]=dis[currNode]+v.S;
                pq.push({v.F,dis[v.F]});
            }
        }
    }

}
signed main() {
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    dis.assign(n+1,INF);
    for(int i=0;i<m;i++){
        int x, y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
}
    dijkstra(1);

    return 0;
}