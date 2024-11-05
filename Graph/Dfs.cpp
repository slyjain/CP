#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> >g;
vector<int>vis;
vector<int>temp;
void dfs(int node){
  temp.push_back(node);
  vis[node]=1;//shared visited array
  for(auto v:g[node]){
    if(!vis[v]){
      dfs(v);
    }
  }
}
int main(){
  cin>>n>>m;
  g.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    //undirected g[b].push_back(a)
    g[b].push_back(a);
  }
  //check which nodes
  //the source touches
  vis.assign(n+1,0);
  cout<<"--------------\n";
  dfs(1);
  for(int i=1;i<=n;i++){
    cout<<i<<" "<<vis[i]<<"\n";
  }
  cout<<"\n";
  for(auto v:temp){
    cout<<v<<" ";
  }
}
