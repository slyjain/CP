#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int>vis;
void dfs(int node,int componentNumber){
  vis[node]=componentNumber;
  for(auto v:g[node]){
    if(!vis[v]){
      dfs(v,componentNumber);
    }
  }

}
int main(){
  int n,m ;
  cin>>n>>m;
  g.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
       
  }
  vis.assign(n+1,0);
  int componentCount=0;
  for(int i=1;i<=n;i++){
    if(vis[i]==0){
      componentCount++;
      dfs(i,componentCount);
    }
  }
  cout<<"Count of new components : "<<componentCount<<endl;
  for(int i=1;i<=n;i++){
    cout<<i<<": "<<vis[i]<<"\n";
  }
  return 0;
}
