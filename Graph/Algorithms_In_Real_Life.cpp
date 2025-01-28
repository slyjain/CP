#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
using ii= pair<int,int>;
const int inf=1e18;
int m,h,n,k;
class priority{
    public:
    bool operator()(pair<ii,int> a,pair<ii,int> b){
        return a.S>b.S;
    }
};
vector<vector<ii>>g;
vector<vector<int>>vis;
vector<vector<int>>pr;
void dijkstra(int sc){
    pr[sc][0]=0;
    priority_queue<pair<ii,int>,vector<pair<ii,int>>,priority>pq;
    pq.push({{sc,0},0});
    
    while(pq.empty()==false){
        auto curr=pq.top();
        pq.pop();
        int currNode=curr.F.F;
        int jump=curr.F.S;
        if(jump==k)continue;
        if(vis[currNode][jump]==1){
            continue;
        }
        vis[currNode][jump]=1;
        for(auto v:g[currNode]){
            if(pr[v.F][jump+1]>pr[currNode][jump]+v.S){
                pr[v.F][jump+1]=pr[currNode][jump]+v.S;
                pq.push({{v.F,jump+1},pr[v.F][jump+1]});
            }
        }
    }
}
void solve(){
    
    cin>>m>>h>>n;
    g.resize(m+1);
    for(int i=0;i<n;i++){
        int x,y,p;
        cin>>x>>y>>p;
        g[x].push_back({y,p});
    }
    cin>>k;
    pr.resize(m+1,vector<int>(k+1,inf));
    vis.resize(m+1,vector<int>(k+1,0));
    dijkstra(1);
    int ans=inf;
    for(int i=0;i<=k;i++){
        ans=min(ans,pr[h][i]);
    }
    cout<<(ans==inf?-1:ans);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}