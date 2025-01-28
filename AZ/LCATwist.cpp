#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define print(a) for(auto i:a){ cout<<i<<' ' ;}cout<<endl; 
#define read(x) int x ; cin>>x;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mt make_tuple
#define eb emplace_back

typedef vector<int> vin;
typedef vector<string> vst;
typedef vector<char> vch;
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
vector<vector<int>>g;
vector<vin> parent;
vin depth;
int lca(int u,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    
    for(int i=19;i>=0;i--){
        if((depth[u]-depth[v])&(1<<i)){
            u=parent[u][i];
            // v=parent[v][i];
        }
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(parent[u][i]!=parent[v][i]){
            u=parent[u][i];
            v=parent[v][i];
        }
    }
    return parent[u][0];
}
void dfs(int node,int par,int dep){
    parent[node][0]=par;
    depth[node]=dep;
    for(int i=1;i<20;i++){
        if(parent[node][i-1]!=0){
            parent[node][i]=parent[parent[node][i-1]][i-1];
        }
    }
    for(int ne:g[node]){
        if(ne!=par){
            dfs(ne,node,dep+1);
        }
    }

}
void solve(){
     int n;
     cin>>n;
     g.clear(),parent.clear(),depth.clear();
     g.resize(n+1,vector<int>());
     parent.assign(n+1,vector<int>(21,0));
     depth.assign(n+1,0);
     for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
     }
     dfs(1,0,0);
     int q;
     cin>>q;
     while(q--){
        int u,v,w;
     cin>>u>>v>>w;
     int x=lca(u,v);
     int y=lca(w,u);
     int z=lca(w,v);
     if(x==y||x==z){
        if(x==y){
            cout<<z<<"\n";
        }else{
            cout<<y<<"\n";
        }
     }else{
        cout<<x<<"\n";
     }
     }
     
     
    //  for(int i=1;i<=n;i++){
    //     cout<<parent[i]<<" ";
    //  }
    //  cout<<"\n";
    //  for(int i=1;i<=n;i++){
    //     cout<<depth[i]<<" ";
    //  }

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